#ifndef Gear_WiFiConnection_h
#define Gear_WiFiConnection_h

#include <Arduino.h>
#include <ESP8266WiFi.h> // biblioteca para usar as funções de Wifi do módulo ESP8266

class Gear_WiFiConnection
{
private:

    const char* _ssid;
    const char* _password;
    IPAddress _localIP;
    
    // Private Methods
    void printEncryptionType(int thisType);

public:

    //Constructors
    Gear_WiFiConnection();
    Gear_WiFiConnection(const char* ssid, const char* password);
    //Destructor
    ~Gear_WiFiConnection();

    //GETTERS AND SETTERS
    const char* ssid();
    const char* password();
    IPAddress localIP();
    
    //Public Methods
    void InitWiFi();
    void ReconnectWiFi();

	void ListNetworks();
};

#endif