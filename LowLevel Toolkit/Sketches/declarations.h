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
Gear_MPU6050 g_mpu(MPU_ADDR);
Gear_Button button_0(D7);
Gear_RGBLed rgbLed(D1, D2, D3, LedMode::STATIC, true);
Gear_Potentiometer pot(D8);
//-------

//--------HEADER--------
const size_t header_bufferSize = 5*JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 6*JSON_OBJECT_SIZE(3) + 2*JSON_OBJECT_SIZE(4) + 2*JSON_OBJECT_SIZE(5) + 310;
DynamicJsonBuffer header_jsonBuffer(header_bufferSize);

const char* header_json = "{\"header\":{\"buttons\":[{\"name\":\"button_0\",\"pin\":\"D2\",\"state\":false,\"type\":0}],\"potentiometers\":[{\"name\":\"pot_0\",\"pin\":\"D8\",\"value\":0}],\"rgb_leds\":[{\"name\":\"rgb_led_0\",\"pin\":\"D3,D4,D5\",\"mode\":2,\"value\":{\"r\":0,\"g\":1023,\"b\":0}}],\"leds\":[{\"name\":\"led_0\",\"pin\":\"D0\",\"value\":1}],\"mpus\":[{\"name\":\"mpu6050_0\",\"pins\":\"D6,D7\",\"accel\":{\"x\":0,\"y\":0,\"z\":0},\"gyro\":{\"x\":0,\"y\":0,\"z\":0},\"angle\":{\"x\":0,\"y\":0,\"z\":0}}]}}";

JsonObject& header_jsonRoot = header_jsonBuffer.parseObject(header_json);

String header_parserJSON;
//-------------------------


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