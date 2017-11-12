#ifndef Gear_RGBLed_h
#define Gear_RGBLed_h

#include "Gear_Object.h"
#include "Gear_Color.h"

enum LedMode
{
    STATIC,
    BLINK,
    BLINKING,
    FADE,
    FADING
};

class Gear_RGBLed : public Gear_Object
{
private:

#pragma region Attributes

    bool isAnalogic;

    int r_pin;
    int g_pin;
    int b_pin;

    bool state;

    Gear_Color color;

    LedMode mode;

    unsigned long initTimer = 0;
    unsigned long currentTimer = 0;

    unsigned long timeOn = 500;
    unsigned long timeOff = 500;

#pragma endregion

#pragma region Private Methods

    String headerJson();

    void SendState();

    void blinkMode();
    void blinkingMode();

    void fadeMode();
    void fadingMode();

#pragma endregion

public:

#pragma region Constructors

    Gear_RGBLed();
    //Gear_RGBLed(int r_pin, int g_pin, int b_pin, Gear_Color color = Gear_Color(Colors::white));
    Gear_RGBLed(String name, int r_pin, int g_pin, int b_pin, LedMode mode = LedMode::STATIC, bool isAnalogic = true);
    ~Gear_RGBLed();

#pragma endregion

#pragma region Gets And Sets

    bool IsAnalogic();
    void IsAnalogic(bool isAnalogic);

    int GetR_Pin();
    int GetG_Pin();
    int GetB_Pin();

    bool GetState();
    LedMode GetMode();

    void SetR_Pin(int r_pin);
    void SetG_Pin(int g_pin);
    void SetB_Pin(int b_pin);

    void SetMode(LedMode mode, int timeOn = 0, int timeOff = 0, bool state = HIGH);

    Gear_Color GetColor();
    
    void SetColor(int r, int g, int b);
    //void SetColor(Gear_Color color);

#pragma endregion

#pragma region Public Attributes

    void init();
    String updatedData();
    void receivedMessage(JsonObject& root, String type);
    
    void update();

#pragma endregion

};

#endif