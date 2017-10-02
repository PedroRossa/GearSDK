#include "cpp_Client.h"

cpp_Client* client;

void TestObjects()
{
	double ax = client->wrapper->GetMPU6050(0)->GetAngle_X();
	double ay = client->wrapper->GetMPU6050(0)->GetAngle_Y();
	double az = client->wrapper->GetMPU6050(0)->GetAngle_Z();

	float intensity = client->wrapper->GetPotentiometer(0)->GetValue() / 1000.0;

	cout << ax << " " << ay << " " << az << " " << intensity << endl;

	if (client->wrapper->GetButton(0)->GetState())
	{
		client->wrapper->GetRGBLed(0)->SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
		client->wrapper->GetRGBLed(0)->SetMode(LedMode::STATIC);
		//wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
		string s = client->wrapper->GetRGBLed(0)->UpdatedJson();
	
		client->connection->SendMessage(s);
	
	}
	else
	{
		client->wrapper->GetRGBLed(0)->SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
		client->wrapper->GetRGBLed(0)->SetMode(LedMode::STATIC);
	
		string s = client->wrapper->GetRGBLed(0)->UpdatedJson();
		client->connection->SendMessage(s);
	}
}

void main()
{
	client = new cpp_Client("192.168.15.8", 81);

	client->Init();

	while (client->connection->IsConnected())
	{
		client->Update();
	
		TestObjects();
	}

	return;
}

