#include "Gear_MPU6050_cpp.h"

#pragma region Constructors

Gear_MPU6050_cpp::Gear_MPU6050_cpp()
{
}

Gear_MPU6050_cpp::Gear_MPU6050_cpp(int id, string name, string pin_SDA, string pin_SCL, int* accel_Values, int* gyro_Values, double* angle_Values)
{
	this->id = id;
	this->name = name;
	this->pin_SDA = pin_SDA;
	this->pin_SCL = pin_SCL;
	this->accel_Values = accel_Values;
	this->gyro_Values = gyro_Values;
	this->angle_Values = angle_Values;
}

Gear_MPU6050_cpp::Gear_MPU6050_cpp(int id, string name, string pin_SDA, string pin_SCL, int accel_x, int accel_y, int accel_z, int gyro_x, int gyro_y, int gyro_z)
{
	this->id = id;
	this->name = name;
	this->pin_SDA = pin_SDA;
	this->pin_SCL = pin_SCL;

	int accel[3] = { accel_x ,accel_y, accel_z };
	this->accel_Values = accel;

	int gyro[3] = { gyro_x ,gyro_y, gyro_z};
	this->gyro_Values = gyro;

	double angle[3] = { 0,0,0 };
	this->angle_Values = angle;
}

Gear_MPU6050_cpp::~Gear_MPU6050_cpp()
{
}

#pragma endregion

#pragma region Getters and Setters

int Gear_MPU6050_cpp::GetId() { return this->id; }
string Gear_MPU6050_cpp::GetName() { return this->name; }
string Gear_MPU6050_cpp::GetPin_SDA() { return this->pin_SDA; }
string Gear_MPU6050_cpp::GetPin_SCL() { return this->pin_SCL; }

int* Gear_MPU6050_cpp::GetAccelValues() { return this->accel_Values; }
int* Gear_MPU6050_cpp::GetGyroValues() { return this->gyro_Values; }
double* Gear_MPU6050_cpp::GetAngleValues() { return this->angle_Values; }

int Gear_MPU6050_cpp::GetAccel_X() { return this->accel_Values[0]; }
int Gear_MPU6050_cpp::GetAccel_Y() { return this->accel_Values[1]; }
int Gear_MPU6050_cpp::GetAccel_Z() { return this->accel_Values[2]; }

int Gear_MPU6050_cpp::GetGyro_X() { return this->gyro_Values[0]; }
int Gear_MPU6050_cpp::GetGyro_Y() { return this->gyro_Values[1]; }
int Gear_MPU6050_cpp::GetGyro_Z() { return this->gyro_Values[2]; }

double Gear_MPU6050_cpp::GetAngle_X() { return this->angle_Values[0]; }
double Gear_MPU6050_cpp::GetAngle_Y() { return this->angle_Values[1]; }
double Gear_MPU6050_cpp::GetAngle_Z() { return this->angle_Values[2]; }

void Gear_MPU6050_cpp::SetAccelValues(int* values)
{
	this->accel_Values[0] = values[0];
	this->accel_Values[1] = values[1];
	this->accel_Values[2] = values[2];
}

void Gear_MPU6050_cpp::SetGyroValues(int* values)
{
	this->gyro_Values[0] = values[0];
	this->gyro_Values[1] = values[1];
	this->gyro_Values[2] = values[2];
}

void Gear_MPU6050_cpp::SetAngleValues(double* values)
{
	this->angle_Values[0] = values[0];
	this->angle_Values[1] = values[1];
	this->angle_Values[2] = values[2];
}


#pragma endregion
