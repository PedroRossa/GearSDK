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

const int MPU_ADDR = 0x68;

bool headerReceivedByClient = false;

//OBJECTS
Gear_WiFiConnection wifi(SSID, PASSWORD);

Gear_MPU6050 g_mpu("Mpu_0", D5, D6, MPU_ADDR);
Gear_Button button_0("button_0", D7);
Gear_Potentiometer pot("pot_0", A0);
Gear_RGBLed rgbLed("rgbLed_0", D1, D2, D3, LedMode::STATIC, true);
//-------

String jsonHeader;

//--------DATA--------
const size_t bufferSize = 5*JSON_ARRAY_SIZE(1) + 3*JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + 5*JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + 190;
DynamicJsonBuffer jsonBuffer(bufferSize);

const char* json = "{\"data\":{\"buttons\":[{\"state\":false,\"type\":0}],\"potentiometers\":[{\"value\":0}],\"rgb_leds\":[{\"mode\":2,\"value\":{\"r\":0,\"g\":1023,\"b\":0}}],\"leds\":[{\"value\":1}],\"mpus\":[{\"accel\":{\"x\":0,\"y\":0,\"z\":0},\"gyro\":{\"x\":0,\"y\":0,\"z\":0},\"angle\":{\"x\":0,\"y\":0,\"z\":0}}]}}";

JsonObject& jsonRoot = jsonBuffer.parseObject(json);

JsonObject& j_data = jsonRoot["data"];
JsonArray& j_buttons = j_data["buttons"];
JsonArray& j_potentiometers = j_data["potentiometers"];
JsonArray& j_rgbLeds = j_data["rgb_leds"];
JsonArray& j_leds = j_data["leds"];
JsonArray& j_mpus = j_data["mpus"];

String parserJSON;
//-------------------------