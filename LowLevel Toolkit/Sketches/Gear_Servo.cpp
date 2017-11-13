#include "Gear_Servo.h"

#pragma region Constructors

Gear_Servo::Gear_Servo(){}

Gear_Servo::Gear_Servo(String name, int pin)
{
    this->name = name;
    this->pin = pin;

    this->header = headerJson();
	
	//DISCOVER THE BUFFER SIZE TO YOUR OBJECT ON:
	// http://arduinojson.org/assistant/
	//Passing the json header of your object
	

    const size_t bufSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
	
	//<object_TAG> is the identifier of the object, like: "button", "potentiometer", etc
    
    const char* dataJson = "{\"servo\":{\"name\":\" name Here \", \"value\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_Servo::~Gear_Servo(){}

#pragma endregion

#pragma region Gets

     int Gear_Servo::GetPin() { return this->pin; }
     int Gear_Servo::GetValue() { return this->value; }
     
     void Gear_Servo::SetValue(int value) 
     { 
         this->value = value; 
         servo.write(value); 
    }

#pragma endregion

#pragma region Private Methods

String Gear_Servo::headerJson()
{
    String hJson = "{\"servo\":{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"value\"" + ":" +  this->value;
    hJson = hJson + "}}";

    return hJson;
}

#pragma endregion

#pragma region Public Methods
 
void Gear_Servo::init()
{
    servo.attach(this->pin); 
    
    (*this->json)["servo"]["name"] = GetName();
}

String Gear_Servo::updatedData()
{
    int lastValue = (*this->json)["servo"]["value"];
    int atualValue = GetValue();

    if(lastValue != atualValue)
    {
        (*this->json)["servo"]["value"] = atualValue;

        String aux = "";
        this->json->printTo(aux);
        return aux;
    }
    else
    {
        return "";
    }
}

void Gear_Servo::receivedMessage(JsonObject& root, String type)
{
    if(type == "servo")
    {
        int val = (root)["servo"]["value"];
        SetValue(val);
    }
}

#pragma endregion