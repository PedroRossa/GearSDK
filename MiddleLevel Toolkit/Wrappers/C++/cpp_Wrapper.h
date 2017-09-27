#ifndef Cpp_Wrapper_H
#define Cpp_Wrapper_H

#include <cpprest/json.h>
#include <iostream>

#include "Sample\cpp_Sample\Gear_Button_cpp.h"
#include "Sample\cpp_Sample\Gear_RGBLed_cpp.h"

using namespace std;
using namespace web;
using namespace utility;

class cpp_Wrapper
{

#pragma region Attributes

	string data;
	json::value jsonValue;
	json::value header;

	bool headerSetted = false;

	vector<Gear_Button_cpp> buttons;
	vector<Gear_RGBLed_cpp> rgbLeds;

#pragma endregion

#pragma region Private Methods

	Gear_Button_cpp CreateButton(json::value values);

	Gear_RGBLed_cpp CreateRGBLed(json::value values);

#pragma endregion
	
public:

#pragma region Constructors

	cpp_Wrapper();
	~cpp_Wrapper();

#pragma endregion

#pragma region Getters and Setters

	bool HeaderSetted();

	void SetData(string data);
	string GetData();


	Gear_Button_cpp GetButton(int id);
	Gear_RGBLed_cpp GetRGBLed(int id);


	bool GetBool(string key);
	int GetInt(string key);
	float GetFloat(string key);
	string GetString(string key);
	json::object GetObject(string key);

	int* Get_xyz_Int(string key);
	int* Get_xyzw_Int(string key);

	float* Get_xyz_Float(string key);
	float* Get_xyzw_Float(string key);

#pragma endregion

#pragma region Public Methods

	json::value StringToJson(string data);
	string JsonToString(json::value json);

	void Init(string header);

	void UpdateObjects();

#pragma endregion

};

#endif
