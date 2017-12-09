#ifndef Gear_PulseDetector_h
#define Gear_PulseDetector_h

#include "Gear_Object.h"

class Gear_PulseDetector : public Gear_Object
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

    Gear_PulseDetector();
    Gear_PulseDetector(String name, int pin, int value);
    ~Gear_PulseDetector();
	
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