#ifndef cpp_Client_H
#define cpp_Client_H

#include "../../cpp_Connection.h"
#include "../../cpp_Wrapper.h"

class cpp_Client
{

private:

#pragma region Attributes

	int numberOfMessagesReceived;
	bool handShakeDone;

#pragma endregion

#pragma region Private Methods

	void TryHandShakeWithServer();

#pragma endregion

public:

	cpp_Connection connection;
	cpp_Wrapper wrapper;

#pragma region Constructors

	cpp_Client();
	cpp_Client(string serverIP, int port);
	~cpp_Client();

#pragma endregion

#pragma region Getters and Setters

	int NumberOfMessagesReceived();

	bool HandShakeDone();

#pragma endregion

#pragma region Public Methods

	void Init();

	void Update();

#pragma endregion

};

#endif
