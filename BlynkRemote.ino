#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk App Project Auth Token.
char auth[] = "";
// WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

#define EspSerial Serial1
#define ESP8266_BAUD 115200

#define PIN_OPEN 5
#define PIN_CLOSE 4
#define PIN_UNLOCK 0
#define PIN_LOCK 14
#define PIN_CONNECTED 2

void doorOpen(int pinValue) {
  digitalWrite(PIN_OPEN, pinValue);
}
void doorClose(int pinValue) {
  digitalWrite(PIN_CLOSE, pinValue);
}
void doorUnlock(int pinValue) {
  digitalWrite(PIN_UNLOCK, pinValue);
}
void doorLock(int pinValue) {
  digitalWrite(PIN_LOCK, pinValue);
}

BLYNK_WRITE(V1) {  
  doorOpen(param.asInt());
}
BLYNK_WRITE(V2) {
  doorClose(param.asInt());
}
BLYNK_WRITE(V3) {
  doorUnlock(param.asInt());
}
BLYNK_WRITE(V4) {
  doorLock(param.asInt());
}

void setup() {
  Serial.begin(ESP8266_BAUD);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  pinMode(PIN_OPEN, OUTPUT);
  pinMode(PIN_CLOSE, OUTPUT);
  pinMode(PIN_UNLOCK, OUTPUT);
  pinMode(PIN_LOCK, OUTPUT); 
  pinMode(PIN_CONNECTED, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  if (Blynk.connected()) {
    digitalWrite(PIN_CONNECTED, HIGH);
  } else {
    digitalWrite(PIN_CONNECTED, LOW);
  }
  
}
