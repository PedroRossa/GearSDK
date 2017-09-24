#ifndef Gear_Button_h
#define Gear_Button_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication

class Gear_Button
{
private:

#pragma region Attributes

    int pin;
    int state;

#pragma endregion

public:

#pragma region Constructors

    Gear_Button();
    Gear_Button(int pin);
    ~Gear_Button();

#pragma endregion

#pragma region Getters

    int GetPin();
    int GetState();

#pragma endregion

#pragma region Public Attributes

    void init();

#pragma endregion

};

#endif
