#ifndef Gear_Potentiometer_h
#define Gear_Potentiometer_h

#include "Gear_Object.h"

class Gear_Potentiometer : public Gear_Object
{
private:

#pragma region Attributes

    int pin;
    int value;

#pragma endregion

#pragma region Private Methods

String headerJson();

#pragma endregion

public:

#pragma region Constructors

    Gear_Potentiometer();
    Gear_Potentiometer(String name, int pin);
    ~Gear_Potentiometer();

#pragma endregion

#pragma region Gets

    int GetPin();
    float GetValue();

#pragma endregion

#pragma region Public Attributes

    String GetHeader();
    void init();
    String updatedData();

#pragma endregion

};

#endif
