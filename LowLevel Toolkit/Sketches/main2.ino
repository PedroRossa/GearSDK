#include "declarations.h"
#include "Gear_Server.h"

void CheckReceivedMessages(uint8_t* payload)
{
    canReceiveMessage = false;

    StaticJsonBuffer<350> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(payload);

    String jsonType = Gear_Object::getObjectTypeByJson(root);

    for(int i = 0; i < gearManager->getObjectsSize(); i++)
    {
        gearManager->getObject(i)->receivedMessage(root, jsonType);
    }

    jsonBuffer.clear();
    root.~JsonObject();
    canReceiveMessage = true;
}

void setup() 
{
    Serial.begin(115200);

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }
    
    gearManager->add(g_mpu);
    gearManager->add(button_0);
    gearManager->add(pot);
    gearManager->add(rgbLed);

    //Init the objects
    gearManager->init();

    wifi.InitWiFi();

    rgbLed->SetColor(1023,1023,0);

    ConfigWebServer();

    rgbLed->SetColor(0,1023,0);
    rgbLed->SetMode(LedMode::BLINKING, 800,200);
}

void loop() 
{
    g_mpu->readRawMPU();
    g_mpu->CalculateAngles();

    rgbLed->update();

    if(!headerReceivedByClient)
    {
        webSocket.sendTXT(0, jsonHeader);
    }
    else
    { 
        String data = gearManager->createJsonData();
        if(data != "")
        {
            webSocket.sendTXT(0, data);
        }
    }
    WebServerLoop();
    delay(40);
}

void webSocketEvent(uint8_t num, int type, uint8_t* payload, size_t length) 
{
    switch(type) 
    {
        case WStype_DISCONNECTED:{
            Serial.printf("[%u] Disconnected!\n", num);
            rgbLed->SetColor(1023,0,0);
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
            jsonHeader = gearManager->createJsonHeader();

            break;
        }
        case WStype_TEXT:{
            Serial.printf("[%u] get Text: %s\n", num, payload);
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
                if(canReceiveMessage)
                {
                    CheckReceivedMessages(payload);
                }
            }
            break;
        }
        case WStype_BIN:{
            //Serial.printf("[%u] get binary length: %u\r\n", num, length);
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