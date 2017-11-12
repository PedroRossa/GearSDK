#include "cpp_Wrapper.h"

#pragma region Constructors

cpp_Wrapper::cpp_Wrapper()
{
	this->buttons = new vector<Gear_Button_cpp*>();
	this->potentiometers = new vector<Gear_Potentiometer_cpp*>();
	this->mpus = new vector<Gear_MPU6050_cpp*>();
	this->rgbLeds = new vector<Gear_RGBLed_cpp*>();
}

cpp_Wrapper::~cpp_Wrapper()
{
}

#pragma endregion

#pragma region Private Methods

void cpp_Wrapper::CreateButton(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonButton = this->jsonValue.at(U("button"));

		string name = utility::conversions::to_utf8string(jsonButton.at(U("name")).as_string());
		string pin = utility::conversions::to_utf8string(jsonButton.at(U("pin")).as_string());
		int state = jsonButton.at(U("state")).as_integer();
		int type = jsonButton.at(U("type")).as_integer();

		Gear_Button_cpp* btn = new Gear_Button_cpp(this->buttons->size(), name, pin, state, type);

		this->buttons->push_back(btn);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::CreatePotentiometer(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonPot = this->jsonValue.at(U("potentiometer"));

		string name = utility::conversions::to_utf8string(jsonPot.at(U("name")).as_string());
		string pin = utility::conversions::to_utf8string(jsonPot.at(U("pin")).as_string());
		int value = jsonPot.at(U("value")).as_integer();

		Gear_Potentiometer_cpp* pot = new Gear_Potentiometer_cpp(this->buttons->size(), name, pin, value);
		this->potentiometers->push_back(pot);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::CreateRGBLed(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonRGBLed = this->jsonValue.at(U("rgb_led"));
		string name = utility::conversions::to_utf8string(jsonRGBLed.at(U("name")).as_string());
		string pin = utility::conversions::to_utf8string(jsonRGBLed.at(U("pin")).as_string());
		int mode = jsonRGBLed.at(U("mode")).as_integer();


		auto vals = jsonRGBLed.at(U("value")).as_object();
		int i_vals[3] = { 0,0,0 };

		i_vals[0] = vals.at(U("r")).as_integer();
		i_vals[1] = vals.at(U("g")).as_integer();
		i_vals[2] = vals.at(U("b")).as_integer();

		vector<string> pins = split(pin, ",");

		string pin_r = pins[0];
		string pin_g = pins[1];
		string pin_b = pins[2];

		Gear_RGBLed_cpp* rgbLed = new Gear_RGBLed_cpp(this->rgbLeds->size(), name, pin_r, pin_g, pin_b, mode, i_vals[0], i_vals[1], i_vals[2]);
		this->rgbLeds->push_back(rgbLed);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::CreateMpu(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonMPU = this->jsonValue.at(U("mpu"));
		string name = utility::conversions::to_utf8string(jsonMPU.at(U("name")).as_string());
		string pin = utility::conversions::to_utf8string(jsonMPU.at(U("pins")).as_string());

		vector<string> pins = split(pin, ",");
		string pin_sda = pins[0];
		string pin_scl = pins[1];

		auto accel_vals = jsonMPU.at(U("accel")).as_object();
		int accel[3] = { 0,0,0 };

		accel[0] = accel_vals.at(U("x")).as_integer();
		accel[1] = accel_vals.at(U("y")).as_integer();
		accel[2] = accel_vals.at(U("z")).as_integer();

		auto gyro_vals = jsonMPU.at(U("gyro")).as_object();
		int gyro[3] = { 0,0,0 };

		gyro[0] = gyro_vals.at(U("x")).as_integer();
		gyro[1] = gyro_vals.at(U("y")).as_integer();
		gyro[2] = gyro_vals.at(U("z")).as_integer();

		auto angle_vals = jsonMPU.at(U("angle")).as_object();
		double angle[3] = { 0,0,0 };

		angle[0] = angle_vals.at(U("x")).as_double();
		angle[1] = angle_vals.at(U("y")).as_double();
		angle[2] = angle_vals.at(U("z")).as_double();

		Gear_MPU6050_cpp* mpu6050 = new Gear_MPU6050_cpp(this->mpus->size(), name, pin_sda, pin_scl, accel, gyro, angle);
		this->mpus->push_back(mpu6050);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}


void cpp_Wrapper::UpdateButton(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;
	
	try
	{
		auto jsonButton = this->jsonValue.at(U("button"));

		string objName = utility::conversions::to_utf8string(jsonButton.at(U("name")).as_string());
		int state = jsonButton.at(U("state")).as_integer();

		for (size_t i = 0; i < this->buttons->size(); i++)
		{
			string name = this->buttons->at(i)->GetName();
			if (name == objName)
			{
				this->buttons->at(i)->SetState((bool)state);
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::UpdatePotentiometer(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonPotentiometer = this->jsonValue.at(U("potentiometer"));

		string objName = utility::conversions::to_utf8string(jsonPotentiometer.at(U("name")).as_string());
		int value = jsonPotentiometer.at(U("value")).as_integer();

		for (size_t i = 0; i < this->potentiometers->size(); i++)
		{
			string name = this->potentiometers->at(i)->GetName();
			if (name == objName)
			{
				this->potentiometers->at(i)->SetValue(value);
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::UpdateRGBLed(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonRgbLed = this->jsonValue.at(U("rgb_led"));

		string objName = utility::conversions::to_utf8string(jsonRgbLed.at(U("name")).as_string());
		auto value = jsonRgbLed.at(U("value")).as_object();
		int color[3] = { 0,0,0 };

		color[0] = value.at(U("r")).as_integer();
		color[1] = value.at(U("g")).as_integer();
		color[2] = value.at(U("b")).as_integer();

		int mode = jsonRgbLed.at(U("mode")).as_integer();

		for (size_t i = 0; i < this->rgbLeds->size(); i++)
		{
			string name = this->rgbLeds->at(i)->GetName();
			if (name == objName)
			{
				this->rgbLeds->at(i)->SetMode((LedMode)mode);
				this->rgbLeds->at(i)->SetRGB_Value(color);
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::UpdateMpu(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue == NULL)
		return;

	try
	{
		auto jsonMpu = this->jsonValue.at(U("mpu"));
				
		string objName = utility::conversions::to_utf8string(jsonMpu.at(U("name")).as_string());

		int accel[3] = { 0,0,0 };
		int gyro[3] = { 0,0,0 };
		double angle[3] = { 0,0,0 };

		auto accel_vals = jsonMpu.at(U("accel")).as_object();;
		accel[0] = accel_vals.at(U("x")).as_integer();
		accel[1] = accel_vals.at(U("y")).as_integer();
		accel[2] = accel_vals.at(U("z")).as_integer();

		auto gyro_vals = jsonMpu.at(U("gyro")).as_object();;
		gyro[0] = gyro_vals.at(U("x")).as_integer();
		gyro[1] = gyro_vals.at(U("y")).as_integer();
		gyro[2] = gyro_vals.at(U("z")).as_integer();

		auto angle_vals = jsonMpu.at(U("angle")).as_object();;
		angle[0] = angle_vals.at(U("x")).as_double();
		angle[1] = angle_vals.at(U("y")).as_double();
		angle[2] = angle_vals.at(U("z")).as_double();

		
		for (size_t i = 0; i < this->mpus->size(); i++)
		{
			string name = this->mpus->at(i)->GetName();
			if (name == objName)
			{
				//TODO: SOLVE PROBLEM ON GET VALUES FROM MPU
				//this->mpus->at(i)->SetAccelValues(accel);
				//this->mpus->at(i)->SetGyroValues(gyro);
				//this->mpus->at(i)->SetAngleValues(angle);
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

#pragma endregion

#pragma region Gets and Sets

bool cpp_Wrapper::HeaderSetted() { return this->headerSetted; }

void cpp_Wrapper::SetData(string data) { this->data = data; }
string cpp_Wrapper::GetData() { return this->data; }

Gear_Button_cpp* cpp_Wrapper::GetButton(int id) { return this->buttons->at(id); }
Gear_Potentiometer_cpp* cpp_Wrapper::GetPotentiometer(int id) { return this->potentiometers->at(id); }
Gear_RGBLed_cpp* cpp_Wrapper::GetRGBLed(int id) { return this->rgbLeds->at(id); }
Gear_MPU6050_cpp* cpp_Wrapper::GetMPU6050(int id) { return this->mpus->at(id); }

#pragma endregion

#pragma region Public Methods

json::value cpp_Wrapper::StringToJson(string data)
{
	json::value json;

	try
	{
		string_t t_data = conversions::to_string_t(data);
		json = json::value::parse(t_data);
	}
	catch (const std::exception& e)
	{
		cout << "problem on Json Parser: " << e.what() << endl;
		return NULL;
	}
	return json;
}

string cpp_Wrapper::JsonToString(json::value json)
{
	stringstream_t s_data;
	string dataValue;
	try
	{
		s_data << json;
		dataValue = conversions::to_utf8string(s_data.str());
	}
	catch (const std::exception& e)
	{
		cout << "problem on Parse Json to Data: " << e.what() << endl;
		return "";
	}
	return dataValue;
}

void cpp_Wrapper::Init(string header)
{	
	try
	{
		vector<string> jsons = split(header, "#");
		
		if (jsons.size() <= 0)
			return;

		if (jsons[0] == "header") //if it's a data message
		{
			for (int i = 1; i < jsons.size(); i++)
			{
				if (jsons[i].find("button") != std::string::npos)
					CreateButton(jsons[i]);
				else if (jsons[i].find("potentiometer") != std::string::npos)
					CreatePotentiometer(jsons[i]);
				else if (jsons[i].find("rgb_led") != std::string::npos)
					CreateRGBLed(jsons[i]);
				else if (jsons[i].find("mpu") != std::string::npos)
					CreateMpu(jsons[i]);
			}

			this->headerSetted = true;
		}
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void cpp_Wrapper::UpdateObjects(string data)
{
		try
		{
			vector<string> jsons = split(data, "#");

			if (jsons.size() <= 0)
				return;

			if (jsons[0] == "data") //if it's a data message
			{
				for (int i = 1; i < jsons.size(); i++)
				{
					if (jsons[i].find("button") != std::string::npos)
						UpdateButton(jsons[i]);
					else if (jsons[i].find("potentiometer") != std::string::npos)
						UpdatePotentiometer(jsons[i]);
					else if (jsons[i].find("rgb_led") != std::string::npos)
						UpdateRGBLed(jsons[i]);
					else if (jsons[i].find("mpu") != std::string::npos)
						UpdateMpu(jsons[i]);
				}
			}
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
}

#pragma endregion