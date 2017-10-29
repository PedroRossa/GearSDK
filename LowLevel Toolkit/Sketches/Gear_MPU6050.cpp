#include "Gear_MPU6050.h"

#pragma region Constrcutors

Gear_MPU6050::Gear_MPU6050(){}

Gear_MPU6050::Gear_MPU6050(String name, int sdaPin, int sclPin, const int MPU_ADDR)
{
    this->name = name;
    this->sdaPin = sdaPin;
    this->sclPin = sclPin;
    this->MPU_ADDR = MPU_ADDR;

    this->header = headerJson();
    
    const size_t bufSize = 4*JSON_OBJECT_SIZE(3) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
         
    const char* dataJson = "{\"accel\":{\"x\":0,\"y\":0,\"z\":0},\"gyro\":{\"x\":0,\"y\":0,\"z\":0},\"angle\":{\"x\":0,\"y\":0,\"z\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_MPU6050::~Gear_MPU6050(){}

#pragma endregion

#pragma region Gets

int16_t* Gear_MPU6050::GetAccelerometer(){ return this->accelerometer; }
int16_t* Gear_MPU6050::GetGyro(){ return this->gyro; }
int16_t Gear_MPU6050::GetTemperature(){ return this->temperature; }

int Gear_MPU6050::GetSDAPin(){ return this->sdaPin; }
int Gear_MPU6050::GetSCLPin(){ return this->sclPin; }

double* Gear_MPU6050::GetAngle(){ return this->angle; }
double Gear_MPU6050::GetAngleX(){ return this->angle[0]; }
double Gear_MPU6050::GetAngleY(){ return this->angle[1]; }
double Gear_MPU6050::GetAngleZ(){ return this->angle[2]; }

#pragma endregion

#pragma region Private Methods
    
String Gear_MPU6050::headerJson()
{
    String hJson = "{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pins\"" + ":" + "\"" + this->sdaPin + "," + this->sclPin+ "\",";
    hJson = hJson + "\"accel\"" + ":";
    hJson = hJson + "{" + "\"x\": 0, \"y\": 0, \"z\": 0 },";
    hJson = hJson + "\"gyro\"" + ":";
    hJson = hJson + "{" + "\"x\": 0, \"y\": 0, \"z\": 0 },";
    hJson = hJson + "\"angle\"" + ":";
    hJson = hJson + "{" + "\"x\": 0, \"y\": 0, \"z\": 0 }";
    hJson = hJson + "}";

    return hJson;
}

/*  função que escreve um dado valor em um dado registro */
void Gear_MPU6050::writeRegMPU(int reg, int val)
{
    Wire.beginTransmission(MPU_ADDR);     // inicia comunicação com endereço do MPU6050
    Wire.write(reg);                      // envia o registro com o qual se deseja trabalhar
    Wire.write(val);                      // escreve o valor no registro
    Wire.endTransmission(true);           // termina a transmissão
}
    
/* função que lê de um dado registro */
 uint8_t Gear_MPU6050::readRegMPU(uint8_t reg)
{
    uint8_t data;
    Wire.beginTransmission(MPU_ADDR);     // inicia comunicação com endereço do MPU6050
    Wire.write(reg);                      // envia o registro com o qual se deseja trabalhar
    Wire.endTransmission(false);          // termina transmissão mas continua com I2C aberto (envia STOP e START)
    Wire.requestFrom(MPU_ADDR, 1);        // configura para receber 1 byte do registro escolhido acima
    data = Wire.read();                   // lê o byte e guarda em 'data'
    return data;                          //retorna 'data'
}
    
/* função que procura pelo sensor no endereço 0x68 */
void Gear_MPU6050::findMPU(int mpu_addr)
{
    Wire.beginTransmission(MPU_ADDR);
    int data = Wire.endTransmission(true);
    
    if(data == 0)
    {
        Serial.print("Found MPU on address: 0x");
        Serial.println(MPU_ADDR, HEX);
    }
    else
    {
        Serial.println("MPU not found!");
    }
}
      
/* função para configurar o sleep bit  */
void Gear_MPU6050::setSleepOff()
{
    writeRegMPU(PWR_MGMT_1, 0); // escreve 0 no registro de gerenciamento de energia(0x68), colocando o sensor em o modo ACTIVE
}
    
/* função para configurar as escalas do giroscópio
    registro da escala do giroscópio: 0x1B[4:3]
    0 é 250°/s

    FS_SEL  Full Scale Range
    0        ± 250 °/s      0b00000000
    1        ± 500 °/s      0b00001000
    2        ± 1000 °/s     0b00010000
    3        ± 2000 °/s     0b00011000
*/
void Gear_MPU6050::setGyroScale()
{
    writeRegMPU(GYRO_CONFIG, 0);
}
    
/* função para configurar as escalas do acelerômetro
    registro da escala do acelerômetro: 0x1C[4:3]
    0 é 250°/s

    AFS_SEL   Full Scale Range
    0           ± 2g            0b00000000
    1           ± 4g            0b00001000
    2           ± 8g            0b00010000
    3           ± 16g           0b00011000
*/
void Gear_MPU6050::setAccelScale()
{
    writeRegMPU(ACCEL_CONFIG, 0);
}

/* função que configura a I2C com os pinos desejados 
    * sda_pin -> D5
    * scl_pin -> D6
*/
void Gear_MPU6050::initI2C() 
{
    Wire.begin(sdaPin, sclPin);
}

/* função de inicialização do sensor */
void Gear_MPU6050::initMPU()
{
    setSleepOff();
    setGyroScale();
    setAccelScale();
}

/* função que verifica se o sensor responde e se está ativo */
void Gear_MPU6050::checkMPU(int mpu_addr)
{
    findMPU(MPU_ADDR);
    int data = readRegMPU(WHO_AM_I); // Register 117 – Who Am I - 0x75
    
    if(data == 104) 
    {
        Serial.println("MPU6050 answer OK! (104)");

        data = readRegMPU(PWR_MGMT_1); // Register 107 – Power Management 1-0x6B

        if(data == 64) Serial.println("MPU6050 in SLEEP MODE! (64)");
        else Serial.println("MPU6050 in ACTIVE MODE!"); 
    }
    else 
    {
        Serial.println("Verify device - MPU6050 Unavailable!");
    }
} 

#pragma endregion

#pragma region Public Methods

/* função que lê os dados 'crus'(raw data) do sensor
   são 14 bytes no total sendo eles 2 bytes para cada eixo e 2 bytes para temperatura:

    0x3B 59 ACCEL_XOUT[15:8]
    0x3C 60 ACCEL_XOUT[7:0]
    0x3D 61 ACCEL_YOUT[15:8]
    0x3E 62 ACCEL_YOUT[7:0]
    0x3F 63 ACCEL_ZOUT[15:8]
    0x40 64 ACCEL_ZOUT[7:0]

    0x41 65 TEMP_OUT[15:8]
    0x42 66 TEMP_OUT[7:0]

    0x43 67 GYRO_XOUT[15:8]
    0x44 68 GYRO_XOUT[7:0]
    0x45 69 GYRO_YOUT[15:8]
    0x46 70 GYRO_YOUT[7:0]
    0x47 71 GYRO_ZOUT[15:8]
    0x48 72 GYRO_ZOUT[7:0] 
*/
void Gear_MPU6050::readRawMPU()
{  
    Wire.beginTransmission(MPU_ADDR);       // inicia comunicação com endereço do MPU6050
    Wire.write(ACCEL_XOUT);                 // envia o registro com o qual se deseja trabalhar, começando com registro 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);            // termina transmissão mas continua com I2C aberto (envia STOP e START)
    Wire.requestFrom(MPU_ADDR, 14);         // configura para receber 14 bytes começando do registro escolhido acima (0x3B)
    
    accelerometer[0] = Wire.read() << 8;                 // lê primeiro o byte mais significativo
    accelerometer[0]  |= Wire.read();                     // depois lê o bit menos significativo
    accelerometer[1]  = Wire.read() << 8;
    accelerometer[1]  |= Wire.read();
    accelerometer[2]  = Wire.read() << 8;
    accelerometer[2]  |= Wire.read();
    
    temperature = Wire.read() << 8;
    temperature |= Wire.read();
    
    gyro[0] = Wire.read() << 8;
    gyro[0] |= Wire.read();
    gyro[1] = Wire.read() << 8;
    gyro[1] |= Wire.read();
    gyro[2] = Wire.read() << 8;
    gyro[2] |= Wire.read();                                  
}

void Gear_MPU6050::CalculateAngles()
{
    int minVal=265; int maxVal=402;
    
    int xAng = map(accelerometer[0],minVal,maxVal,-90,90); 
    int yAng = map(accelerometer[1],minVal,maxVal,-90,90); 
    int zAng = map(accelerometer[2],minVal,maxVal,-90,90);
    
    angle[0] = RAD_TO_DEG * (atan2(-yAng, -zAng)+PI); 
    angle[1] = RAD_TO_DEG * (atan2(-xAng, -zAng)+PI); 
    angle[2] = RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
}

String Gear_MPU6050::GetHeader(){ return this->header; }

void Gear_MPU6050::init()
{
    initI2C();
    initMPU();
    checkMPU(MPU_ADDR);
}

String Gear_MPU6050::updatedData()
{
    int lastAccelX = (*this->json)["accel"]["x"];
    int lastAccelY = (*this->json)["accel"]["y"];
    int lastAccelZ = (*this->json)["accel"]["z"];

    int atualAccelX = GetAccelerometer()[0];
    int atualAccelY = GetAccelerometer()[1];
    int atualAccelZ = GetAccelerometer()[2];

    int lastGyroX = (*this->json)["gyro"]["x"];
    int lastGyroY = (*this->json)["gyro"]["y"];
    int lastGyroZ = (*this->json)["gyro"]["z"];

    int atualGyroX = GetGyro()[0];
    int atualGyroY = GetGyro()[1];
    int atualGyroZ = GetGyro()[2];

    int lastAngleX = (*this->json)["angle"]["x"];
    int lastAngleY = (*this->json)["angle"]["y"];
    int lastAngleZ = (*this->json)["angle"]["z"];

    double atualAngleX = GetAngle()[0];
    double atualAngleY = GetAngle()[1];
    double atualAngleZ = GetAngle()[2];

    int lastTemperature = (*this->json)["temperature"];
    int atualTemperature = GetTemperature();
    
    if(lastAccelX != atualAccelX || lastAccelY != atualAccelY || lastAccelZ != atualAccelZ ||
        lastGyroX != atualGyroX || lastGyroY != atualGyroY || lastGyroZ != atualGyroZ ||
        lastAngleX != atualAngleX || lastAngleY != atualAngleY || lastAngleZ != atualAngleZ || 
        lastTemperature != atualTemperature)
    {
        (*this->json)["accel"]["x"] = atualAccelX;
        (*this->json)["accel"]["y"] = atualAccelY;
        (*this->json)["accel"]["z"] = atualAccelZ;

        (*this->json)["gyro"]["x"] = atualGyroX;
        (*this->json)["gyro"]["y"] = atualGyroY;
        (*this->json)["gyro"]["z"] = atualGyroZ;

        (*this->json)["angle"]["x"] = atualAngleX;
        (*this->json)["angle"]["y"] = atualAngleY;
        (*this->json)["angle"]["z"] = atualAngleZ;

        (*this->json)["temperature"] = atualTemperature;

        String aux = "";
        this->json->printTo(aux);
        return aux;
    }
    else
    {
        return "";
    }
}

#pragma endregion

