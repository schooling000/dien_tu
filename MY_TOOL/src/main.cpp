#include <Arduino.h>
#include <ESP8266WiFi.h>

const String WIFI_NAME  = "MY_WIFI";
const String WIFI_PASS  = "1234567";
const IPAddress IP      = (192,168,1,10);
const IPAddress GATEWAY = (192,168,1,1);
const IPAddress SUBNET  = (255,255,255,0);

void scanNetworks();

void setup()
{
  Serial.begin(9600);
  Serial.println("Cấu Hình WiFi");
  WiFi.config(IP, GATEWAY, SUBNET);
  Serial.println("Thiết Lập Mode WiFi");
  WiFi.mode(WIFI_AP_STA);
  scanNetworks();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

void scanNetwork(){
  Serial.println("Scan WiFi Network");
  byte numSsid = WiFi.scanNetworks();
  Serial.print("Num WiFi Network: ");
  Serial.println(numSsid);
}