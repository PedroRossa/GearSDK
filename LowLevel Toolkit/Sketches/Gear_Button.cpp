#include "Gear_Button.h"

#pragma region Constructors

Gear_Button::Gear_Button(){}

Gear_Button::Gear_Button(String name, int pin, ButtonType type)
{
    this->name = name;
    this->pin = pin;
    this->type = type;
    this->state = 0;

    this->header = headerJson();

    const size_t bufSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
    
    const char* dataJson = "{\"button\":{\"name\":\" name Here \", \"state\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_Button::~Gear_Button(){}

#pragma endregion

#pragma region Gets

     int Gear_Button::GetPin() { return this->pin; }
     
     int Gear_Button::GetState()
     {
        this->state = digitalRead(this->pin);
        return this->state; 
     }

     int Gear_Button::GetType() { return this->type; }

#pragma endregion

#pragma region Private Methods

String Gear_Button::headerJson()
{
    String hJson = "{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"state\"" + ":" + this->state + ",";
    hJson = hJson + "\"type\"" + ":" + this->type;
    hJson = hJson + "}";

    return hJson;
}

#pragma endregion

#pragma region Public Methods
 
String Gear_Button::GetHeader(){ return this->header; }

void Gear_Button::init()
{
    pinMode(this->pin, INPUT);
    
    (*this->json)["button"]["name"] = GetName();
}

String Gear_Button::updatedData()
{
    int lastState = (*this->json)["button"]["state"];
    int atualState = GetState();

    if(lastState != atualState)
    {
        (*this->json)["button"]["state"] = atualState;

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