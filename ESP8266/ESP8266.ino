
#include <ESP8266WiFi.h>
#include "ESP8266_MODULE.h"

const char *WIFI_NAME = "MY_WIFI";
const char *WIFI_PASS = "1234567";
const IPAddress IP = (192, 168, 1, 10);
const IPAddress GATEWAY = (192, 168, 1, 1);
const IPAddress SUBNET = (255, 255, 255, 0);

ESP8266_MODULE module;


void scanNetworks();

void setup() {
  module.setMode(WiFiMode::WIFI_AP);
  module.moduleConfig((192, 168, 1, 10), (192, 168, 1, 1), (255, 255, 255, 0));
  module.setSSID("thanh lộc 1");
  module.setSSIDPass("0972001445");
  module.moduleStart();
}

void loop() {
}




void scanNetworks() {
  Serial.println("===================================================");
  Serial.println("Scan WiFi Network");

  byte numSSID = WiFi.scanNetworks();

  Serial.printf("Num WiFi Network: %d\n", numSSID);

  for (int index = 0; index < (numSSID - 1); index++) {
    Serial.printf("SSID NAME: %s\n", WiFi.SSID(index).c_str());
  }
  Serial.println("===================================================");
}