#include "../../cpp_Connection.h"
#include "../../cpp_Wrapper.h"

cpp_Connection cppConnection("192.168.15.2", 81);
cpp_Wrapper wrapper;

int atualNumberOfMessages = 0;

bool handShakeDone = false;

bool button_0_state;
float accelerometer_val[3] = { 0,0,0 };
float gyro_val[4] = { 0,0,0,0 };

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
			while(!wrapper.HeaderSetted())
			{
				wrapper.Init(cppConnection.ReceivedMessage());
			}

			if (!handShakeDone)
			{
				cppConnection.SendMessage("@ Hand Shake");
				handShakeDone = true;
			}

			//If the number of connection messages grether then localCounter, it's a new message
			if (cppConnection.GetNumberOfMessagesReceived() > atualNumberOfMessages)
			{
				atualNumberOfMessages = cppConnection.GetNumberOfMessagesReceived();

				//cout << cppConnection.ReceivedMessage() << endl;
				
				wrapper.SetData(cppConnection.ReceivedMessage());

				/*
				button_0_state = wrapper.GetBool("button_0");

				float* accel = wrapper.Get_xyz_Float("accelerometer");

				if (accel != NULL)
				{
					accelerometer_val[0] = accel[0];
					accelerometer_val[1] = accel[1];
					accelerometer_val[2] = accel[2];
				}
					cout << "Accelerometer is NULL" << endl;

				float* gyro = wrapper.Get_xyz_Float("gyro");

				if (gyro != NULL)
				{
					gyro_val[0] = gyro[0];
					gyro_val[1] = gyro[1];
					gyro_val[2] = gyro[2];
				}
				else
					cout << "Gyro is NULL" << endl;


				cout << "------ Buttons ------" << endl;
				cout << " Button_0 : " << button_0_state << endl;
				cout << "---------------------" << endl << endl;

				cout << "--- Accelerometer ---" << endl;
				cout << "(" << accelerometer_val[0] << "," << accelerometer_val[1] << "," << accelerometer_val[2] << ")" << endl;
				cout << "---------------------" << endl;

				cout << "------- Gyro --------" << endl;
				cout << "(" << gyro_val[0] << "," << gyro_val[1] << "," << gyro_val[2] << ")" << endl;
				cout << "---------------------" << endl;

				system("cls");
				*/

				//if (wrapper.GetButton(0).GetState())
				button_0_state = wrapper.GetButton(0).GetState();

				if(button_0_state)
				{
					wrapper.GetRGBLed(0).SetRGB_Value(1023, 0, 1023);
					string s = wrapper.GetRGBLed(0).UpdatedJsonValue();
					
				}
				else
				{
					wrapper.GetRGBLed(0).SetRGB_Value(0, 1023, 1023);
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

