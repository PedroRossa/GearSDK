#ifndef Gear_PulseDetector_cpp_H
#define Gear_PulseDetector_cpp_H

#include "..\Helper.h"

class Gear_PulseDetector_cpp
{
private:

#pragma region Attributes

	int id;
	string name;
	string pin;
	int value;

#pragma endregion

public:

#pragma region Constructors

	Gear_PulseDetector_cpp();
	Gear_PulseDetector_cpp(int id, string name, string pin, int value);
	~Gear_PulseDetector_cpp();

#pragma endregion

#pragma region Getters and Setters

	int GetId();
	string GetName();
	string GetPin();
	int GetValue();

	void SetValue(int value);

#pragma endregion

};

#endif