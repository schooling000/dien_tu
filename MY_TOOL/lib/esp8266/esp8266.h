#ifndef ESP8266_H
#define ESP8266_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

enum ESP8266_MODE
{
    ESP8266_STATION = WIFI_STA,
    ESP8266_ACCESS_POINT = WIFI_STA,
    ESP8266_ALL = WIFI_AP_STA,
    ESP8266_OFF = WIFI_OFF
};

class MY_ESP8266
{
private:
    String _nameWiFi = "";
    String _passWiFi = "";
    byte _modeWiFi;

public:
    MY_ESP8266()
    {
        Serial.begin(9600);
        this->_nameWiFi = "ESP8266";
        this->_passWiFi = "123456789";
        this->_modeWiFi = ESP8266_MODE::ESP8266_STATION;
    }

    void setMode(ESP8266_MODE mode)
    {
        this->_modeWiFi = mode;
    }

    bool setName(String name)
    {
        if (name == NULL)
        {
            return false;
        }

        this->_nameWiFi = name;
        return true;
    }

    bool setPass(String pass)
    {
        if (pass == NULL || pass.length() < 8)
        {
            return false;
        }

        this->_nameWiFi = pass;
        return true;
    }

    void setConfig(IPAddress IP, IPAddress gateWay, IPAddress subnet){
        
    }

    
};
#endif