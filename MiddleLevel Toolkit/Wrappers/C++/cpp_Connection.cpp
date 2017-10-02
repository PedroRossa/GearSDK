#include "cpp_Connection.h"

#pragma region Constructors

cpp_Connection::cpp_Connection()
{
}	

cpp_Connection::cpp_Connection(string ip, int port)
{
	this->hardwareIP = ip;
	this->port = port;
}

cpp_Connection::~cpp_Connection()
{
}

#pragma endregion

#pragma region Private Methods

void cpp_Connection::SetReceivedMessage(string message)
{
	this->receivedMessage = message;
}

#pragma endregion

#pragma region Getters and Setters

string cpp_Connection::GetIP() { return this->hardwareIP; }
int cpp_Connection::GetPort() { return this->port; }

int cpp_Connection::GetNumberOfMessagesReceived() { return this->messageCounter; }

void cpp_Connection::SetIP(string ip) { this->hardwareIP = ip; }
void cpp_Connection::SetPort(int port) { this->port = port; }

#pragma endregion

#pragma region Public Methods

web::uri cpp_Connection::ConnectionAddress()
{
	//concat values to mount the string to connection
	string conn = "ws://" + hardwareIP + ":" + to_string(port);
	utility::string_t utilityConn = utility::conversions::to_string_t(conn);

	return web::uri(utilityConn);
}

bool cpp_Connection::Connect(string initialMessage)
{
	web::uri conn = ConnectionAddress();
	int messageCounter = 0;

	this->message = initialMessage;
	try
	{
		//Connect with the WebServer
		wsClient.connect(conn).then([this]()
		{
			cout << "DEBUG: Connected with the Hardware \o\ |o| /o/! " << endl;

			this->wsOutMessage.set_utf8_message(this->message);

			wsClient.send(this->wsOutMessage).then([this]()
			{
				/* Successfully sent the message. */
				cout << "Me: " << this->message << endl;
			});

		}).wait();

		isConnected = true;

		// set receive handler
		wsClient.set_message_handler([this](websocket_incoming_message msg)
		{
			this->receivedMessage = msg.extract_string().get();
			//cout << messageCounter << " Server: " << receivedMessage << endl;

			this->messageCounter++;
		});

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void cpp_Connection::Disconnect(string byebyeMessage)
{
	wsClient.close().then([this]() 
	{ 
		/* Successfully closed the connection. */ 
		cout << "Oh, it's so Sad, but we are alone now :( " << endl;

		this->isConnected = false;
	});
}

bool cpp_Connection::IsConnected()
{
	return isConnected;
}

bool cpp_Connection::SendMessage(string message)
{
	wsOutMessage.set_utf8_message(message);

	try
	{
		wsClient.send(wsOutMessage).then([]()
		{
			//Message sent succefuly!

		}).wait();

		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}	

string cpp_Connection::ReceivedMessage()
{
	return receivedMessage;
}

bool cpp_Connection::StablishConnection()
{
	//Connect to WebServer
	while (!this->isConnected)
	{
		//Check for succesful connection
		if (this->Connect())
			this->SendMessage("Server we are soooo connected!!! <3 ");
		else
		{
			cout << "some problem with connection occours!" << endl << endl;
			system("pause");
			return false;
		}
	}
	return true;
}

#pragma endregion