#include "../../cpp_Connection.h"
#include "../../cpp_Wrapper.h"

cpp_Connection cppConnection("192.168.15.7", 81);
cpp_Wrapper wrapper;

int atualNumberOfMessages = 0;

bool handShakeDone = false;

bool button_0_state;
float accelerometer_val[3] = { 0,0,0 };
float gyro_val[4] = { 0,0,0,0 };

void TryHandShakeWithServer()
{
	while (!wrapper.HeaderSetted())
		wrapper.Init(cppConnection.ReceivedMessage());

	if (!handShakeDone)
	{
		cppConnection.SendMessage("@ Hand Shake");
		handShakeDone = true;
	}
}

void main()
{
	try
	{
		//Connect to WebServer
		while (!cppConnection.IsConnected())
		{
			//Check for succesful connection
			if (cppConnection.Connect())
				cppConnection.SendMessage("Server we are soooo connected!!! <3 ");
			else
			{
				cout << "some problem with connection occours!" << endl << endl;
				system("pause");
				return;
			}
		}

		//while connected with the server, try read messages
		while (cppConnection.IsConnected())
		{
			if(!handShakeDone)
				TryHandShakeWithServer(); //Loop until handshake done!

			//If the number of connection messages grether then localCounter, it's a new message
			if (cppConnection.GetNumberOfMessagesReceived() > atualNumberOfMessages)
			{
				atualNumberOfMessages = cppConnection.GetNumberOfMessagesReceived();
				
				wrapper.UpdateObjects(cppConnection.ReceivedMessage());

				double ax = wrapper.GetMPU6050(0)->GetAngle_X();
				double ay = wrapper.GetMPU6050(0)->GetAngle_Y();
				double az = wrapper.GetMPU6050(0)->GetAngle_Z();

				float intensity = wrapper.GetPotentiometer(0)->GetValue()/1000.0;

 				if(wrapper.GetButton(0)->GetState())
				{
					wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity*1023), (int)(intensity*0), (int)(intensity*1023));
					wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);
					//wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
					string s = wrapper.GetRGBLed(0)->UpdatedJson();

					cppConnection.SendMessage(s);
					
				}
				else
				{
					wrapper.GetRGBLed(0)->SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
					wrapper.GetRGBLed(0)->SetMode(LedMode::STATIC);

					string s = wrapper.GetRGBLed(0)->UpdatedJson(); 
					cppConnection.SendMessage(s);
				}

			}

			//forced disconnetion
			//if (atualNumberOfMessages > 40)
			//{
			//	cout << "Disconnecting..." << endl << endl;
			//	cppConnection.Disconnect();
			//	break;
			//}
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	system("pause");
}

