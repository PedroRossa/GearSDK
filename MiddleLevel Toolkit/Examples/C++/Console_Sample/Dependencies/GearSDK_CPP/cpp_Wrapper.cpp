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

Gear_Button_cpp* cpp_Wrapper::CreateButton(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pin")).as_string());
	int state = values.at(U("state")).as_integer();
	int type = values.at(U("type")).as_integer();

	Gear_Button_cpp* btn = new Gear_Button_cpp(this->buttons->size(), name, pin, state, type);

	return btn;
}

Gear_Potentiometer_cpp* cpp_Wrapper::CreatePotentiometer(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pin")).as_string());
	int value = values.at(U("value")).as_integer();

	Gear_Potentiometer_cpp* pot = new Gear_Potentiometer_cpp(this->buttons->size(), name, pin, value);

	return pot;
}

Gear_RGBLed_cpp* cpp_Wrapper::CreateRGBLed(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pin")).as_string());
	int mode = values.at(U("mode")).as_integer();


	auto vals = values.at(U("value")).as_object();
	int i_vals[3] = { 0,0,0 };

	i_vals[0] = vals.at(U("r")).as_integer();
	i_vals[1] = vals.at(U("g")).as_integer();
	i_vals[2] = vals.at(U("b")).as_integer();

	vector<string> pins = split(pin, ",");

	string pin_r = pins[0];
	string pin_g = pins[1];
	string pin_b = pins[2];

	Gear_RGBLed_cpp* rgbLed = new Gear_RGBLed_cpp(this->rgbLeds->size(), name, pin_r, pin_g, pin_b, mode, i_vals[0], i_vals[1], i_vals[2]);

	return rgbLed;
}

Gear_MPU6050_cpp* cpp_Wrapper::CreateMPU6050(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pins")).as_string());
	
	vector<string> pins = split(pin, ",");
	string pin_sda = pins[0];
	string pin_scl = pins[1];

	auto accel_vals = values.at(U("accel")).as_object();
	int accel[3] = { 0,0,0 };

	accel[0] = accel_vals.at(U("x")).as_integer();
	accel[1] = accel_vals.at(U("y")).as_integer();
	accel[2] = accel_vals.at(U("z")).as_integer();

	auto gyro_vals = values.at(U("gyro")).as_object();
	int gyro[3] = { 0,0,0 };

	gyro[0] = gyro_vals.at(U("x")).as_integer();
	gyro[1] = gyro_vals.at(U("y")).as_integer();
	gyro[2] = gyro_vals.at(U("z")).as_integer();

	auto angle_vals = values.at(U("angle")).as_object();
	double angle[3] = { 0,0,0 };

	angle[0] = angle_vals.at(U("x")).as_double();
	angle[1] = angle_vals.at(U("y")).as_double();
	angle[2] = angle_vals.at(U("z")).as_double();

	Gear_MPU6050_cpp* mpu6050 = new Gear_MPU6050_cpp(this->mpus->size(), name, pin_sda, pin_scl, accel, gyro, angle);

	return mpu6050;
}

#pragma endregion

#pragma region Getters and Setters

bool cpp_Wrapper::HeaderSetted() { return this->headerSetted; }


void cpp_Wrapper::SetData(string data) { this->data = data; }
string cpp_Wrapper::GetData() { return this->data; }


Gear_Button_cpp* cpp_Wrapper::GetButton(int id) { return this->buttons->at(id); }
Gear_Potentiometer_cpp* cpp_Wrapper::GetPotentiometer(int id) { return this->potentiometers->at(id); }
Gear_RGBLed_cpp* cpp_Wrapper::GetRGBLed(int id) { return this->rgbLeds->at(id); }
Gear_MPU6050_cpp* cpp_Wrapper::GetMPU6050(int id) { return this->mpus->at(id); }


void cpp_Wrapper::SetRGBLed(int id, Gear_RGBLed_cpp* newObj) { this->rgbLeds->at(id) = newObj; }

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
	//TODO: FALTA FAZER O RESTO DOS ELEMENTOS
	// ATUALMENTE JA TEM BOTAO E RGBLED

	/* Header Reference
	{
  "header": {
    "buttons": [
      {
        "name": "button_0",
        "pin": "D2",
        "state": false,
        "type" : "PUSH_BUTTON"
      },
      {
        "name": "button_1",
        "pin": "D3",
        "state": false,
        "type" : "PUSH_BUTTON"
      }
    ],
    "rgb_leds": [
      {
        "name": "rgb_led_0",
        "pin": "D3,D4,D5",
        "mode": "BLINKING",
        "value": {
          "r": 0,
          "g": 1023,
          "b": 0
        }
      }
    ],
    "leds": [
      {
        "name": "led_0",
        "pin": "D8",
        "value": 1
      },
      {
        "name": "led_1",
        "pin": "D9",
        "mode": "STATIC",
        "value": 0
      }
    ],
    "accelerometer": {
      "name": "accelerometer_0",
      "pins": "D6,D7",
      "value": {
        "x": 0,
        "y": 0,
        "z": 0
      }
    },
    "gyroscope": {
      "id": "gyroscope_0",
      "pin": "D6,D7",
      "value": {
        "x": 0,
        "y": 0,
        "z": 0,
        "w": 0
      }
    }
  }
}
	*/
	
	if (header[0] == '{') //if it's probably a json
	{
		this->header = StringToJson(header);

		if (this->header != NULL)
		{
			try
			{
				auto data = this->header.at(U("header"));

				this->headerSetted = true;

				try
				{
					//-------- buttons ------------
					string_t t_key = conversions::to_string_t("buttons");

					json::array buttons = data.at(t_key).as_array();

					for (size_t i = 0; i < buttons.size(); i++)
						this->buttons->push_back(CreateButton(buttons[i]));
					//-----------------------------


					//-------- potentiometers ------------
					t_key = conversions::to_string_t("potentiometers");

					json::array pots = data.at(t_key).as_array();

					for (size_t i = 0; i < pots.size(); i++)
						this->potentiometers->push_back(CreatePotentiometer(pots[i]));
					//------------------------------------

					//-------- rgb leds ------------
					t_key = conversions::to_string_t("rgb_leds");

					json::array rgbLeds = data.at(t_key).as_array();

					for (size_t i = 0; i < rgbLeds.size(); i++)
						this->rgbLeds->push_back(CreateRGBLed(rgbLeds[i]));
					//------------------------------

					//--------- mpu6050 ------------
					t_key = conversions::to_string_t("mpus");

					json::array mpus = data.at(t_key).as_array();

					for (size_t i = 0; i < mpus.size(); i++)
						this->mpus->push_back(CreateMPU6050(mpus[i]));
					//------------------------------
				}
				catch (const std::exception& e)
				{
					cout << "Exception: " << e.what() << " OR don't have buttons" << endl;
				}
			}
			catch (const std::exception& e)
			{
				cout << "Exception: " << e.what() << endl;
			}
		}
	}
}

void cpp_Wrapper::UpdateObjects(string data)
{
	this->jsonValue = StringToJson(data);

	if (this->jsonValue != NULL)
	{
		try
		{
			auto data = this->jsonValue.at(U("data"));
			try
			{
				string_t t_key = conversions::to_string_t("buttons");

				json::array data_buttons = data.at(t_key).as_array();

				for (size_t i = 0; i < this->buttons->size(); i++)
				{
					string btn_state = "state";
					string_t key = conversions::to_string_t(btn_state);

					int state = data_buttons[i].at(key).as_integer();
					this->buttons->at(i)->SetState((bool)state);
				}
				//--------------------------------------------------

				t_key = conversions::to_string_t("potentiometers");

				json::array data_pots = data.at(t_key).as_array();

				for (size_t i = 0; i < this->potentiometers->size(); i++)
				{
					string pot_value = "value";
					string_t key = conversions::to_string_t(pot_value);

					int value = data_pots[i].at(key).as_integer();
					this->potentiometers->at(i)->SetValue(value);
				}

				//--------------------------------------------------

				t_key = conversions::to_string_t("mpus");

				json::array data_mpus = data.at(t_key).as_array();

				for (size_t i = 0; i < this->mpus->size(); i++)
				{
					string str_accel = "accel";
					string_t key = conversions::to_string_t(str_accel);
					
					auto accel_vals = data_mpus[i].at(key).as_object();
					int accel[3] = { 0,0,0 };

					accel[0] = accel_vals.at(U("x")).as_integer();
					accel[1] = accel_vals.at(U("y")).as_integer();
					accel[2] = accel_vals.at(U("z")).as_integer();

					auto gyro_vals = data_mpus[i].at(U("gyro")).as_object();
					int gyro[3] = { 0,0,0 };

					gyro[0] = gyro_vals.at(U("x")).as_integer();
					gyro[1] = gyro_vals.at(U("y")).as_integer();
					gyro[2] = gyro_vals.at(U("z")).as_integer();

					auto angle_vals = data_mpus[i].at(U("angle")).as_object();
					double angle[3] = { 0,0,0 };

					angle[0] = angle_vals.at(U("x")).as_double();
					angle[1] = angle_vals.at(U("y")).as_double();
					angle[2] = angle_vals.at(U("z")).as_double();

					this->mpus->at(i)->SetAccelValues(accel);
					this->mpus->at(i)->SetGyroValues(gyro);
					this->mpus->at(i)->SetAngleValues(angle);
				}

				/*{
				"name": "rgb_led_0",
				"pin" : "D3,D4,D5",
				"mode" : "BLINKING",
				"value" : {
				"r": 0,
				"g" : 1023,
				"b" : 0
				}*/

			}
			catch (const std::exception& e)
			{
				cout << "Exception: " << e.what() << endl;
			}

		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}
}

#pragma endregion