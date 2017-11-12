#ifndef Cpp_Client_H
#define Cpp_Client_H

#include <chrono>
#include <thread>

#include "cpp_Connection.h"
#include "cpp_Wrapper.h"

class Cpp_Client
{
private:

#pragma region Private Attributes

	int atualNumberOfMessages = 0;
	bool handShakeDone = false;
	bool canUpdateObjects = false;

#pragma endregion

#pragma region Private Methods

	void HandShakeWithServer();

#pragma endregion

public:

#pragma region Public Attributes

	cpp_Connection connection;
	cpp_Wrapper wrapper;

#pragma endregion

#pragma region Constructors

	Cpp_Client();
	Cpp_Client(string ip, int port = 81);
	~Cpp_Client();

#pragma endregion

#pragma region Getters and Setters

	int GetAtualNumberOfMessages();
	bool HandShakeIsDone();
	bool CanUpdateObjects();

	void SetAtualNumberOfMessages(int value);
	void HandShakeIsDone(bool handShakeIsDone);

#pragma endregion

#pragma region Public Methods

	void Init();
	void Update();

#pragma endregion

};

#endif

