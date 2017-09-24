#include "Gear_MPU6050.h"
#include "Gear_Button.h"
#include "Gear_RGBLed.h"
#include "Gear_WifiConnection.h"

#include <Hash.h>
#include <ArduinoJson.h>

// Definições da rede Wifi
char* SSID = "MILIOPA";
char* PASSWORD = "balapacaraio@2017";

const int MPU_ADDR = 0x68;

const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(6) + 110;
DynamicJsonBuffer jsonBuffer(bufferSize);

const char* json = "{\"data\":{\"button_0\":0,\"button_1\":0,\"button_2\":0,\"button_3\":0,\"gyro\":{\"x\":0,\"y\":0,\"z\":0,\"w\":0},\"accelerometer\":{\"x\":0,\"y\":0,\"z\":0}}}";

JsonObject& jsonRoot = jsonBuffer.parseObject(json);

JsonObject& data = jsonRoot["data"];
JsonObject& gyro = data["gyro"];
JsonObject& accelerometer = data["accelerometer"];

String parserJSON;