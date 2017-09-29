#ifndef Gear_Button_cpp_H
#define Gear_Button_cpp_H

#include "Helper.h"

class Gear_Button_cpp
{
private:

#pragma region Attributes

	int id;
	string name;
	string pin;
	bool state;
	ButtonType type;

#pragma endregion

public:

#pragma region Constructors

	Gear_Button_cpp();
	Gear_Button_cpp(int id, string name, string pin, bool state = false, ButtonType type = ButtonType::PUSH_BUTTON);
	~Gear_Button_cpp();

#pragma endregion

#pragma region Getters and Setters

	int GetId();
	string GetName();
	string GetPin();
	bool GetState();
	ButtonType GetType();

#pragma endregion

};

#endif
