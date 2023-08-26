#ifndef ESP8266_MODULE_H
#define ESP8266_MODULE_H

#include<ESP8266WiFi.h>
#include <ESP8266WebServer.h>

class ESP8266_MODULE {
private:
  char *_name;
  char *_pass;
  WiFiMode _mode;
public:
  ESP8266_MODULE();
  ~ESP8266_MODULE();
  void moduleConfig(IPAddress ip, IPAddress gateway, IPAddress subnet);
  void moduleStart();
  void setMode(WiFiMode mode);
  void setSSID(char *ssid);
  void setSSIDPass(char *pass);
  void moduleDebug();
};

#endif