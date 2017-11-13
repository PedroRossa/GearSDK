#include <chrono>
#include <thread>
#include "..\Dependencies\GearSDK_CPP\Cpp_Client.h"

Cpp_Client client;

void UpdateObjects()
{
	int acellX = client.wrapper.GetMPU6050(0)->GetAccel_X();
	int acellY = client.wrapper.GetMPU6050(0)->GetAccel_Y();
	int acellZ = client.wrapper.GetMPU6050(0)->GetAccel_Z();

	int gyroX = client.wrapper.GetMPU6050(0)->GetGyro_X();
	int gyroY = client.wrapper.GetMPU6050(0)->GetGyro_Y();
	int gyroZ = client.wrapper.GetMPU6050(0)->GetGyro_Z();

	double angleX = client.wrapper.GetMPU6050(0)->GetAngle_X();
	double angleY = client.wrapper.GetMPU6050(0)->GetAngle_Y();
	double angleZ = client.wrapper.GetMPU6050(0)->GetAngle_Z();

	int potentiometer = client.wrapper.GetPotentiometer(0)->GetValue();

	bool buttonState = client.wrapper.GetButton(0)->GetState();

	int r = client.wrapper.GetRGBLed(0)->Get_R_Value();
	int g = client.wrapper.GetRGBLed(0)->Get_G_Value();
	int b = client.wrapper.GetRGBLed(0)->Get_B_Value();

	int motorVal = client.wrapper.GetServo(0)->GetValue();

	cout << "BUTTON: " << buttonState << endl;
	cout << "POTENTIOMETER: " << potentiometer << endl;
	cout << "MOTOR: " << motorVal << endl;
	//cout << "ACELEROMETER: (" << acellX << ", " << acellY << ", " << acellZ << ")" << endl;
	//cout << "GYRO: (" << gyroX << ", " << gyroY << ", " << gyroZ << ")" << endl;
	//cout << "ANGLE: (" << angleX << ", " << angleY << ", " << angleZ << ")" << endl;
	//cout << "RGB LED: (" << r << ", " << g << ", " << b << ")" << endl;

	//this_thread::sleep_for(chrono::milliseconds(20));
	//system("cls");


	float intensity = potentiometer / 1000.0;

	if (buttonState)
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);
		
		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();

		if (s != "")
		{
			client.connection.SendMessage(s);
		}

		client.wrapper.GetServo(0)->SetValue(0);
		s = client.wrapper.GetServo(0)->UpdatedJson();
		
		if (s != "")
		{
			client.connection.SendMessage(s);
		}
	}
	else
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);
		
		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();
		
		if (s != "")
		{
			client.connection.SendMessage(s);
		}

		client.wrapper.GetServo(0)->SetValue(15);
		s = client.wrapper.GetServo(0)->UpdatedJson();

		if (s != "")
		{
			client.connection.SendMessage(s);
		}
	}
}

int main()
{
	client = Cpp_Client("192.168.43.36", 81);

	client.Init();

	while (client.connection.IsConnected())
	{
		client.Update();
		UpdateObjects();
	}

	return 0;
}