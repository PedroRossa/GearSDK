#ifndef Gear_Manager_h
#define Gear_Manager_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication
#include <Hash.h>
#include <ArduinoJson.h>

#include "Gear_Object.h"

#define MAX_OBJECTS 8

class Gear_Manager
{
protected:

#pragma region Attributes

Gear_Object* objs[MAX_OBJECTS];
int objsSize = 0;

#pragma endregion

public:

#pragma region Constructors

    Gear_Manager();
    ~Gear_Manager();

#pragma endregion

#pragma region Gets

Gear_Object** getObjects();
int getObjectsSize();

Gear_Object* getObject(int id);
Gear_Object* getObject(String name);

#pragma endregion

#pragma region Public Methods

void add(Gear_Object* object);
void init();
String createJsonHeader();
String createJsonData();

#pragma endregion

};

#endif
