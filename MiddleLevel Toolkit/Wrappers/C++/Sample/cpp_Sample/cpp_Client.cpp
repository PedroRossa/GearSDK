#include "Cpp_Client.h"

#pragma region Constructors

Cpp_Client::Cpp_Client()
{
}

Cpp_Client::Cpp_Client(string ip, int port)
{
	this->connection = cpp_Connection(ip, port);
	this->wrapper = cpp_Wrapper();
}

Cpp_Client::~Cpp_Client()
{
}

#pragma endregion

#pragma region Getters and Setters

int Cpp_Client::GetAtualNumberOfMessages() { return this->atualNumberOfMessages; }
bool Cpp_Client::HandShakeIsDone() { return this->handShakeDone; }
bool Cpp_Client::CanUpdateObjects() { return this->canUpdateObjects; }

void Cpp_Client::SetAtualNumberOfMessages(int value) { this->atualNumberOfMessages = value; }
void Cpp_Client::HandShakeIsDone(bool handShakeIsDone) { this->handShakeDone = handShakeDone; }

#pragma endregion

#pragma region Private Methods

void Cpp_Client::HandShakeWithServer()
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

#pragma region Public Methods

void Cpp_Client::Init()
{
	try
	{
		//Connect to WebServer
		if (!connection.IsConnected())
		{
			//Check for succesful connection
			if (connection.Connect())
				connection.SendMessage("Server we are soooo connected!!! <3 ");
			else
			{
				cout << "some problem with connection occours!" << endl << endl;
				system("pause");
				return;
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

}

void Cpp_Client::Update()
{
	try
	{
		//while connected with the server, try read messages
		if (connection.IsConnected())
		{
			if (!handShakeDone)
				HandShakeWithServer(); //Loop until handshake done!

			//If the number of connection messages grether then localCounter, it's a new message
			if (connection.GetNumberOfMessagesReceived() > atualNumberOfMessages)
			{
				atualNumberOfMessages = connection.GetNumberOfMessagesReceived();

				wrapper.UpdateObjects(connection.ReceivedMessage());
				canUpdateObjects = true;
			}
			else
				canUpdateObjects = false;

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
}

#pragma endregion