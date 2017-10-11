#include <SFML/Graphics.hpp>

#include "../Dependencies/GearSDK_CPP/Cpp_Client.h"
#include "Screen.h"

Screen screen;
Cpp_Client client;

double accel[3] = { 0,0,0 };
double gyro[3] = { 0,0,0 };
double angle[3] = { 0,0,0 };
float pot = 0;
bool btnState = false;

void Update_GearObjects()
{

	accel[0] = client.wrapper.GetMPU6050(0)->GetAccel_X();
	accel[1] = client.wrapper.GetMPU6050(0)->GetAccel_Y();
	accel[2] = client.wrapper.GetMPU6050(0)->GetAccel_Z();

	gyro[0] = client.wrapper.GetMPU6050(0)->GetGyro_X();
	gyro[1] = client.wrapper.GetMPU6050(0)->GetGyro_Y();
	gyro[2] = client.wrapper.GetMPU6050(0)->GetGyro_Z();

	angle[0] = client.wrapper.GetMPU6050(0)->GetAngle_X();
	angle[1] = client.wrapper.GetMPU6050(0)->GetAngle_Y();
	angle[2] = client.wrapper.GetMPU6050(0)->GetAngle_Z();

	pot = client.wrapper.GetPotentiometer(0)->GetValue() / 1000.0;

	btnState = client.wrapper.GetButton(0)->GetState();
	
	if (btnState)
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(pot * 1023), (int)(pot * 0), (int)(pot * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);
		//wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();
		client.connection.SendMessage(s);
	}
	else
	{
		client.wrapper.GetRGBLed(0)->SetRGB_Value((int)(pot * 0), (int)(pot * 1023), (int)(pot * 1023));
		client.wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);

		string s = client.wrapper.GetRGBLed(0)->UpdatedJson();
		client.connection.SendMessage(s);
	}
}

void Update_SFLMObjects()
{
	string s_accel = "Accel: (" + to_string((int)accel[0]) + ", " + to_string((int)accel[1]) + ", " + to_string((int)accel[2]) + ")";
	screen.txtAccelerometer.setString(s_accel);

	string s_gyro = "Gyro: (" + to_string((int)gyro[0]) + ", " + to_string((int)gyro[1]) + ", " + to_string((int)gyro[2]) + ")";
	screen.txtGyro.setString(s_gyro);

	string s_angle = "Angle: (" + to_string((int)angle[0]) + ", " + to_string((int)angle[1]) + ", " + to_string((int)angle[2]) + ")";
	screen.txtAngle.setString(s_angle);

	string s_pot = "Pot: " + to_string(pot);
	screen.txtPotentiometer.setString(s_pot);

	string s_button = "Button: " + to_string(btnState);
	screen.txtButton.setString(s_button);

	sf::Color col;
	if (btnState)
	{
		col.r = 255; col.g = 0; col.b = 255;
		col.a = 255 * pot;
	}
	else {
		col.r = 0; col.g = 255; col.b = 255;
		col.a = 255 * pot;
	}

	screen.spLed.setFillColor(col);

}

void GearSDL_Loop()
{
	if (client.connection.IsConnected())
	{
		client.Update();

		if (client.CanUpdateObjects())
		{
			Update_GearObjects();

			Update_SFLMObjects();
		}
	}
}

void SFML_Loop()
{
	while (screen.window->isOpen())
	{
		sf::Event event;
		while (screen.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.window->close();
		}

		GearSDL_Loop();

		screen.WindowUpdate();
	}
}

int main()
{
	client = Cpp_Client("192.168.15.7", 81);
	client.Init();

	screen = Screen();

	SFML_Loop();
	
	return 0;
}