#ifndef Gear_Server_h
#define Gear_Server_h

#include <Arduino.h>
#include <Wire.h>//I2C comunication

#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer espServer = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, int type, uint8_t* payload, size_t length);

void ConfigWebServer()
{
    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    if(MDNS.begin("esp8266")) {
        Serial.println("MDNS responder started");
    }

    Serial.println(WiFi.localIP());
    espServer.begin();

    // Add service to MDNS
    MDNS.addService("http", "tcp", 80);
    MDNS.addService("ws", "tcp", 81);
}

void WebServerLoop()
{
    webSocket.loop();
    espServer.handleClient();
}

#endif