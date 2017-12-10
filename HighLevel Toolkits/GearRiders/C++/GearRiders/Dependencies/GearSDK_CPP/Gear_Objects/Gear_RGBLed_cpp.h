#ifndef Gear_RGBLed_cpp_H
#define Gear_Button_cpp_H

#include "..\Helper.h"

class Gear_RGBLed_cpp
{
private:

#pragma region Attributes

	int id;
	string name;

	string pin_r;
	string pin_g;
	string pin_b;

	int mode;
	unsigned int timeOn;
	unsigned int timeOff;

	int r_value;
	int g_value;
	int b_value;

	string lastJsonValue;

#pragma endregion

public:

#pragma region Constructors

	Gear_RGBLed_cpp();
	Gear_RGBLed_cpp(int id, string name, string pin_r, string pin_g, string pin_b, int mode = LedMode::STATIC, int r_value = 1023, int g_value = 1023, int b_value = 1023, int timeOn = 1000, int timeOff = 500);
	~Gear_RGBLed_cpp();

#pragma endregion

#pragma region Getters and Setters

	int GetId();
	string GetName();
	string Get_R_Pin();
	string Get_G_Pin();
	string Get_B_Pin();

	int GetMode();

	int Get_R_Value();
	int Get_G_Value();
	int Get_B_Value();

	int* GetRGB_Value();

	void SetMode(LedMode mode, int timeOn = 1000, int timeOff = 500);

	void Set_R_Value(int r_value);
	void Set_G_Value(int g_value);
	void Set_B_Value(int b_value);

	void SetRGB_Value(int* values);
	void SetRGB_Value(int r, int g, int b);

#pragma endregion

#pragma region Public Methods

	string UpdatedJson();

#pragma endregion

};

#endif