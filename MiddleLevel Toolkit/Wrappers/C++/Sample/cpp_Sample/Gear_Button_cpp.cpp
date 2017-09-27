#include "Gear_Button_cpp.h"

#pragma region Constructors

Gear_Button_cpp::Gear_Button_cpp()
{
}

Gear_Button_cpp::Gear_Button_cpp(string name, string pin, bool state, ButtonType type)
{
	this->name = name;
	this->pin = pin;
	this->state = state;
	this->type = type;
}

Gear_Button_cpp::~Gear_Button_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

string Gear_Button_cpp::GetName() { return this->name; }
string Gear_Button_cpp::GetPin() { return this->pin; }
bool Gear_Button_cpp::GetState() { return this->state; }
ButtonType Gear_Button_cpp::GetType() { return this->type; }

#pragma endregion
