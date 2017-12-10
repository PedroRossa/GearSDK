#ifndef GEAR_SDK_WRAPPER_H
#define GEAR_SDK_WRAPPER_H

#include <chrono>
#include <thread>
#include "../Dependencies/GearSDK_CPP/Cpp_Client.h"

enum HandleBarState
{
	LEFT,
	CENTER,
	RIGHT
};

enum TypeOfSpeed
{
	AVERAGE,
	MAX,
	CURRENT
};

class gearSDKWrapper
{
private:

#pragma region Attributes

	Cpp_Client client;

#pragma endregion
	
public:

#pragma region Constructors

	gearSDKWrapper();
	gearSDKWrapper(string ip, int port = 81);
	~gearSDKWrapper();

#pragma endregion

#pragma region Getters and Setters

	Cpp_Client GetClient();

#pragma endregion

#pragma region Public Methods

	HandleBarState HandlebarStatus();
	float HandleBarValue();

	int Pulse();

	float CurrentSpeed();
	float AverageSpeed();
	float MaxSpeed();

	bool Button01();
	bool Button02();

#pragma endregion

};

#endif
