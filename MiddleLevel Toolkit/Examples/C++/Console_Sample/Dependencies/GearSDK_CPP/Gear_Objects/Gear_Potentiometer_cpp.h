#ifndef Gear_Potentiometer_cpp_H
#define Gear_Potentiometer_cpp_H

#include <iostream>
using namespace std;

class Gear_Potentiometer_cpp
{

#pragma region Attributes

	int id;
	string name;
	string pin;
	int value;

#pragma endregion

public:

#pragma region Constructors

	Gear_Potentiometer_cpp();
	Gear_Potentiometer_cpp(int id, string name, string pin, int value);
	~Gear_Potentiometer_cpp();

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

