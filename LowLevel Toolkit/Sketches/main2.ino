#include "declarations.h"
#include "Gear_Server.h"

void StartMPU()
{
  Serial.println("\nStart MPU6050\n");
  g_mpu.initI2C();
  g_mpu.initMPU();
  g_mpu.checkMPU(MPU_ADDR);
}

void SetJSON()
{
    for(uint8_t i = 0 ; i < j_buttons.size(); i++)
    {
        //TODO: Pegar todos os botoes aqui!!!!
        j_buttons[i]["state"] = button_0.GetState();
    }

    for(uint8_t i = 0; i < j_potentiometers.size(); i++)
    {
        j_potentiometers[i]["value"] = pot.GetValue();
    }

    for(uint8_t i = 0; i < j_mpus.size(); i++)
    {    
        int16_t* acell = g_mpu.GetAccelerometer();

        j_mpus[i]["accel"]["x"] = acell[0];
        j_mpus[i]["accel"]["y"] = acell[1];
        j_mpus[i]["accel"]["z"] = acell[2];

        int16_t* gyro = g_mpu.GetGyro();

        j_mpus[i]["gyro"]["x"] = gyro[0];
        j_mpus[i]["gyro"]["y"] = gyro[1];
        j_mpus[i]["gyro"]["z"] = gyro[2];

        double* angle = g_mpu.GetAngle();

        j_mpus[i]["angle"]["x"] = angle[0];
        j_mpus[i]["angle"]["y"] = angle[1];
        j_mpus[i]["angle"]["z"] = angle[2];
    }
    
    parserJSON = "";
    jsonRoot.printTo(parserJSON);
}

void setup() 
{
    Serial.begin(115200);

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    StartMPU();

    button_0.init();

    rgbLed.init();
    rgbLed.SetColor(1023,256,0);

    pot.init();

    wifi.InitWiFi();

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
        webSocket.sendTXT(0, header_parserJSON);
    }
    else
    {
        SetJSON();
        webSocket.sendTXT(0, parserJSON);
    }

    WebServerLoop();

    //24 fps
    delay(40);
}

void webSocketEvent(uint8_t num, int type, uint8_t* payload, size_t length) 
{
    switch(type) 
    {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            rgbLed.SetColor(1023,0,0);
            break;
        
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Hi, software :)");
            
            //Reset the boolean to control the header
            headerReceivedByClient = false;

            //SET HEADER TO send
            header_parserJSON = "";
            header_jsonRoot.printTo(header_parserJSON);
        }
            break;
        case WStype_TEXT:
            //Serial.printf("[%u] get Text: %s\n", num, payload);

            if(payload[0] == '_')
            {
                SetJSON();
                // webSocket.sendTXT(num, parserJSON);
                webSocket.sendTXT(num,"hi");
            }
            else if(payload[0] == '@') //Header Handshake
            {
                headerReceivedByClient = true;
            }
            else if(payload[0] == '#') {
                // we get RGB data

                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

                //analogWrite(redPin,    ((rgb >> 16) & 0xFF));
                //analogWrite(greenPin,  ((rgb >> 8) & 0xFF));
                //analogWrite(bluePin,   ((rgb >> 0) & 0xFF));
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
                //Serial.println(json);
            }

            break;
        
        case WStype_BIN:
            Serial.printf("[%u] get binary length: %u\r\n", num, length);
            hexdump(payload, length);
      
            // echo data back to browser
            //webSocket.sendBIN(num, payload, length);
            break;
          default:
            Serial.printf("Invalid WStype [%d]\r\n", type);
            break;
    }
}