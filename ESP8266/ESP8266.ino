
#include <ESP8266WiFi.h>

const char *WIFI_NAME   = "MY_WIFI";
const char *WIFI_PASS   = "1234567";
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
}

void loop()
{
  scanNetworks();
}

void scanNetworks(){
  Serial.println("===================================================");
  Serial.println("Scan WiFi Network");

  byte numSSID = WiFi.scanNetworks();

  Serial.printf("Num WiFi Network: %d\n",numSSID);

  for(int index = 0; index < (numSSID -1); index++){
    Serial.printf("SSID NAME: %s\n",WiFi.SSID(index).c_str());
  }  
  Serial.println("===================================================");
  
}