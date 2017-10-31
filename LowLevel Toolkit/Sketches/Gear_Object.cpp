#include "Gear_Object.h"

#pragma region Constructors

Gear_Object::Gear_Object()
{

}
Gear_Object::~Gear_Object()
{

}

#pragma endregion

#pragma region Gets and Sets

    uint Gear_Object::GetID() { return this->id; }
    String Gear_Object::GetName() { return this->name; }
    JsonObject* Gear_Object::GetJson(){ return this->json; }

#pragma endregion