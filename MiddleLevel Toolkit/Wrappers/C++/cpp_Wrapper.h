#ifndef CPP_WRAPPER_H
#define CPP_WRAPPER_H

#include <cpprest/json.h>
#include <iostream>

using namespace std;
using namespace web;
using namespace utility;

class cpp_Wrapper
{
	string data;
	json::value jsonValue;

	bool ParseDataToJson();

public:
	cpp_Wrapper();
	~cpp_Wrapper();

	void SetData(string data);
	string GetData();

	bool GetBool(string key);
	int GetInt(string key);
	float GetFloat(string key);
	string GetString(string key);
	json::object GetObject(string key);
	
};

#endif
