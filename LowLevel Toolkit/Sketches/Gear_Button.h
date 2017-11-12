#ifndef Gear_Button_h
#define Gear_Button_h

#include "Gear_Object.h"

enum ButtonType
{
    PUSH_BUTTON,
    STATE_BUTTON
};

class Gear_Button : public Gear_Object
{
private:

#pragma region Attributes

    int pin;
    int state;
    ButtonType type;

#pragma endregion

#pragma region Private Methods

String headerJson();

#pragma endregion

public:

#pragma region Constructors

    Gear_Button();
    Gear_Button(String name, int pin, ButtonType type = ButtonType::PUSH_BUTTON);
    ~Gear_Button();

#pragma endregion

#pragma region Gets

    int GetPin();
    int GetState();
    int GetType();

#pragma endregion

#pragma region Public Methods

    void init();
    String updatedData();
    void receivedMessage(JsonObject& root, String type);

#pragma endregion

};

#endif
