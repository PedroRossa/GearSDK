#ifndef Gear_Servo_h
#define Gear_Servo_h

#include <Servo.h> 
#include "Gear_Object.h"

class Gear_Servo : public Gear_Object
{
private:

#pragma region Attributes

    int pin;
    int value;

    Servo servo;

#pragma endregion

#pragma region Private Methods

String headerJson();

#pragma endregion

public:

#pragma region Constructors

    Gear_Servo();
    Gear_Servo(String name, int pin);
    ~Gear_Servo();
	
#pragma endregion

#pragma region Gets and Sets

    int GetPin();
    int GetValue();

    void SetValue(int value);

#pragma endregion

#pragma region Public Methods

    void init();
    String updatedData();
    void receivedMessage(JsonObject& root, String type);

#pragma endregion

};

#endif
