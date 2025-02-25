#ifndef MY_ESP8266_WIFI_H
#define MY_ESP8266_WIFI_H

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <ArduinoJson.h>
#include <DHT.h>


#define DEFAULT_WIFI_NAME "MY_ESP8266_WIFI"
#define DEFAULT_WIFI_PASS "123456789"

class MY_ESP8266_WIFI
{
private:
    char *_ssid;
    char *_pass;
    JsonDocument data;
public:
    MY_ESP8266_WIFI();
    ~MY_ESP8266_WIFI();
    void debug();
    void setWifiNameInAccessMode(char *ssid);
    void setWifiPassInAccessMode(char *pass);
    void getDataDTH11Sensor(int pin);
    char* getMode(int mode);
};



#endif