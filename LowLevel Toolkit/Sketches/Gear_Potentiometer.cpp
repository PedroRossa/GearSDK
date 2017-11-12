#include "Gear_Potentiometer.h"

#pragma region Constructors

    Gear_Potentiometer::Gear_Potentiometer(){}

    Gear_Potentiometer::Gear_Potentiometer(String name, int pin)
    {
        this->name = name;
        this->pin = pin;

        this->header = headerJson();
        
        const size_t bufSize = JSON_OBJECT_SIZE(1) + 10;
        jsonBuffer = new DynamicJsonBuffer(bufSize);
             
        const char* dataJson = "{\"potentiometer\":{\"name\":\" name Here \", \"value\":0}}";
            
        this->json =  &jsonBuffer->parseObject(dataJson);
    }

    Gear_Potentiometer::~Gear_Potentiometer(){}

#pragma endregion

#pragma region Getters

    int Gear_Potentiometer::GetPin(){ return this->pin; }
   
    float Gear_Potentiometer::GetValue()
    {
        this->value = analogRead(this->pin);
        return this->value; 
    }

#pragma endregion

#pragma region Private Methods

String Gear_Potentiometer::headerJson()
{	
    String hJson = "{\"potentiometer\":{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"value\"" + ":" + this->value;
    hJson = hJson + "}}";

    return hJson;
}

#pragma endregion

#pragma region Public Attributes

    void Gear_Potentiometer::init()
    {
        pinMode(this->pin, INPUT);

        (*this->json)["potentiometer"]["name"] = GetName();
    }

    String Gear_Potentiometer::updatedData()
    {
        int lastValue = (*this->json)["potentiometer"]["value"];
        int atualValue = GetValue();

        if(lastValue != atualValue)
        {
            (*this->json)["potentiometer"]["value"] = atualValue;

            String aux = "";
            this->json->printTo(aux);
            return aux;
        }
        else
        {
            return "";
        }
    }

    void Gear_Potentiometer::receivedMessage(JsonObject& root, String type)
    {
        //This object don't receive messages from clients
    }

#pragma endregion

