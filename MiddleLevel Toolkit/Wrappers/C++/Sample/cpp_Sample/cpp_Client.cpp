#include "cpp_Client.h"

#pragma region Constructors

cpp_Client::cpp_Client()
{
}

cpp_Client::cpp_Client(string serverIP, int port)
{
	connection = cpp_Connection(serverIP, port);
	wrapper = cpp_Wrapper();

	this->numberOfMessagesReceived = 0;
	this->handShakeDone = false;
}

cpp_Client::~cpp_Client()
{
}

#pragma endregion


#pragma region Private Methods

void cpp_Client::TryHandShakeWithServer()
{
	while (!wrapper.HeaderSetted())
		wrapper.Init(connection.ReceivedMessage());

	if (!handShakeDone)
	{
		connection.SendMessage("@ Hand Shake");
		handShakeDone = true;
	}
}

#pragma endregion

#pragma region Getters and Setters

int cpp_Client::NumberOfMessagesReceived() { return this->numberOfMessagesReceived; }
bool cpp_Client::HandShakeDone() { return this->handShakeDone; }

#pragma endregion

#pragma region Public Methods

void cpp_Client::Init()
{
	try
	{
		//Garantee the connection with the webServer
		if (!connection.StablishConnection())
			return;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

void cpp_Client::Update()
{
	try
	{
		//while connected with the server, try read messages
		if (connection.IsConnected())
		{
			if (!handShakeDone)
				TryHandShakeWithServer(); //Loop until handshake done!
			else
			{
				//If the number of connection messages grether then localCounter, it's a new message
				//if (connection.GetNumberOfMessagesReceived() > numberOfMessagesReceived)
				//{
 					numberOfMessagesReceived = connection.GetNumberOfMessagesReceived();
					wrapper.UpdateObjects(connection.ReceivedMessage());
				//}
			}
		}
		else
		{
			cout << "Lost connection!" << endl;
			system("pause");
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		system("pause");
	}
}

#pragma endregion