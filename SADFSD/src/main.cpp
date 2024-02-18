#include <Arduino.h>
#include <my_library.h>
#include <ESP8266WiFi.h>

const int timeoutTime = 2000;

/**
 * KHAI BÁO BIẾN SERVER VỚI CỔNG KẾT NỐI 80
*/
WiFiServer server(80);


void wifiSetUp();

void setup() {
  Serial.begin(115200);
  wifiSetUp();
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if(client){
    
  }
}

void wifiSetUp(){
  Serial.print("Mời bạn kết nối vơi wifi tên: ");
  Serial.println(DEFAULT_WIFI_NAME);
  WiFi.begin(DEFAULT_WIFI_NAME, DEFAULT_WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Wifi đã được kết nối với địa chỉ IP: ");
  Serial.println(WiFi.localIP());
}