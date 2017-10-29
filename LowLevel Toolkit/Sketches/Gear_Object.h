#ifndef Gear_Object_h
#define Gear_Object_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication
#include <Hash.h>
#include <ArduinoJson.h>

class Gear_Object
{
protected:

#pragma region Attributes

    String name;        
    String header;

    DynamicJsonBuffer* jsonBuffer;
    JsonObject* json;

#pragma endregion

#pragma region Private Methods

    virtual String headerJson() = 0;

#pragma endregion

public:

#pragma region Constructors

    Gear_Object();
    ~Gear_Object();

#pragma endregion

#pragma region Gets

    String GetName();
    JsonObject* GetJson();

#pragma endregion

#pragma region Public Methods

    virtual String GetHeader() = 0;
    virtual void init() = 0;
    virtual String updatedData() = 0;

#pragma endregion

};

#endif
