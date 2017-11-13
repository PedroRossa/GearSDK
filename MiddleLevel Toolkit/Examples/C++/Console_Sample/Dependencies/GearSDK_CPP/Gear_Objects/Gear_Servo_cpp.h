#ifndef Gear_Servo_cpp_H
#define Gear_Servo_cpp_H

#include "..\Helper.h"

class Gear_Servo_cpp
{
private:

#pragma region Attributes

	int id;
	string name;
	string pin;
	int value;

	string lastJsonValue;

#pragma endregion

public:

#pragma region Constructors

	Gear_Servo_cpp();
	Gear_Servo_cpp(int id, string name, string pin, int value);
	~Gear_Servo_cpp();

#pragma endregion

#pragma region Getters and Setters

	int GetId();
	string GetName();
	string GetPin();
	int GetValue();

	void SetValue(int value);

#pragma endregion

#pragma region Public Methods

	string UpdatedJson();

#pragma endregion

};

#endif
