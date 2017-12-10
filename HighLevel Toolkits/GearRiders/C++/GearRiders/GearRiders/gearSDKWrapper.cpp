#include "gearSDKWrapper.h"

#pragma region Constructors

gearSDKWrapper::gearSDKWrapper()
{
}

gearSDKWrapper::gearSDKWrapper(string ip, int port)
{
	client = Cpp_Client(ip, port);
}

gearSDKWrapper::~gearSDKWrapper()
{
}

#pragma endregion

#pragma region Getters and Setters

Cpp_Client gearSDKWrapper::GetClient(){ return this->client; }

#pragma endregion

#pragma region Public Methods

HandleBarState gearSDKWrapper::HandlebarStatus()
{
	float angle = client.wrapper.GetMPU6050(0)->GetAngle_Z();

	if (angle < 20 || angle > 340)
		return HandleBarState::CENTER;
	else if (angle > 20 && angle < 270)
		return HandleBarState::LEFT;
	else
		return HandleBarState::RIGHT;
}

float gearSDKWrapper::HandleBarValue()
{
	return client.wrapper.GetMPU6050(0)->GetAngle_Z();
}

int gearSDKWrapper::Pulse()
{
	int val = client.wrapper.GetPulseDetector(0)->GetValue();

	//convert from brute value to pulse value
	val /= 60;
	return val;
}

float gearSDKWrapper::CurrentSpeed()
{
	//need to be implemented using the hallEffect sensor
}

float gearSDKWrapper::AverageSpeed()
{
	//need to be implemented using the hallEffect sensor
}

float gearSDKWrapper::MaxSpeed()
{
	//need to be implemented using the hallEffect sensor
}

bool gearSDKWrapper::Button01()
{
	return client.wrapper.GetButton(0)->GetState();
}

bool gearSDKWrapper::Button02()
{
	return client.wrapper.GetButton(1)->GetState();
}

#pragma endregion
