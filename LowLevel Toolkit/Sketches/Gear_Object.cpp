#include "Gear_Object.h"

#pragma region Constructors

Gear_Object::Gear_Object()
{

}
Gear_Object::~Gear_Object()
{

}

#pragma endregion

#pragma region Gets and Sets

    uint Gear_Object::GetID() { return this->id; }
    String Gear_Object::GetName() { return this->name; }
    String Gear_Object::GetHeader() { return this->header; }
    JsonObject* Gear_Object::GetJson(){ return this->json; }
    
    String Gear_Object::getObjectTypeByJson(JsonObject& root)
    {
        String jsonType = "";
        String sJson = "";
        root.printTo(sJson);
    
        int pntIndex = sJson.indexOf(":");
    
        if(pntIndex > 0)
        {
            jsonType = sJson.substring(2, pntIndex-1);  
        }
         return jsonType;
    }

#pragma endregion