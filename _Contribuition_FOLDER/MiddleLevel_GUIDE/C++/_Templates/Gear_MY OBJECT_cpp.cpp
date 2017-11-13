#include "Gear_<MY OBJECT>_cpp.h"

#pragma region Constructors

Gear_<MY OBJECT>_cpp::Gear_<MY OBJECT>_cpp()
{
}

Gear_<MY OBJECT>_cpp::Gear_<MY OBJECT>_cpp(int id, string name, string pin, int value)
{
	this->id = id;
	this->name = name;
	this->pin = pin;
	this->value = value;
}

Gear_<MY OBJECT>_cpp::~Gear_<MY OBJECT>_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_<MY OBJECT>_cpp::GetId() { return this->id; }

string Gear_<MY OBJECT>_cpp::GetName() { return this->name; }
string Gear_<MY OBJECT>_cpp::GetPin() { return this->pin; }
int Gear_<MY OBJECT>_cpp::GetValue() { return this->value; }


void Gear_<MY OBJECT>_cpp::SetValue(int value) { this->value = value; }

#pragma endregion
