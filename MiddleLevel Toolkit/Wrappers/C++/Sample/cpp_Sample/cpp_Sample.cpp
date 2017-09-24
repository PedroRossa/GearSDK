#include "../../cpp_Connection.h"
#include "../../cpp_Wrapper.h"

cpp_Connection cppConnection("192.168.15.8", 81);
cpp_Wrapper wrapper;

int atualNumberOfMessages = 0;

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
			//If the number of connection messages grether then localCounter, it's a new message
			if (cppConnection.GetNumberOfMessagesReceived() > atualNumberOfMessages)
			{
				atualNumberOfMessages = cppConnection.GetNumberOfMessagesReceived();
				//cout << cppConnection.ReceivedMessage() << endl;

				//AQUI FALTA TRATAR PRA O WRAPPER PRA PEGAR CERTINHO OS VALORES E CASO NAO TENHA NAO ESTOURAR EXEPETION

				wrapper.SetData(cppConnection.ReceivedMessage());

				cout << "------ Buttons ------" << endl;
				cout << " Button_0 : " << wrapper.GetBool("button_0") << endl;
				cout << "---------------------" << endl << endl;

				cout << "--- Accelerometer ---" << endl;
				//cout << " Accelerometer : " << wrapper.GetObject("accelerometer").at(U("x")).as_double() << endl;
				cout << "---------------------" << endl;

				system("cls");
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

