#include <WiFi.h>

const char* ssid     = "";
const char* password = "";

WiFiServer server(80);
const int LED = 13;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Open this in your browser: http://");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.readStringUntil('\n');

  if (request.indexOf("/on") != -1)  digitalWrite(LED, HIGH);
  if (request.indexOf("/off") != -1) digitalWrite(LED, LOW);

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println("<!DOCTYPE html><html><head>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
  client.println("<style>a{display:block;font-size:40px;padding:30px;margin:20px;");
  client.println("background:#222;color:#fff;text-decoration:none;text-align:center;}</style>");
  client.println("</head><body><h1>ESP32 LED</h1>");
  client.println("<a href='/on'>TURN ON</a>");
  client.println("<a href='/off'>TURN OFF</a>");
  client.println("</body></html>");

  client.stop();
}