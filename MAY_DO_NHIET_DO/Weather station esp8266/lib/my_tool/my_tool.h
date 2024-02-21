#ifndef MY_TOOL_H
#define MY_TOOL_H

#include <string.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>

#define DEFAULT_WIFI_NAME "ESP8266_MODULE"
#define DEFAULT_WIFI_PASS "123456789"
#define DEFAULT_WIFI_IP staticIP(192, 168, 1, 150)
#define DEFAULT_WIFI_GATETWAY gateway(192, 168, 1, 1)
#define DEFAULT_WIFI_SUBNET subnet(255,255,255,0


class MY_TOOL
{
private:
    String _wifiName = DEFAULT_WIFI_NAME;
    String _wifiPass = DEFAULT_WIFI_PASS;
    WiFiMode _wifiMode = WIFI_AP_STA;
    IPAddress _ipAddress;
    IPAddress _gateway;
    IPAddress _subnet;

public:
    MY_TOOL();
    ~MY_TOOL();
    void begin();
    void setNameWifi(String name);
    void setPassWifi(String pass);
    IPAddress getIPAddressStationMode();
    IPAddress getIPAddressAccessMode();
};

MY_TOOL::MY_TOOL()
{
    Serial.begin(9600);
    Serial.println("");
    Serial.println("KHỞI TẠO OBJECT MY_TOOL");
    Serial.println("ESP8266 MODULE DISCONNECTED");
    WiFi.disconnect();
    WiFi.mode(_wifiMode);
}

MY_TOOL::~MY_TOOL()
{
    Serial.println("HỦY OBJECT MY_TOOL");
    WiFi.disconnect();
}

void MY_TOOL::begin()
{
    Serial.println("KHỞI CHẠI WIFI VỚI TÊN "+_wifiName+"");
    WiFi.begin(_wifiName, _wifiPass);
}

void MY_TOOL::setNameWifi(String name)
{
    _wifiName = name;
}

void MY_TOOL::setPassWifi(String pass)
{
    _wifiPass = pass;
}



#endif