#ifndef Gear_Color_h
#define Gear_Color_h

enum Colors
{
    red,
    green,
    blue,
    yellow,
    magenta,
    cian,
    white,
    black
};

class Gear_Color
{
private:

    #pragma region Attributes

    bool isAnalogic;

    int r;
    int g;
    int b;

    #pragma endregion

public:

    #pragma region Constructors

    Gear_Color();
    Gear_Color(Colors color, bool isAnalogic = true);
    Gear_Color(int r, int g, int b, bool isAnalogic = true);
    ~Gear_Color();

    #pragma endregion

    #pragma region Getters and Setters

    bool IsAnalogic();
    void IsAnalogic(bool isAnalogic);

    int GetR();
    int GetG();
    int GetB();

    void SetR(int r);
    void SetG(int g);
    void SetB(int b);

    #pragma endregion

    #pragma region Public Attributes

    static int* GetValues(Colors color, bool isAnalogic);

    #pragma endregion

};

#endif