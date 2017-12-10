#include "Gear_Servo_cpp.h"

#pragma region Constructors

Gear_Servo_cpp::Gear_Servo_cpp()
{
}

Gear_Servo_cpp::Gear_Servo_cpp(int id, string name, string pin, int value)
{
	this->id = id;
	this->name = name;
	this->pin = pin;
	this->value = value;
}

Gear_Servo_cpp::~Gear_Servo_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_Servo_cpp::GetId() { return this->id; }

string Gear_Servo_cpp::GetName() { return this->name; }
string Gear_Servo_cpp::GetPin() { return this->pin; }
int Gear_Servo_cpp::GetValue() { return this->value; }


void Gear_Servo_cpp::SetValue(int value) { this->value = value; }

#pragma endregion


#pragma region Public Methods

string Gear_Servo_cpp::UpdatedJson()
{
	string val = "{\"servo\":{\"name\":\"" + this->name + "\",";
	val += "\"pin\":\"" + this->pin + "\",";
	val += "\"value\":" + to_string(this->value);
	val += "}}";

	if (lastJsonValue != val)
	{
		lastJsonValue = val;
	}
	else
	{
		val = "";
	}

	return val;
}

#pragma endregion
