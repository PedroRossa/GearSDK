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

bool headerReceivedByClient = false;

//--------HEADER--------
const size_t header_bufferSize = JSON_ARRAY_SIZE(1) + 2*JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(1) + 5*JSON_OBJECT_SIZE(3) + 5*JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + 420;
DynamicJsonBuffer header_jsonBuffer(header_bufferSize);

const char* header_json = "{\"header\":{\"buttons\":[{\"name\":\"button_0\",\"pin\":\"D7\",\"state\":false,\"type\":\"PUSH_BUTTON\"},{\"name\":\"button_1\",\"pin\":\"D8\",\"state\":false,\"type\":\"PUSH_BUTTON\"}],\"rgb_leds\":[{\"name\":\"rgb_led_0\",\"pin\":\"D3,D4,D5\",\"mode\":\"BLINKING\",\"value\":{\"r\":0,\"g\":1023,\"b\":0}}],\"leds\":[{\"name\":\"led_0\",\"pin\":\"D8\",\"value\":1},{\"name\":\"led_1\",\"pin\":\"D9\",\"mode\":\"STATIC\",\"value\":0}],\"accelerometer\":{\"name\":\"accelerometer_0\",\"pins\":\"D6,D7\",\"value\":{\"x\":0,\"y\":0,\"z\":0}},\"gyroscope\":{\"id\":\"gyroscope_0\",\"pin\":\"D6,D7\",\"value\":{\"x\":0,\"y\":0,\"z\":0,\"w\":0}}}}";
JsonObject& header_jsonRoot = header_jsonBuffer.parseObject(header_json);

String header_parserJSON;
//-------------------------

const size_t bufferSize = JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(4) + 6*JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(3) + 2*JSON_OBJECT_SIZE(4) + 160;
DynamicJsonBuffer jsonBuffer(bufferSize);

const char* json = "{\"data\":{\"buttons\":[{\"button_0\":false},{\"button_1\":false},{\"button_2\":false},{\"button_3\":false}],\"rgb_leds\":[{\"rgb_led_0\":{\"r\":1023,\"g\":1023,\"b\":1023}}],\"gyro\":{\"x\":0,\"y\":0,\"z\":0,\"w\":0},\"accelerometer\":{\"x\":0,\"y\":0,\"z\":0}}}";

JsonObject& jsonRoot = jsonBuffer.parseObject(json);

JsonObject& j_data = jsonRoot["data"];
JsonArray& j_buttons = j_data["buttons"];
JsonArray& j_rgbLeds = j_data["rgb_leds"];
JsonObject& j_gyro = j_data["gyro"];
JsonObject& j_accelerometer = j_data["accelerometer"];

String parserJSON;