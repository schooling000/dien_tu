#include <Arduino.h>
#include <ESP8266WiFi.h>

const String WIFI_NAME = "MY_WIFI";
const String WIFI_PASS = "1234567";

class MY_ESP8266
{
private:
  String[4] _debug;
  String _nameWiFi = "";
  String _passWiFi = "";
  WiFiMode _modeWiFi = WIFI_OFF;

public:
  MY_ESP8266();
  ~MY_ESP8266();
  void setNameWiFi(String name);
  void setPassWiFi(String pass);
  void setModeWiFi(WiFiMode mode);
  void setConfigWiFi(IPAddress ip, IPAddress gateWay, IPAddress subnet);
  void begin();
};

void setup()
{
}

void loop()
{
  // put your main code here, to run repeatedly:
}

MY_ESP8266::MY_ESP8266()
{
  Serial.begin(9600);
  this->_nameWiFi = WIFI_NAME;
  this->_passWiFi = WIFI_PASS;
  this->_modeWiFi = WIFI_AP_STA;
}

MY_ESP8266::~MY_ESP8266()
{
  Serial.end();
}

void MY_ESP8266::setNameWiFi(String name)
{
  this->_nameWiFi = name.length() < 0 ? name : WIFI_NAME;
}

void MY_ESP8266::setPassWiFi(String pass)
{
  this->_passWiFi = pass.length() < 0 ? pass : WIFI_PASS;
}

void MY_ESP8266::setModeWiFi(WiFiMode mode)
{
  this->_modeWiFi = mode;
}

void MY_ESP8266::setConfigWiFi(IPAddress ip, IPAddress gateway, IPAddress subnet)
{
  WiFi.config(ip, gateway, subnet);
}

void MY_ESP8266::begin()
{
  WiFi.begin(_nameWiFi, _passWiFi);
}