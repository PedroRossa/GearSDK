#ifndef Cpp_Wrapper_H
#define Cpp_Wrapper_H

#include <cpprest/json.h>
#include <iostream>

#include "Gear_Objects\Gear_Button_cpp.h"
#include "Gear_Objects\Gear_Potentiometer_cpp.h"
#include "Gear_Objects\Gear_RGBLed_cpp.h"
#include "Gear_Objects\Gear_MPU6050_cpp.h"
#include "Gear_Objects\Gear_Servo_cpp.h"

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

	vector<Gear_Button_cpp*>* buttons;
	vector<Gear_Potentiometer_cpp*>* potentiometers;
	vector<Gear_RGBLed_cpp*>* rgbLeds;
	vector<Gear_MPU6050_cpp*>* mpus;
	vector<Gear_Servo_cpp*>* servos;

#pragma endregion

#pragma region Private Methods

	void CreateButton(string data);
	void CreatePotentiometer(string data);
	void CreateRGBLed(string data);
	void CreateMpu(string data);
	void CreateServo(string data);

	void UpdateButton(string data);
	void UpdatePotentiometer(string data);
	void UpdateRGBLed(string data);
	void UpdateMpu(string data);
	void UpdateServo(string data);

#pragma endregion
	
public:

#pragma region Constructors

	cpp_Wrapper();
	~cpp_Wrapper();

#pragma endregion

#pragma region Gets and Sets

	bool HeaderSetted();

	void SetData(string data);
	string GetData();

	Gear_Button_cpp* GetButton(int id);
	Gear_Potentiometer_cpp* GetPotentiometer(int id);
	Gear_RGBLed_cpp* GetRGBLed(int id);
	Gear_MPU6050_cpp* GetMPU6050(int id);
	Gear_Servo_cpp* GetServo(int id);

#pragma endregion

#pragma region Public Methods

	json::value StringToJson(string data);
	string JsonToString(json::value json);
	
	void Init(string header);
	
	void UpdateObjects(string data);

#pragma endregion

};

#endif
