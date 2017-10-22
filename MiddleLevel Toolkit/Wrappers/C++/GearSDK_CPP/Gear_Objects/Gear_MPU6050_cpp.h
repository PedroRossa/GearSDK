#ifndef Gear_MPU6050_cpp_H
#define Gear_MPU6050_cpp_H

#include <iostream>
using namespace std;

class Gear_MPU6050_cpp
{

#pragma region Attributes

	int id;
	string name;
	string pin_SDA;
	string pin_SCL;
	int* accel_Values;
	int* gyro_Values;

	double* angle_Values;

#pragma endregion

public:

#pragma region Constructors

	Gear_MPU6050_cpp();
	Gear_MPU6050_cpp(int id, string name, string pin_SDA, string pin_SCL, int* accel_Values, int* gyro_Values, double* angle_Values);
	Gear_MPU6050_cpp(int id, string name, string pin_SDA, string pin_SCL, int accel_x = 0, int accel_y = 0, int accel_z = 0, int gyro_x = 0, int gyro_y = 0, int gyro_z = 0);
	~Gear_MPU6050_cpp();

#pragma endregion

#pragma region Getters and Setters

	int GetId();
	string GetName();
	string GetPin_SDA();
	string GetPin_SCL();

	int* GetAccelValues();
	int* GetGyroValues();
	double* GetAngleValues();

	int GetAccel_X();
	int GetAccel_Y();
	int GetAccel_Z();

	int GetGyro_X();
	int GetGyro_Y();
	int GetGyro_Z();

	double GetAngle_X();
	double GetAngle_Y();
	double GetAngle_Z();

	void SetAccelValues(int* values);
	void SetGyroValues(int* values);
	void SetAngleValues(double* values);

#pragma endregion

};

#endif

