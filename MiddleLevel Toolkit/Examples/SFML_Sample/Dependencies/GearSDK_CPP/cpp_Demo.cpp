#include "Cpp_Client.h"

Cpp_Client client;

void UpdateObjects()
{
	double ax = client.wrapper.GetMPU6050(0)->GetAngle_X();
	double ay = client.wrapper.GetMPU6050(0)->GetAngle_Y();
	double az = client.wrapper.GetMPU6050(0)->GetAngle_Z();
	
	cout << ax << "," << ay << "," << az << endl;

	float intensity = client.wrapper.GetPotentiometer(0)->GetValue() / 1000.0;

	if (client.wrapper.GetButton(0)->GetState())
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);
		//wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();

		client.connection.SendMessage(s);

	}
	else
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);

		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();
		client.connection.SendMessage(s);
	}
}

int old_main()
{
	client = Cpp_Client("192.168.15.7", 81);

	client.Init();

	while (client.connection.IsConnected())
	{
		client.Update();

		if (client.CanUpdateObjects())
			UpdateObjects();
	}

	return 0;
}