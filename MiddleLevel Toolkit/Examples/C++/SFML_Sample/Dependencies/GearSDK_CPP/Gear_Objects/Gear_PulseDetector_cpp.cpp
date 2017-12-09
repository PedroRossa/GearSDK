#include "Gear_PulseDetector_cpp.h"

#pragma region Constructors

Gear_PulseDetector_cpp::Gear_PulseDetector_cpp()
{
}

Gear_PulseDetector_cpp::Gear_PulseDetector_cpp(int id, string name, string pin, int value)
{
	this->id = id;
	this->name = name;
	this->pin = pin;
	this->value = value;
}

Gear_PulseDetector_cpp::~Gear_PulseDetector_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_PulseDetector_cpp::GetId() { return this->id; }

string Gear_PulseDetector_cpp::GetName() { return this->name; }
string Gear_PulseDetector_cpp::GetPin() { return this->pin; }
int Gear_PulseDetector_cpp::GetValue() { return this->value; }


void Gear_PulseDetector_cpp::SetValue(int value) { this->value = value; }

#pragma endregion