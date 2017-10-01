#include "Gear_Potentiometer.h"

#pragma region Constructors

    Gear_Potentiometer::Gear_Potentiometer()
    {

    }

    Gear_Potentiometer::Gear_Potentiometer(int pin)
    {

    }

    Gear_Potentiometer::~Gear_Potentiometer()
    {

    }

#pragma endregion

#pragma region Getters

    int Gear_Potentiometer::GetPin(){ return this->pin; }
    float Gear_Potentiometer::GetValue()
    {
        this->value = analogRead(this->pin);
        return this->value; 
     }

#pragma endregion

#pragma region Public Attributes

    void Gear_Potentiometer::init()
    {
        pinMode(this->pin, INPUT);
    }

#pragma endregion

