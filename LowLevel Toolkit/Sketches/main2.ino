#include "declarations.h"
#include "Gear_Server.h"

Gear_WiFiConnection wifi(SSID, PASSWORD);
Gear_MPU6050 g_mpu(MPU_ADDR);
Gear_Button button_0(D7);
Gear_RGBLed rgbLed(D1, D2, D3, LedMode::STATIC, true);

void StartMPU()
{
  Serial.println("\nStart MPU6050\n");
  g_mpu.initI2C();
  g_mpu.initMPU();
  g_mpu.checkMPU(MPU_ADDR);
}

void SetJSON()
{
    data["button_0"] = button_0.GetState();
    //jsonRoot["button_1"] = button_1_State;
    
    gyro["x"] = g_mpu.GetGyro()[0];
    gyro["y"] = g_mpu.GetGyro()[1];
    gyro["z"] = g_mpu.GetGyro()[2];
    
    accelerometer["x"] = g_mpu.GetAccelerometer()[0];
    accelerometer["y"] = g_mpu.GetAccelerometer()[1];
    accelerometer["z"] = g_mpu.GetAccelerometer()[2];

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

    wifi.InitWiFi();

    ConfigWebServer();

    rgbLed.SetColor(0,1023,0);
    rgbLed.SetMode(LedMode::BLINKING, 800,200);
}

void loop() 
{
    g_mpu.readRawMPU();

    rgbLed.update();

    if(button_0.GetState() == HIGH)
        rgbLed.SetColor(random(0,1023),random(0,1023),random(0,1023));

    SetJSON();
    webSocket.sendTXT(0, parserJSON);
    
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
            break;
        
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Hi, software :)");
        }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);

            if(payload[0] == '_')
            {
                SetJSON();
                // webSocket.sendTXT(num, parserJSON);
                webSocket.sendTXT(num,"hi");
            }
            else if(payload[0] == '#') {
                // we get RGB data

                // decode rgb data
                uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);

                //analogWrite(redPin,    ((rgb >> 16) & 0xFF));
                //analogWrite(greenPin,  ((rgb >> 8) & 0xFF));
                //analogWrite(bluePin,   ((rgb >> 0) & 0xFF));
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