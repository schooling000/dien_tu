#include <MY_ESP8266_WIFI.h>

MY_ESP8266_WIFI::MY_ESP8266_WIFI()
{
    Serial.begin(9600);
    Serial.println("Khởi động Chế độ giao tiếp với máy tính Serial Monitor.");
    delay(1000);

    _ssid = DEFAULT_WIFI_NAME;
    _pass = DEFAULT_WIFI_PASS;
    Serial.println("Khởi tạo tên wifi và mật khẩu wifi mặt định cho thiết bị .");
    delay(1000);

    WiFi.mode(WiFiMode::WIFI_AP_STA);
    Serial.println("Khởi tạo ESP8266 chạy với chế độ STATION MODE VÀ ACCESS MODE.");
    delay(100);

    WiFi.softAP(_ssid, _pass);
    Serial.print("Khởi tạo ACCESS MODE với id là: ");
    Serial.print(WiFi.softAPIP());
    Serial.println();
    delay(1000);
}

MY_ESP8266_WIFI::~MY_ESP8266_WIFI()
{
}

void MY_ESP8266_WIFI::debug()
{
    Serial.println("======================DEBUG======================");
    Serial.printf("ESP8266 đang ở chế độ: %c \n",getMode(WiFi.getMode()));
    Serial.printf("ESP8266 có tên wifi ở chế độ ACCESS MODE là: %s \n",WiFi.softAPSSID());
    Serial.printf("ESP8266 có pass wifi ở chế độ ACCESS MODE là: %s \n",WiFi.softAPPSK());
    Serial.printf("ESP8266 đang ở chế độ: %c",getMode(WiFi.getMode()));
    Serial.println("=================================================");
}

void MY_ESP8266_WIFI::setWifiNameInAccessMode(char *ssid)
{
    _ssid = ssid;
}

void MY_ESP8266_WIFI::setWifiPassInAccessMode(char *pass)
{
    _pass = pass;
}

void MY_ESP8266_WIFI::getDataDTH11Sensor(int pin)
{
    DynamicJsonDocument data(200);
    String strData;

    DHT SENSOR(pin, DHT11);
    SENSOR.begin();
    float H = SENSOR.readHumidity();
    float T = SENSOR.readTemperature();
    if (isnan(H) || isnan(T)){
        data["sensor_name"]="DHT11";
        data["sensor_status"]="error";
        data["sensor_data"]['Humidity']= 0;
        data["sensor_data"]['Temperature']= 0;
    }else{
        data["sensor_name"]="DHT11";
        data["sensor_status"]="error";
        data["sensor_data"]['Humidity']= H;
        data["sensor_data"]['Temperature']= T;
    }
    serializeJson(data, strData);
    Serial.print(strData);
}

char *MY_ESP8266_WIFI::getMode(int mode)
{
    switch (mode)
    {
    case 1:
        return "STATION MODE";
        break;
    case 2:
        return "ACCESS MODE";
        break;
    case 3:
        return "ACCESS VÀ STATION MODE";
        break;

    default:
        return "WIFI OFF";
        break;
    }
}
