#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32-C3_AP";
const char* password = "12345678";

WebServer server(80);

void handleRoot() {
  server.send(
    200,
    "text/html",
    "<!DOCTYPE html>"
    "<html>"
    "<head><title>ESP32-C3</title></head>"
    "<body style='text-align:center;font-family:Arial;'>"
    "<h1>Hallo ESP 👋</h1>"
    "<p>ESP32-C3 sebagai Access Point</p>"
    "</body>"
    "</html>"
  );
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
