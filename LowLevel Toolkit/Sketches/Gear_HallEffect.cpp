#include "Gear_HallEffect.h"

#pragma region Constructors

Gear_HallEffect::Gear_HallEffect(){}

Gear_HallEffect::Gear_HallEffect(String name, int pin, int value)
{
    this->name = name;
    this->pin = pin;
    this->value = value;

    this->header = headerJson();
	
    const size_t bufSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
	        
    const char* dataJson = "{\"hallEffect\":{\"name\":\" name Here \", \"value\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_HallEffect::~Gear_HallEffect(){}

#pragma endregion

#pragma region Gets

     int Gear_HallEffect::GetPin() { return this->pin; }
     int Gear_HallEffect::GetValue() { return this->value; }

#pragma endregion

#pragma region Private Methods

String Gear_HallEffect::headerJson()
{
    String hJson = "{\"hallEffect\":{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"value\"" + ":" +  this->value;
    hJson = hJson + "}}";

    return hJson;
}

#pragma endregion

#pragma region Public Methods
 
void Gear_HallEffect::init()
{
    pinMode(this->pin, INPUT);
    
    (*this->json)["hallEffect"]["name"] = GetName();
}

String Gear_HallEffect::updatedData()
{
    int lastValue = (*this->json)["hallEffect"]["value"];
    int atualValue = GetValue();

    if(lastValue != atualValue)
    {
        (*this->json)["hallEffect"]["value"] = atualValue;

        String aux = "";
        this->json->printTo(aux);
        return aux;
    }
    else
    {
        return "";
    }
}

void Gear_HallEffect::receivedMessage(JsonObject& root, String type)
{
	//Threat here if the object receive messages from the software side
}

#pragma endregion