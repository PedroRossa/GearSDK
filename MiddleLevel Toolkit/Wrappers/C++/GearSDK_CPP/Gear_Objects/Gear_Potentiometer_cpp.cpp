#include "Gear_Potentiometer_cpp.h"

#pragma region Constructors

Gear_Potentiometer_cpp::Gear_Potentiometer_cpp()
{
}

Gear_Potentiometer_cpp::Gear_Potentiometer_cpp(int id, string name, string pin, int value)
{
	this->id = id;
	this->name = name;
	this->pin = pin;
	this->value = value;
}

Gear_Potentiometer_cpp::~Gear_Potentiometer_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_Potentiometer_cpp::GetId() { return this->id; }

string Gear_Potentiometer_cpp::GetName() { return this->name; }
string Gear_Potentiometer_cpp::GetPin() { return this->pin; }
int Gear_Potentiometer_cpp::GetValue() { return this->value; }

void Gear_Potentiometer_cpp::SetValue(int value) { this->value = value; }

#pragma endregion