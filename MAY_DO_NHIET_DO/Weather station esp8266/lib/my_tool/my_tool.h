#ifndef MY_TOOL_H
#define MY_TOOL_H

#include <string.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>

const String DEFAULT_WIFI_NAME = "ESP8266_MODULE";
const String DEFAULT_WIFI_PASS = "123456789";
#define DEFAULT_WIFI_IP  staticIP(192, 168, 1, 150);
#define DEFAULT_WIFI_GATETWAY  gateway(192, 168, 1, 1);
#define DEFAULT_WIFI_SUBNET  subnet(255,255,255,0);

class MY_TOOL
{
private:
    String _wifiConnectName = "";
    String _wifiConnectPass = "";
    String _wifiName = DEFAULT_WIFI_NAME;
    String _wifiPass = DEFAULT_WIFI_PASS;
    WiFiMode _wifiMode = WIFI_AP_STA;
    IPAddress _ipAddress;
    IPAddress _gateway;
    IPAddress _subnet;

public:
    MY_TOOL();
    ~MY_TOOL();
    void setNameWifi(String name);
    void setPassWifi(String pass);
    void setNameWifiConnect(String name);
    void setPassWifiConnect(String pass);
    void setMode(WiFiMode mode);
    WiFiMode getMode();
    wl_status_t getStatus();
    
    void begin();
    
    IPAddress getWifiIP();
    String getModeToString();
    void debug();
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
    switch (_wifiMode)
    {
    case WIFI_STA:
        Serial.println("KHỞI CHẠI WIFI MODE STATION(TRẠM KẾT NỐI HAY THIẾT BỊ KẾT NỐI VỚI THIẾT BỊ KHÁC) VỚI TÊN: "+_wifiConnectName);
        WiFi.begin(_wifiConnectName, _wifiConnectPass);
        break;
    case WIFI_AP:
        Serial.println("KHỞI CHẠI WIFI MODE ACCESS(MODEL CHO THIẾT BỊ KHÁC KẾT NỐI) VỚI TÊN: "+_wifiName);
        WiFi.softAP(_wifiName, _wifiPass);
        break;

    default:
        Serial.println("KHỞI CHẠI WIFI MODE STATION VÀ MODE ACCESS");
        Serial.println("STATION MODE: THIẾT BỊ KẾT NỐI TỚI WIFI TÊN: "+_wifiConnectName);
        Serial.println("ACCESS MODE: LÀ WIFI CHO CÁC THIẾT BỊ KHÁC KÊT NỐI VỚI TÊN: "+_wifiName);
        WiFi.begin(_wifiConnectName, _wifiConnectPass);
        WiFi.softAP(_wifiName, _wifiPass);
        break;
    }
}

void MY_TOOL::setNameWifi(String name)
{
    _wifiName = name;
}

void MY_TOOL::setPassWifi(String pass)
{
    _wifiPass = pass;
}

void MY_TOOL::setNameWifiConnect(String name)
{
    _wifiConnectName = name;
}

void MY_TOOL::setPassWifiConnect(String pass)
{
    _wifiConnectPass = pass;
}

void MY_TOOL::setMode(WiFiMode mode)
{
    _wifiMode = mode;
}

WiFiMode MY_TOOL::getMode()
{
    return _wifiMode;
}

wl_status_t MY_TOOL::getStatus()
{
    return WiFi.status();
}

IPAddress MY_TOOL::getWifiIP()
{
    switch (_wifiMode)
    {
    case WIFI_AP:
        return WiFi.softAPIP();
        break;
    case WIFI_STA:
        return WiFi.localIP();
        break;

    default:
        return WiFi.softAPIP();
        break;
    }
}

String MY_TOOL::getModeToString()
{
    switch (_wifiMode)
    {
    case WIFI_AP:
        return "WIFI ACCESS MODE";
        break;
    case WIFI_STA:
        return "WIFI STATION MODE";
        break;

    default:
        return "WIFI ACCESS MODE VÀ STATION MODE";
        break;
    }
}

void MY_TOOL::debug()
{
    Serial.println();
    Serial.println("WiFi Name: " + _wifiName);
    Serial.println("WiFi Pass: " + _wifiPass);
    Serial.println("WiFi Mode: " + getModeToString());
    Serial.print("WiFi Name: ");
    Serial.println(getWifiIP());
}

#endif