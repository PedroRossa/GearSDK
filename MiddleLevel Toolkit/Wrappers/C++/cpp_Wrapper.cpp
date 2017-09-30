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

Gear_Button_cpp cpp_Wrapper::CreateButton(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pin")).as_string());
	bool state = values.at(U("state")).as_bool();
	string type = utility::conversions::to_utf8string(values.at(U("type")).as_string());

	ButtonType btn_type = ButtonTypesMap[type];

	Gear_Button_cpp btn(this->buttons.size(), name, pin, state, btn_type);

	return btn;
}

Gear_RGBLed_cpp cpp_Wrapper::CreateRGBLed(json::value values)
{
	string name = utility::conversions::to_utf8string(values.at(U("name")).as_string());
	string pin = utility::conversions::to_utf8string(values.at(U("pin")).as_string());

	string mode = utility::conversions::to_utf8string(values.at(U("mode")).as_string());
	LedMode led_mode = LedModesMap[mode];


	auto vals = values.at(U("value")).as_object();
	int i_vals[3] = { 0,0,0 };

	i_vals[0] = vals.at(U("r")).as_integer();
	i_vals[1] = vals.at(U("g")).as_integer();
	i_vals[2] = vals.at(U("b")).as_integer();



	vector<string> pins = split(pin, ",");

	string pin_r = pins[0];
	string pin_g = pins[1];
	string pin_b = pins[2];

	Gear_RGBLed_cpp rgbLed(this->rgbLeds.size(), name, pin_r, pin_g, pin_b, led_mode, i_vals[0], i_vals[1], i_vals[2]);

	return rgbLed;
}

#pragma endregion

#pragma region Getters and Setters

bool cpp_Wrapper::HeaderSetted() { return this->headerSetted; }


void cpp_Wrapper::SetData(string data) { this->data = data; }
string cpp_Wrapper::GetData() { return this->data; }


Gear_Button_cpp cpp_Wrapper::GetButton(int id) { return this->buttons[id]; }
Gear_RGBLed_cpp cpp_Wrapper::GetRGBLed(int id) { return this->rgbLeds[id]; }


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
	
	this->header = StringToJson(header);

	if (this->header != NULL)
	{
		try
		{
			auto data = this->header.at(U("header"));

			this->headerSetted = true;

			try
			{
				/*{
					"name": "button_0",
					"pin" : "D2",
					"state" : false,
					"type" : 0
				}*/
				string_t t_key = conversions::to_string_t("buttons");

				json::array buttons = data.at(t_key).as_array();

				for (size_t i = 0; i < buttons.size(); i++)
					this->buttons.push_back(CreateButton(buttons[i]));

				/*{
					"name": "rgb_led_0",
						"pin" : "D3,D4,D5",
						"mode" : "BLINKING",
						"value" : {
						"r": 0,
							"g" : 1023,
							"b" : 0
					}*/
				t_key = conversions::to_string_t("rgb_leds");

				json::array rgbLeds = data.at(t_key).as_array();

				for (size_t i = 0; i < rgbLeds.size(); i++)
					this->rgbLeds.push_back(CreateRGBLed(rgbLeds[i]));
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

void cpp_Wrapper::UpdateObjects(string data)
{
	//TODO: FAZER AQUI O UPDATE DOS OBJETOS CRIADOS, A PARTIR DO JSON RECEBIDO POR WEBSOCKET
	// PRECISA MUDAR O FORMATO DO JSON QUE EH ENVIADO COM O DATA VALUE
	// ELE TEM QUE CONTAR TODOS OS OBJETOS DENTRO DE ARRAYS E COM TODOS OS DADOS CRUCIAIS

	this->jsonValue = StringToJson(data);

	if (this->jsonValue != NULL)
	{
		try
		{
			auto data = this->jsonValue.at(U("data"));
			try
			{
				/*{
					"name": "button_0",
					"pin": "D2",
					"state": false,
					"type" : "PUSH_BUTTON"
				},*/
				string_t t_key = conversions::to_string_t("buttons");

				json::array data_buttons = data.at(t_key).as_array();

				for (size_t i = 0; i < this->buttons.size(); i++)
				{
					string btnPath = "button_" + to_string(i);
					string_t btns = conversions::to_string_t(btnPath);

					bool state = data_buttons[i].at(btns).as_bool();
					this->buttons[i].SetState(state);
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