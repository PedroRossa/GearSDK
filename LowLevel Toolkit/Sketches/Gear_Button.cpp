#include "Gear_Button.h"

#pragma region Constructors

Gear_Button::Gear_Button(){}

Gear_Button::Gear_Button(int pin)
{
    this->pin = pin;
}

Gear_Button::~Gear_Button(){}

#pragma endregion

#pragma region Getters

     int Gear_Button::GetPin() { return this->pin; }
     
     int Gear_Button::GetState()
     {
        this->state = digitalRead(this->pin);
        return this->state; 
     }

#pragma endregion

#pragma region Public Methods
 
void Gear_Button::init()
{
    pinMode(this->pin, INPUT);
}

#pragma endregion