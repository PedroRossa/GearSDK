#include "Gear_WiFiConnection.h"

#pragma region Constructors

Gear_WiFiConnection::Gear_WiFiConnection()
{

}

Gear_WiFiConnection::Gear_WiFiConnection(const char* ssid, const char* password)
{
    this->_ssid = ssid;
    this->_password = password;
}

//Destructor
Gear_WiFiConnection::~Gear_WiFiConnection()
{
    this->_ssid = "";
    this->_password = "";
}

#pragma endregion

#pragma region GETTERS AND SETTERS

const char* Gear_WiFiConnection::ssid(){return this->_ssid;}
const char* Gear_WiFiConnection::password(){return this->_password;}
IPAddress Gear_WiFiConnection::localIP(){return this->_localIP;}

#pragma endregion

#pragma region Private Methods

void Gear_WiFiConnection::printEncryptionType(int thisType) 
{
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
  }
}

#pragma endregion

#pragma region Public Methods

void Gear_WiFiConnection::InitWiFi()
{
    delay(10);
    Serial.print("Conectando-se na rede: ");
    Serial.println(this->ssid());
    Serial.println("Aguarde");
	
	  WiFi.persistent(false);
   
    ReconnectWiFi();
}

void Gear_WiFiConnection::ReconnectWiFi()
{
    if(WiFi.status() == WL_CONNECTED)
    return;
 
 
    WiFi.begin(this->ssid(), this->password());
 
	int i = 0;
	while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
		delay(1000);
		Serial.print(++i); Serial.print(' ');
	}
 
    Serial.println();
    Serial.print("Connected with sucess on network: ");
    Serial.println(this->ssid());
    Serial.print("Obtained IP: ");
    Serial.println(WiFi.localIP());  

    this->_localIP = WiFi.localIP();
}

void Gear_WiFiConnection::ListNetworks()
{
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  int thisNet = 0;
  // print the network number and name for each network found:
  for (thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
  }
}

#pragma endregion
