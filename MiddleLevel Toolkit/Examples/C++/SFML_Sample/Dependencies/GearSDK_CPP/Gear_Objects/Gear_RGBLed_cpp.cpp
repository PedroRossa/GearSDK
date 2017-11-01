#include "Gear_RGBLed_cpp.h"

#pragma region Constructors

Gear_RGBLed_cpp::Gear_RGBLed_cpp()
{
}

Gear_RGBLed_cpp::Gear_RGBLed_cpp(int id, string name, string pin_r, string pin_g, string pin_b, int mode, int r_value, int g_value, int b_value, int timeOn, int timeOff)
{
	this->id = id;
	this->name = name;

	this->pin_r = pin_r;
	this->pin_g = pin_g;
	this->pin_b = pin_b;

	this->mode = mode;
	this->timeOn = timeOn;
	this->timeOff = timeOff;

	this->r_value = r_value;
	this->g_value = g_value;
	this->b_value = b_value;
}

Gear_RGBLed_cpp::~Gear_RGBLed_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_RGBLed_cpp::GetId() { return this->id; }

string Gear_RGBLed_cpp::GetName() { return this->name; }
string Gear_RGBLed_cpp::Get_R_Pin() { return this->pin_r; }
string Gear_RGBLed_cpp::Get_G_Pin() { return this->pin_g; }
string Gear_RGBLed_cpp::Get_B_Pin() { return this->pin_b; }

int Gear_RGBLed_cpp::GetMode() { return this->mode; }

int Gear_RGBLed_cpp::Get_R_Value() { return this->r_value; }
int Gear_RGBLed_cpp::Get_G_Value() { return this->g_value; }
int Gear_RGBLed_cpp::Get_B_Value() { return this->b_value; }

int* Gear_RGBLed_cpp::GetRGB_Value() 
{
	int vals[3] = { 0,0,0 };

	vals[0] = this->r_value;
	vals[1] = this->g_value;
	vals[2] = this->b_value;

	return vals;
}


void Gear_RGBLed_cpp::SetMode(LedMode mode, int timeOn, int timeOff) 
{ 
	this->mode = mode; 
	this->timeOn = timeOn;
	this->timeOff = timeOff;
};

void Gear_RGBLed_cpp::Set_R_Value(int r_value) { this->r_value = r_value; }
void Gear_RGBLed_cpp::Set_G_Value(int g_value) { this->g_value = g_value; }
void Gear_RGBLed_cpp::Set_B_Value(int b_value) { this->b_value = b_value; }
	
void Gear_RGBLed_cpp::SetRGB_Value(int* values)
{
	this->r_value = values[0];
	this->g_value = values[1];
	this->b_value = values[2];
}

void Gear_RGBLed_cpp::SetRGB_Value(int r, int g, int b)
{
	this->r_value = r;
	this->g_value = g;
	this->b_value = b;
}

#pragma endregion

#pragma region Public Methods

string Gear_RGBLed_cpp::UpdatedJson()
{
	string val = "{\"rgb_led\":{\"name\":\"" + this->name + "\",";
	val += "\"pin\":\"" + this->pin_r + "," + this->pin_g + "," + this->pin_b + "\",";
	val += "\"mode\":" + to_string(this->mode) + ",";
	val += "\"value\": {\"r\":" + to_string(this->r_value) + ", \"g\":" + to_string(this->g_value) + ", \"b\":" + to_string(this->b_value);
	val += "}}}";

	return val;
}

#pragma endregion