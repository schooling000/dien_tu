#include "MY_TOOL.h"

MY_TOOL module;

void setup()
{
  module.setNameWifiConnect("Thanh lộc 1");
  module.setPassWifiConnect("0972001445");
  module.begin();
  if (module.getMode() == WIFI_STA || module.getMode() == WIFI_AP_STA)
  {
    Serial.println("Kết nối Wifi");
    while (module.getStatus() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println();
    Serial.print("Kết nối thành công, IP address: ");
    Serial.println(module.getWifiIP());
  }
}

void loop()
{
}