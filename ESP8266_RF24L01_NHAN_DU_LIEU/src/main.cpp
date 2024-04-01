#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

// ĐỊNH NGHĨA CHÂN KẾT NỐI VỚI RF24L01
const int CE_PIN = D4;
const int CSN_PIN = D2;
const byte RADIO_ADDRESS = 1;
const byte RADIO_CHANNEL = 3;

struct DATA
{
  float temperature;
  float humidity;
  int soil_value;
};

RF24 RADIO_SENSOR(CE_PIN, CSN_PIN);
DATA DATA_SENSOR;

void setup()
{
  Serial.begin(9600);
  Serial.println("Khởi tạo module RF24L01");
  RADIO_SENSOR.begin();
  RADIO_SENSOR.setPALevel(RF24_PA_MIN);
  RADIO_SENSOR.setChannel(RADIO_CHANNEL);
  RADIO_SENSOR.openReadingPipe(1, RADIO_ADDRESS);
  RADIO_SENSOR.startListening();
  if (!RADIO_SENSOR.available())
  {
    Serial.println("Chưa kết nối được với RF24L01 PHÁT");
    while (!RADIO_SENSOR.available())
    {
      Serial.print(".");
      delay(100);
    }    
  }else{
    Serial.println("Kết nối với RF24L01 phát thành công");
  }
}

void loop()
{
  while (RADIO_SENSOR.available())
  {
    RADIO_SENSOR.read(&DATA_SENSOR, sizeof(DATA_SENSOR));
    Serial.println("");
    Serial.print("Nhiệt độ: ");
    Serial.println(DATA_SENSOR.temperature);
    Serial.print("Độ ẩm: ");
    Serial.println(DATA_SENSOR.humidity);
    Serial.print("Độ ẩm đất: ");
    Serial.println(DATA_SENSOR.soil_value);
    Serial.println("");
    delay(5000);
  }
}
