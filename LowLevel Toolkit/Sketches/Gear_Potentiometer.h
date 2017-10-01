#ifndef Gear_Potentiometer_h
#define Gear_Potentiometer_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication

class Gear_Potentiometer
{
private:

#pragma region Attributes

    int pin;
    int value;

#pragma endregion

public:

#pragma region Constructors

    Gear_Potentiometer();
    Gear_Potentiometer(int pin);
    ~Gear_Potentiometer();

#pragma endregion

#pragma region Getters

    int GetPin();
    float GetValue();

#pragma endregion

#pragma region Public Attributes

    void init();

#pragma endregion

};

#endif
