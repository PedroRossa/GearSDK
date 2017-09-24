#include "Gear_Color.h"

#pragma region Constructors

Gear_Color::Gear_Color(){}

Gear_Color::Gear_Color(Colors color, bool isAnalogic)
{
    this->isAnalogic = isAnalogic;

    int* vals = GetValues(color, isAnalogic);

    this->r = vals[0];
    this->g = vals[1];
    this->b = vals[2];
}

Gear_Color::Gear_Color(int r, int g, int b, bool isAnalogic)
{
    this->isAnalogic = isAnalogic;

    this->r = r;
    this->g = g;
    this->b = b;
}

Gear_Color::~Gear_Color(){}

#pragma endregion

#pragma region Getters and Setters

bool Gear_Color::IsAnalogic(){ return this->isAnalogic; }
void Gear_Color::IsAnalogic(bool isAnalogic){ this->isAnalogic = isAnalogic; }

int Gear_Color::GetR(){ return this->r; }
int Gear_Color::GetG(){ return this->g; }
int Gear_Color::GetB(){ return this->b; }

void Gear_Color::SetR(int r){ this->r = r; }
void Gear_Color::SetG(int g){ this->g = g; }
void Gear_Color::SetB(int b){ this->b = b; }

#pragma endregion

#pragma region Constructors

int* Gear_Color::GetValues(Colors color, bool isAnalogic)
{
    int intValues[3] = {0,0,0};
    
    switch(color)
    {
        case Colors::black:
        {
            intValues[0] = 0; intValues[1] = 0; intValues[2] = 0; 
            break;
        }
    
        case Colors::blue:
        {
            if(isAnalogic)
            {
                intValues[0] = 0; intValues[1] = 0; intValues[2] = 1023; 
            }
            else
            {
                intValues[0] = 0; intValues[1] = 0; intValues[2] = 1; 
            }    
            break;
        }
        case Colors::cian:
        {
            if(isAnalogic)
            {
                intValues[0] = 0; intValues[1] = 1023; intValues[2] = 1023; 
            } 
            else
            {
                intValues[0] = 0; intValues[1] = 1; intValues[2] = 1;
            }  
                
            break;
        }
        case Colors::green:
        {
            if(isAnalogic)
            {
                intValues[0] = 0; intValues[1] = 1023; intValues[2] = 0; 
            } 
            else
            {
                intValues[0] = 0; intValues[1] = 1; intValues[2] = 0; 
            } 
                
            break;
        }
        case Colors::magenta:
        {
            if(isAnalogic)
            {
                intValues[0] = 1023; intValues[1] = 0; intValues[2] = 1023; 
            } 
            else
            {
                intValues[0] = 1; intValues[1] = 0; intValues[2] = 1; 
            } 
                
            break;
        }
        case Colors::red:
        {
            if(isAnalogic)
            {
                intValues[0] = 1023; intValues[1] = 0; intValues[2] = 0; 
            } 
            else
            {
                intValues[0] = 1; intValues[1] = 0; intValues[2] = 0; 
            } 
                
            break;
        }
        case Colors::white:
        {
            if(isAnalogic)
            {
                intValues[0] = 1023; intValues[1] = 1023; intValues[2] = 1023; 
            } 
            else
            {
                intValues[0] = 1; intValues[1] = 1; intValues[2] = 1; 
            } 
                
            break;
        }
        case Colors::yellow:
        {
            if(isAnalogic)
            {
                intValues[0] = 1023; intValues[1] = 1023; intValues[2] = 0; 
            } 
            else
            {
                intValues[0] = 1; intValues[1] = 1; intValues[2] = 0; 
            } 
                
            break;
        }
        default:
        break;
    }
    return intValues;
}

#pragma endregion