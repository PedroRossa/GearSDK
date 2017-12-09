#include "Gear_HallEffect_cpp.h"

#pragma region Constructors

Gear_HallEffect_cpp::Gear_HallEffect_cpp()
{
}

Gear_HallEffect_cpp::Gear_HallEffect_cpp(int id, string name, string pin, int value)
{
	this->id = id;
	this->name = name;
	this->pin = pin;
	this->value = value;
}

Gear_HallEffect_cpp::~Gear_HallEffect_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_HallEffect_cpp::GetId() { return this->id; }

string Gear_HallEffect_cpp::GetName() { return this->name; }
string Gear_HallEffect_cpp::GetPin() { return this->pin; }
int Gear_HallEffect_cpp::GetValue() { return this->value; }


void Gear_HallEffect_cpp::SetValue(int value) { this->value = value; }

#pragma endregion