#include "cpp_Wrapper.h"

#pragma region Constructors

cpp_Wrapper::cpp_Wrapper()
{
}

cpp_Wrapper::~cpp_Wrapper()
{
}

#pragma endregion

#pragma region Private Methods

bool cpp_Wrapper::ParseDataToJson()
{
	try
	{
		string_t t_data = conversions::to_string_t(this->data);
		this->jsonValue = json::value::parse(t_data);
	}
	catch (const std::exception& e)
	{
		cout << "problem on Json Parser: " << e.what() << endl;
		return false;
	}
	return true;
}

#pragma endregion

#pragma region Getters and Setters

void cpp_Wrapper::SetData(string data) { this->data = data; }
string cpp_Wrapper::GetData() { return this->data; }

#pragma endregion

#pragma region Public Methods

bool cpp_Wrapper::GetBool(string key)
{
	if (ParseDataToJson())
	{
		string_t t_key = conversions::to_string_t(key);
		
		try
		{
			auto val = this->jsonValue.at(U("data"));
			bool b_val = val.at(t_key).as_integer();
			return b_val;
		}
		catch (const std::exception&)
		{
			return NULL;
		}
	}
	return NULL;
}

int cpp_Wrapper::GetInt(string key)
{
	if (ParseDataToJson())
	{
		string_t t_key = conversions::to_string_t(key);
		
		try
		{
			auto val = this->jsonValue.at(U("data"));
			int i_val = val.at(t_key).as_integer();
			return i_val;
		}
		catch (const std::exception&)
		{
			return NULL;
		}
	}
	return NULL;
}

float cpp_Wrapper::GetFloat(string key)
{
	if (ParseDataToJson())
	{
		string_t t_key = conversions::to_string_t(key);
		
		try
		{
			auto val = this->jsonValue.at(U("data"));
			auto f_val = val.at(t_key).as_double();
			return f_val;
		}
		catch (const std::exception&)
		{
			return NULL;
		}
	}
	return NULL;
}

string cpp_Wrapper::GetString(string key)
{
	if (ParseDataToJson())
	{
		string_t t_key = conversions::to_string_t(key);
		try
		{
			auto val = this->jsonValue.at(U("data"));
			auto s_val = val.at(t_key).as_string();
			return conversions::to_utf8string(s_val);
		}
		catch (const std::exception&)
		{
			return NULL;
		}
	}
	return NULL;
}

json::object cpp_Wrapper::GetObject(string key)
{
	if (ParseDataToJson())
	{
		string_t t_key = conversions::to_string_t(key);

		try
		{
			auto val = this->jsonValue.at(U("data"));
			auto o_val = val.at(t_key).as_object();
			return o_val;
		}
		catch (const std::exception&)
		{
		}
	}
}

#pragma endregion