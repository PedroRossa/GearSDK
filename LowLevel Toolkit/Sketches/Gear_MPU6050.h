#ifndef Gear_MPU6050_h
#define Gear_MPU6050_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication

class Gear_MPU6050
{
private:

#pragma region Attributes
    /*
     * Definições de alguns endereços mais comuns do MPU6050
     * os registros podem ser facilmente encontrados no mapa de registros do MPU6050
     */
    int MPU_ADDR =      0x68; // definição do endereço do sensor MPU6050 (0x68)
    const int WHO_AM_I =      0x75; // registro de identificação do dispositivo
    const int PWR_MGMT_1 =    0x6B; // registro de configuração do gerenciamento de energia
    const int GYRO_CONFIG =   0x1B; // registro de configuração do giroscópio
    const int ACCEL_CONFIG =  0x1C; // registro de configuração do acelerômetro
    const int ACCEL_XOUT =    0x3B; // registro de leitura do eixo X do acelerômetro
    
    const int sda_pin = D5; // definição do pino I2C SDA
    const int scl_pin = D6; // definição do pino I2C SCL

    // variáveis para armazenar os dados "crus" do acelerômetro
    int16_t accelerometer[3];
    int16_t gyro[3];
    int16_t temperature;

#pragma endregion

    //Private Methods
    void writeRegMPU(int reg, int val); //aceita um registro e um valor como parâmetro
    uint8_t readRegMPU(uint8_t reg); // aceita um registro como parâmetro

    void findMPU(int mpu_addr);

    void setSleepOff();
    void setGyroScale();
    void setAccelScale();
 
public:

    //Constructors
    Gear_MPU6050();
    Gear_MPU6050(const int MPU_ADDR = 0x68);
    ~Gear_MPU6050();

    //Getters
    int16_t* GetAccelerometer();
    int16_t* GetGyro();
    int16_t GetTemperature();

    //Public Methods
    void initI2C();
    void initMPU();

    void checkMPU(int mpu_addr);
    
    void readRawMPU();
};

#endif