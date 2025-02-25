#include <MY_ESP8266_WIFI.h>

MY_ESP8266_WIFI esp8266_modemcu;

void setup(){
  esp8266_modemcu.debug();
  esp8266_modemcu.getDataDTH11Sensor(4);
}
 
void loop(){

}