#include "Gear_MPU6050.h"
#include "Gear_Button.h"
#include "Gear_RGBLed.h"
#include "Gear_Potentiometer.h"
#include "Gear_WifiConnection.h"

#include <Hash.h>
#include <ArduinoJson.h>

// Definições da rede Wifi
char* SSID = "MILIOPA";
char* PASSWORD = "balapacaraio@2017";

//char* SSID = "Policia_Federal";
//char* PASSWORD = "roupaNOvaral@2017";

const int MPU_ADDR = 0x68;

bool headerReceivedByClient = false;
String jsonHeader;

//OBJECTS
Gear_WiFiConnection wifi(SSID, PASSWORD);

Gear_MPU6050 g_mpu("Mpu_0", D5, D6, MPU_ADDR);
Gear_Button button_0("button_0", D7);
Gear_Potentiometer pot("pot_0", A0);
Gear_RGBLed rgbLed("rgbLed_0", D1, D2, D3, LedMode::STATIC, true);
//-------