#ifndef Gear_<MY OBJECT>_h
#define Gear_<MY OBJECT>_h

#include "Gear_Object.h"

class Gear_<MY OBJECT> : public Gear_Object
{
private:

#pragma region Attributes

    int pin;
    int value;
	
	/* Create HERE other util/necessary Attributes to your object */

#pragma endregion

#pragma region Private Methods

String headerJson();

	/* Create HERE other util/necessary Private Methods to your object */

#pragma endregion

public:

#pragma region Constructors

    Gear_<MY OBJECT>();
    Gear_<MY OBJECT>(String name, int pin, int value);
    ~Gear_<MY OBJECT>();
	
	/* Create HERE other util/necessary Constructors to your object */

#pragma endregion

#pragma region Gets and Sets

    int GetPin();
    int GetValue();
	
	/* Create HERE other util/necessary Gets and Sets to your object */

#pragma endregion

#pragma region Public Methods

    void init();
    String updatedData();
    void receivedMessage(JsonObject& root, String type);
	
	/* Create HERE other util/necessary functions to your object */

#pragma endregion

};

#endif
