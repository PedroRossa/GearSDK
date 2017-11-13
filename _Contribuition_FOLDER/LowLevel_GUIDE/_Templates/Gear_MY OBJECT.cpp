#include "Gear_<MY OBJECT>.h"

#pragma region Constructors

Gear_<MY OBJECT>::Gear_<MY OBJECT>(){}

Gear_<MY OBJECT>::Gear_<MY OBJECT>(String name, int pin, int value)
{
    this->name = name;
    this->pin = pin;
    this->value = value;

    this->header = headerJson();
	
	//DISCOVER THE BUFFER SIZE TO YOUR OBJECT ON:
	// http://arduinojson.org/assistant/
	//Passing the json header of your object
	

    const size_t bufSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 60;
    jsonBuffer = new DynamicJsonBuffer(bufSize);
	
	//<object_TAG> is the identifier of the object, like: "button", "potentiometer", etc
        
	/*Create a JSON to represent your object
		It's necessary to respect this sintax
        {
            "<object_TAG>":
            {
                fields
            }
        }

    */
    const char* dataJson = "{\"<my_object_TAG>\":{\"name\":\" name Here \", \"value\":0}}";
    this->json =  &jsonBuffer->parseObject(dataJson);
}

Gear_<MY OBJECT>::~Gear_<MY OBJECT>(){}

#pragma endregion

#pragma region Gets

     int Gear_<MY OBJECT>::GetPin() { return this->pin; }
     int Gear_<MY OBJECT>::GetValue() { return this->value; }

#pragma endregion

#pragma region Private Methods

/*Create a JSON to represent your data object, put only important fields
		It's necessary to respect this sintax
        {
            "<object_TAG>":
            {
                fields
            }
        }

    */
String Gear_<MY OBJECT>::headerJson()
{
    String hJson = "{\"<my_object_TAG>\":{";
    hJson = hJson + "\"name\"" + ":" + "\"" + this->name + "\",";
    hJson = hJson + "\"pin\"" + ":" + "\"" +  this->pin + "\",";
    hJson = hJson + "\"value\"" + ":" +  this->value;
    hJson = hJson + "}}";

    return hJson;
}

#pragma endregion

#pragma region Public Methods
 
void Gear_<MY OBJECT>::init()
{
    pinMode(this->pin, INPUT);
    
    (*this->json)["<my_object_TAG>"]["name"] = GetName();
}

String Gear_<MY OBJECT>::updatedData()
{
    int lastValue = (*this->json)["<my_object_TAG>"]["value"];
    int atualValue = GetValue();

    if(lastValue != atualValue)
    {
        (*this->json)["<my_object_TAG>"]["value"] = atualValue;

        String aux = "";
        this->json->printTo(aux);
        return aux;
    }
    else
    {
        return "";
    }
}

void Gear_<MY OBJECT>::receivedMessage(JsonObject& root, String type)
{
	//Threat here if the object receive messages from the software side
	
	/* led Example
	
	if(type == "rgb_led")  
    {
        int v1 = (root)["rgb_led"]["value"]["r"];
        int v2 = (root)["rgb_led"]["value"]["g"];
        int v3 = (root)["rgb_led"]["value"]["b"];

        int mode = (root)["rgb_led"]["mode"];

        SetColor(v1,v2,v3);
        SetMode((LedMode)mode, 800, 200);
    }   
	
	*/
}

#pragma endregion