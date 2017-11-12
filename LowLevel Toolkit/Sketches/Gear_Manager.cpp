#include "Gear_Manager.h"

#pragma region Constructors

Gear_Manager::Gear_Manager()
{
    objsSize = 0;
}

Gear_Manager::~Gear_Manager()
{

}

#pragma endregion

#pragma region Gets

Gear_Object** Gear_Manager::getObjects() { return this->objs; }
int Gear_Manager::getObjectsSize(){ return this->objsSize; }

Gear_Object* Gear_Manager::getObject(int id){ return objs[id]; }
Gear_Object* Gear_Manager::getObject(String name){
    for(int i = 0; i < objsSize; i++)
    {
        if(objs[i]->GetName() == name)
            return objs[i];
    }

}

#pragma endregion

#pragma region Public Methods

void Gear_Manager::add(Gear_Object* object)
{
    if (objsSize > MAX_OBJECTS)
    {
        return;
    }
    objs[objsSize] = object;

    objsSize++;
}

void Gear_Manager::init()
{
    for(int i = 0; i < objsSize; i++)
    {
        objs[i]->init();
    }
}

String Gear_Manager::createJsonHeader()
{
    String message = "header";
    String s = "";
    for(int i = 0; i < objsSize; i++)
    {
        s = objs[i]->GetHeader();
        message = message + "#" + s;
    }

    return message;
}

String Gear_Manager::createJsonData()
{
    String message = "data";
    String s = "";
    for(int i = 0; i < objsSize; i++)
    {
        s = objs[i]->updatedData();
        message = message + "#" + s;
    }

    return message;
}

#pragma endregion