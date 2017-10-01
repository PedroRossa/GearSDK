#include "Gear_RGBLed.h"

#pragma region Constructors

    Gear_RGBLed::Gear_RGBLed(){}

    /*Gear_RGBLed::Gear_RGBLed(int r_pin, int g_pin, int b_pin, Gear_Color color)
    {
        this->r_pin = r_pin;
        this->g_pin = g_pin;
        this->b_pin = b_pin;

        this->color = color;
    }*/

    Gear_RGBLed::Gear_RGBLed(int r_pin, int g_pin, int b_pin, LedMode mode, bool isAnalogic)
    {
        this->isAnalogic = isAnalogic;
        this->state = HIGH;

        this->mode = mode;

        this->r_pin = r_pin;
        this->g_pin = g_pin;
        this->b_pin = b_pin;
    }

    Gear_RGBLed::~Gear_RGBLed(){}

#pragma endregion

#pragma region Getters And Setters

bool Gear_RGBLed::IsAnalogic(){ return this->isAnalogic; }
void Gear_RGBLed::IsAnalogic(bool isAnalogic){ this->isAnalogic = isAnalogic; }

int Gear_RGBLed::GetR_Pin(){ return this->r_pin; }
int Gear_RGBLed::GetG_Pin(){ return this->g_pin; }
int Gear_RGBLed::GetB_Pin(){ return this->b_pin; }

bool Gear_RGBLed::GetState(){ return this->state; }
LedMode Gear_RGBLed::GetMode(){ return this->mode; }

void Gear_RGBLed::SetR_Pin(int r_pin){ this->r_pin = r_pin; }
void Gear_RGBLed::SetG_Pin(int g_pin){ this->g_pin = g_pin; }
void Gear_RGBLed::SetB_Pin(int b_pin){ this->b_pin = b_pin; }

void Gear_RGBLed::SetMode(LedMode mode, int timeOn, int timeOff, bool state)
{ 
    this->state = state;

    this->mode = mode; 
    this->timeOn = timeOn;
    this->timeOff = timeOff;
}

Gear_Color Gear_RGBLed::GetColor(){ return this->color; }

void Gear_RGBLed::SetColor(int r, int g, int b)
{
    this->color = Gear_Color(r,g,b);

    this->SendState();
}

/*void Gear_RGBLed::SetColor(Gear_Color color)
{
    this->color = color;

    digitalWrite(this->r_pin, color.GetR());
    digitalWrite(this->g_pin, color.GetG());
    digitalWrite(this->b_pin, color.GetB());
}*/

#pragma endregion

#pragma region Private Methods

void Gear_RGBLed::SendState()
{
    int val[3] = {0,0,0};

    if(this->state == HIGH)
    {
        val[0] = this->color.GetR();
        val[1] = this->color.GetG();
        val[2] = this->color.GetB();
    }

    if(this->isAnalogic)
    {
        analogWrite(this->r_pin, val[0]);
        analogWrite(this->g_pin, val[1]);
        analogWrite(this->b_pin, val[2]);
    }
    else
    {
        digitalWrite(this->r_pin, val[0]);
        digitalWrite(this->g_pin, val[1]);
        digitalWrite(this->b_pin, val[2]);
    }
}

void Gear_RGBLed::blinkMode()
{
}

void Gear_RGBLed::blinkingMode()
{
    currentTimer = millis();

    if(this->state == LOW)
    {
        if((currentTimer - initTimer) >= this->timeOff)
        {
            initTimer = currentTimer;
            this->state = HIGH;
        }
    } 
    else if(this->state == HIGH)
    {
        if((currentTimer - initTimer) >= this->timeOn)
        {
            initTimer = currentTimer;
            this->state = LOW;
        }
    } 
}
    
void Gear_RGBLed::fadeMode()
{
    
}
    
void Gear_RGBLed::fadingMode()
{
    
}

#pragma endregion

#pragma region Public Attributes

void Gear_RGBLed::init()
{
    pinMode(this->r_pin, OUTPUT);
    pinMode(this->g_pin, OUTPUT);
    pinMode(this->b_pin, OUTPUT);
}


void Gear_RGBLed::update()
{
    switch (this->mode)
    {
        case LedMode::STATIC:
        
        break;

        case LedMode::BLINK:
            this->blinkMode();
        break;

        case LedMode::BLINKING:
            this->blinkingMode();
        break;

        case LedMode::FADE:
            this->fadeMode();
        break;

        case LedMode::FADING:
            this->fadingMode();
        break;
        default:
        break;
    } 

    this->SendState();
}

#pragma endregion