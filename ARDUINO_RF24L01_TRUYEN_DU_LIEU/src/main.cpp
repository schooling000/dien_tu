#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <RF24.h>

//  ĐỊNH NGHĨA CHÂN KẾT NỐI VỚI CẢM BIẾN ĐỘ ẨM ĐẤT
const int SOIL_SENSOR = A2;

// ĐỊNH NGHĨA CHÂN KẾT NỐI VỚI CẢM BIẾN DHT
// ĐỊNH NGHĨA KIỂU CỦA CẢM BIẾN
const int DHT_SENSOR_PIN = 2;
const int DHT_SENSOR_TYPE = DHT11;

// ĐỊNH NGHĨA CHÂN KẾT NỐI VỚI RF24L01
const int CE_PIN = 7;
const int CSN_PIN = 8;
const byte RADIO_ADDRESS = 1;
const byte RADIO_CHANNEL = 3;

struct DATA
{
  float temperature;
  float humidity;
  int soil_value;
};

RF24 RADIO_SENSOR(CE_PIN, CSN_PIN);
DHT DHT_SENSOR(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
DATA DATA_SENSOR;

void setup()
{
  Serial.begin(9600);

  Serial.println("Khởi tạo cảm biến DHT");
  DHT_SENSOR.begin();

  Serial.println("Khởi tạo cảm biến độ ẩm đất");
  pinMode(SOIL_SENSOR, INPUT);

  Serial.println("Khởi tạo module RF24L01");
  RADIO_SENSOR.begin();
  RADIO_SENSOR.setPALevel(RF24_PA_MIN);
  RADIO_SENSOR.setChannel(RADIO_CHANNEL);
  RADIO_SENSOR.openWritingPipe(RADIO_ADDRESS);
  RADIO_SENSOR.stopListening();
}

void loop()
{
  float temperature = DHT_SENSOR.readTemperature();
  float humidity = DHT_SENSOR.readHumidity();
  int value = analogRead(SOIL_SENSOR);

  if (isnan(temperature) || isnan(humidity) || isnan(value))
  {
    Serial.println("Không đọc được dữ liệu từ cảm biến DHT");
  }
  else
  {
    DATA_SENSOR.temperature = temperature;
    DATA_SENSOR.humidity = humidity;
    DATA_SENSOR.soil_value = value;
    Serial.println("");
    Serial.print("Nhiệt độ: ");
    Serial.println(DATA_SENSOR.temperature);
    Serial.print("Độ ẩm: ");
    Serial.println(DATA_SENSOR.humidity);
    Serial.print("Độ ẩm đất: ");
    Serial.println(DATA_SENSOR.soil_value);
    Serial.println("Đã gởi dữ liệu đi");
    RADIO_SENSOR.write(&DATA_SENSOR,sizeof(DATA_SENSOR));
    Serial.println("");
    delay(5000);
  }

}
