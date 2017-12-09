#ifndef Gear_HallEffect_h
#define Gear_HallEffect_h

#include "Gear_Object.h"

class Gear_HallEffect : public Gear_Object
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

    Gear_HallEffect();
    Gear_HallEffect(String name, int pin, int value);
    ~Gear_HallEffect();
	
#pragma endregion

#pragma region Gets and Sets

    int GetPin();
    int GetValue();
	
#pragma endregion

#pragma region Public Methods

    void init();
    String updatedData();
    void receivedMessage(JsonObject& root, String type);
	
#pragma endregion

};

#endif