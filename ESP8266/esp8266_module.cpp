#include "ESP8266_MODULE.h"

ESP8266_MODULE::ESP8266_MODULE() {
  Serial.begin(9600);
  Serial.println("===========================================================");
  Serial.println("Khởi Tạo Module Esp8266");
  _name = "ESP8266_MODULE";
  _pass = "123456";
  _mode = WiFiMode::WIFI_OFF;
}

ESP8266_MODULE::~ESP8266_MODULE() {
  _mode = WiFiMode::WIFI_OFF;
  Serial.println("===========================================================");
  Serial.end();
}

void ESP8266_MODULE::moduleConfig(IPAddress ip, IPAddress gateway, IPAddress subnet) {
  switch (_mode) {
    case WiFiMode::WIFI_AP:
      Serial.println("Cấu Hình Lại Thông Số Module Esp8266 Ở Chế Độ Điểm Truy Cập");
      WiFi.config(ip, gateway, subnet);
      break;
    case WiFiMode::WIFI_STA:
      Serial.println("Cấu Hình Lại Thông Số Module Esp8266 Ở Chế Độ Trạm Truy Cập");
      WiFi.softAPConfig(ip, gateway, subnet);
      break;
    case WiFiMode::WIFI_AP_STA:
      Serial.println("Cấu Hình Lại Thông Số Module Esp8266 Ở Chế Độ Điểm Truy Cập Và Trạm Truy Cập");
      WiFi.config(ip, gateway, subnet);
      WiFi.softAPConfig(ip, gateway, subnet);
      break;
  }
}

void ESP8266_MODULE::moduleStart() {
  switch (_mode) {
    case WiFiMode::WIFI_AP:
      Serial.printf("Khởi Tạo Một Điểm Kết Nối Có Tên: %s", _name);
      Serial.println("");
      WiFi.softAP(_name, _pass);
      Serial.print("Điểm Kết Nối Có IP Là: ");
      Serial.println(WiFi.softAPIP());
      break;
    case WiFiMode::WIFI_STA:
      Serial.printf("Khởi Tạo Kết Nối WiFi Tới WiFi Tên: %s", _name);
      Serial.println("");
      WiFi.begin(_name, _pass);
      int index;
      index = 0;
      while (WiFi.status() != WL_CONNECTED && index < 50) {
        delay(500);
        Serial.print(".");
        index++;
      }

      Serial.println();

      if (WiFi.isConnected()) {
        Serial.printf("Kết Nối Thành Công Vơi WiFi %s Có IP Là: ", _name);
        Serial.println(WiFi.localIP());
      } else {
        Serial.printf("Kết Không Thành Công Vơi WiFi: %s", _name);
      }
      break;
    case WiFiMode::WIFI_AP_STA:
      Serial.printf("Khởi Tạo Một Điểm Kết Nối Có Tên: %s Và Khởi Tạo Kết Nối WiFi Tới WiFi Tên: %s", _name);
      Serial.println("");
      WiFi.begin(_name, _pass);
      WiFi.softAP(_name, _pass);
      Serial.print("Điểm Kết Nối Có IP Là: ");
      Serial.println(WiFi.softAPIP());
      Serial.print("WiFi Đã Kết Nối Có IP Là: ");
      Serial.println(WiFi.localIP());
      break;
  }
}

void ESP8266_MODULE::setMode(WiFiMode mode) {
  Serial.println("Thiết Lập Mode Làm Việc Mới Cho WiFi");
  _mode = mode;
}

void ESP8266_MODULE::setSSID(char *ssid) {
  if (ssid != NULL) {
    _name = ssid;
  }
}

void ESP8266_MODULE::setSSIDPass(char *pass) {
  if (pass != NULL) {
    _pass = pass;
  }
}

void ESP8266_MODULE::moduleDebug() {
  Serial.println();
  Serial.println("DEBUG MODULE ESP8266");
  Serial.printf("NAME MODULE ESP8266 LÀ: %s", _name);
  Serial.printf("PASS MODULE ESP8266 LÀ: %s", _pass);
  switch (_mode) {
    case WiFiMode::WIFI_AP:
      Serial.println("MODULE ESP8266 Ở MODE WIFI_AP");
      break;
    case WiFiMode::WIFI_STA:
      Serial.println("MODULE ESP8266 Ở MODE WIFI_STA");
      break;
    case WiFiMode::WIFI_AP_STA:
      Serial.println("MODULE ESP8266 Ở MODE WIFI_AP_STA");
      break;
  }
}
