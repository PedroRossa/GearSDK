#include "declarations.h"
#include "Gear_Server.h"

void InitOjbects()
{
    g_mpu.init();
    button_0.init();
    
    rgbLed.init();
    rgbLed.SetColor(1023,256,0);
    
    pot.init();
    
    wifi.InitWiFi();
}

String MountJSONHeader()
{
    jsonHeader = "{\"header\":";
    jsonHeader = jsonHeader + "{\"buttons\":[";
    jsonHeader = jsonHeader + button_0.GetHeader() + "],";

    jsonHeader = jsonHeader + "\"potentiometers\":[";
    jsonHeader = jsonHeader + pot.GetHeader() + "],";

    jsonHeader = jsonHeader + "\"rgb_leds\":[";
    jsonHeader = jsonHeader + rgbLed.GetHeader() + "],";

    jsonHeader = jsonHeader + "\"mpus\":[";
    jsonHeader = jsonHeader + g_mpu.GetHeader() + "]";
    
    jsonHeader = jsonHeader + "}}";
    
    return jsonHeader;
}

void SendObjects()
{
    String s = button_0.updatedData();
    if(s != "") { webSocket.sendTXT(0, s); }

    s = pot.updatedData();
    if(s != "") { webSocket.sendTXT(0, s); }

    s = rgbLed.updatedData();
    if(s != "") { webSocket.sendTXT(0, s); }

    s = g_mpu.updatedData();
    if(s != "") { webSocket.sendTXT(0, s); }
}

void setup() 
{
    Serial.begin(115200);

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    InitOjbects();

    ConfigWebServer();

    rgbLed.SetColor(0,1023,0);
    rgbLed.SetMode(LedMode::BLINKING, 800,200);
}

void loop() 
{
    g_mpu.readRawMPU();
    g_mpu.CalculateAngles();

    rgbLed.update();

    if(!headerReceivedByClient)
    {
        webSocket.sendTXT(0, jsonHeader);
    }
    else
    { 
        SendObjects();
    }

    WebServerLoop();
}

void webSocketEvent(uint8_t num, int type, uint8_t* payload, size_t length) 
{
    switch(type) 
    {
        case WStype_DISCONNECTED:{
            Serial.printf("[%u] Disconnected!\n", num);
            rgbLed.SetColor(1023,0,0);
            break;
        }
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Hi, software :)");
            
            //Reset the boolean to control the header
            headerReceivedByClient = false;

            //SET HEADER TO send
            MountJSONHeader();

            break;
        }
        case WStype_TEXT:{
            //Serial.printf("[%u] get Text: %s\n", num, payload);
            if(payload[0] == '_')
            {
                // webSocket.sendTXT(num, parserJSON);
                webSocket.sendTXT(num,"hi");
            }
            else if(payload[0] == '@') //Header Handshake
            {
                headerReceivedByClient = true;
            }
            else if(payload[0] == '{') { //JSON

                StaticJsonBuffer<200> jsonBuffer;
                JsonObject& root = jsonBuffer.parseObject(payload);

                String name = root["name"].as<String>();
                int mode = root["mode"];

                if(name.indexOf("rgb_led") >= 0)
                {
                    int v1 = root["value"]["r"];
                    int v2 = root["value"]["g"];
                    int v3 = root["value"]["b"];

                    rgbLed.SetColor(v1,v2,v3);
                    rgbLed.SetMode((LedMode)mode, 800, 200);
                }
            }
            break;
        }
        case WStype_BIN:{
            Serial.printf("[%u] get binary length: %u\r\n", num, length);
            hexdump(payload, length);
      
            // echo data back to browser
            //webSocket.sendBIN(num, payload, length);
            break;
        }
        default:{
            Serial.printf("Invalid WStype [%d]\r\n", type);
            break;
        }
    }
}