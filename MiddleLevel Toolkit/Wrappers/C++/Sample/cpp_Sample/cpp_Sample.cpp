#include "cpp_Client.h"

cpp_Client client;

void TestObjects()
{
	float intensity = client.wrapper.GetPotentiometer(0)->GetValue() / 1000.0;

	//double ax = client->wrapper->GetMPU6050(0)->GetAngle_X();
	//double ay = client->wrapper->GetMPU6050(0)->GetAngle_Y();
	//double az = client->wrapper->GetMPU6050(0)->GetAngle_Z();
	//cout << ax << " " << ay << " " << az << " " << intensity << endl;

	Gear_RGBLed_cpp* aux = client.wrapper.GetRGBLed(0);

	if (client.wrapper.GetButton(0)->GetState())
	{
		aux->SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
		aux->SetMode(LedMode::STATIC);
		//aux->SetMode(LedMode::BLINKING, 500, 100);

		string s = aux->UpdatedJson();
		client.wrapper.SetRGBLed(0, aux);

		client.connection.SendMessage(s);
	}
	else
	{
		aux->SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
		aux->SetMode(LedMode::STATIC);
	
		string s = aux->UpdatedJson();
		client.wrapper.SetRGBLed(0, aux);

		client.connection.SendMessage(s);
	}
}

void main()
{
	client = cpp_Client("192.168.15.12", 81);

	client.Init();

	while (client.connection.IsConnected())
	{
		client.Update();
	
		TestObjects();
	}

	return;
}

