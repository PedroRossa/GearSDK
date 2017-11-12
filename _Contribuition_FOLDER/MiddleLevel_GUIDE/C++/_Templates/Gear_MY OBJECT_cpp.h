#ifndef Gear_<MY OBJECT>_cpp_H
#define Gear_<MY OBJECT>_cpp_H

#include "..\Helper.h"

class Gear_<MY OBJECT>_cpp
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

	Gear_<MY OBJECT>_cpp();
	Gear_<MY OBJECT>_cpp(int id, string name, string pin, int value);
	~Gear_<MY OBJECT>_cpp();

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
