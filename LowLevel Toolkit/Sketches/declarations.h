#include "Gear_MPU6050.h"
#include "Gear_Button.h"
#include "Gear_RGBLed.h"
#include "Gear_Potentiometer.h"
#include "Gear_Servo.h"
#include "Gear_WifiConnection.h"
#include "Gear_Manager.h"

//Explicar no doc de uso, que tem que instalar lib de list e lib de json


// Definições da rede Wifi

char* SSID = "teste";
char* PASSWORD = "12345678";

const int MPU_ADDR = 0x68;

bool headerReceivedByClient = false;
bool canReceiveMessage = true;
String jsonHeader;

enum JsonObjectType
{
    RGB_LED
};

//OBJECTS
Gear_WiFiConnection wifi(SSID, PASSWORD);

Gear_Manager* gearManager = new Gear_Manager();

Gear_MPU6050* g_mpu = new Gear_MPU6050("Mpu_0", D5, D6, MPU_ADDR);
Gear_Button* button_0 = new Gear_Button("button_0", D7);
Gear_Potentiometer* pot = new Gear_Potentiometer("pot_0", A0);
Gear_RGBLed* rgbLed = new Gear_RGBLed("rgbLed_0", D1, D2, D3, LedMode::STATIC, true);
Gear_Servo* servo_0 = new Gear_Servo("servo_0", D8);

//-------