#ifndef Cpp_Connection_H
#define Cpp_Connection_H

#include <cpprest/ws_client.h>
#include <iostream>
#include <ctime>

using namespace web;
using namespace web::websockets::client;
using namespace std;

class cpp_Connection
{
private:
	string hardwareIP;
	int port;


	websocket_callback_client wsClient;
	websocket_outgoing_message wsOutMessage;

	string message;
	string receivedMessage;

	int messageCounter = 0;
	bool isConnected = false;

	void SetReceivedMessage(string message);

public:
	cpp_Connection();
	cpp_Connection(string ip, int port = 81);
	~cpp_Connection();

#pragma region Getters and Setters

	string GetIP();
	int GetPort();

	int GetNumberOfMessagesReceived();

	void SetIP(string ip);
	void SetPort(int port);

#pragma endregion

	web::uri ConnectionAddress();

	bool Connect(string initialMessage="Hello Hardware i'm the C++ =P !!!");
	void Disconnect(string byebyeMessage = "Bye bye my Hard Friend");

	bool IsConnected();

	bool SendMessage(string message);

	string ReceivedMessage();


};

#endif