#include "Gear_PulseDetector.h"

#pragma region Constructors

Gear_PulseDetector::Gear_PulseDetector(){}

Gear_PulseDetector::Gear_PulseDetector(String name, int pin, int value)
{
    this->name = name;
    this->pin = pin;
    this->value = value;

    this->header = headerJson();
	
    const size_t bufSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
	        
    const char* dataJson = "{\"pulseDetector\":{\"name\":\" name Here \", \"value\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_PulseDetector::~Gear_PulseDetector(){}

#pragma endregion

#pragma region Gets

     int Gear_PulseDetector::GetPin() { return this->pin; }
     int Gear_PulseDetector::GetValue() { return this->value; }

#pragma endregion

#pragma region Private Methods

String Gear_PulseDetector::headerJson()
{
    String hJson = "{\"pulseDetector\":{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"value\"" + ":" +  this->value;
    hJson = hJson + "}}";

    return hJson;
}

#pragma endregion

#pragma region Public Methods
 
void Gear_PulseDetector::init()
{
    pinMode(this->pin, INPUT);
    
    (*this->json)["pulseDetector"]["name"] = GetName();
}

String Gear_PulseDetector::updatedData()
{
    int lastValue = (*this->json)["pulseDetector"]["value"];
    int atualValue = GetValue();

    if(lastValue != atualValue)
    {
        (*this->json)["pulseDetector"]["value"] = atualValue;

        String aux = "";
        this->json->printTo(aux);
        return aux;
    }
    else
    {
        return "";
    }
}

void Gear_PulseDetector::receivedMessage(JsonObject& root, String type)
{
	//Threat here if the object receive messages from the software side
}

#pragma endregion