#ifndef Gear_HallEffect_cpp_H
#define Gear_HallEffect_cpp_H

#include "..\Helper.h"

class Gear_HallEffect_cpp
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

	Gear_HallEffect_cpp();
	Gear_HallEffect_cpp(int id, string name, string pin, int value);
	~Gear_HallEffect_cpp();

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