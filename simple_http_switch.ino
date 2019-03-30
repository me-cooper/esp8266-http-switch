#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

const char* ssid = "WLAN_SSID";
const char* password = "WLAN_PASSWORD";

// following for the name of: http://name_esp.local/ 
const char* dns_name = "esp8266";

int relay_pin = 5; //D1

void setup()
{
  pinMode(relay_pin, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP Gestartet");

  WiFi.begin(ssid, password);

  Serial.print("Verbindung wird hergestellt ...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Verbunden! IP-Adresse: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(dns_name)) {
    Serial.println("DNS gestartet, erreichbar unter: ");
    Serial.println("http://" + String(dns_name) + ".local/");
  }

  server.onNotFound([](){
    server.send(404, "text/plain", "Link wurde nicht gefunden!");  
  });

  server.on("/", []() {
    server.send(200, "text/plain", "ESP-Startseite!");
  });

  server.on("/relay_on", []() {
    server.send(200, "text/plain", "relay on");
    relay_on();
  });

  server.on("/relay_off", []() {
    server.send(200, "text/plain", "relay off");
    relay_off();
  });

  server.on("/state", []() {
    server.send(200, "text/plain", String(digitalRead(relay_pin)));
  });

  server.begin();
  Serial.println("Webserver gestartet.");
}

void loop() {
  server.handleClient();  
}

void relay_on(){
  digitalWrite(relay_pin, HIGH);  
}


void relay_off(){
  digitalWrite(relay_pin, LOW);    
}
