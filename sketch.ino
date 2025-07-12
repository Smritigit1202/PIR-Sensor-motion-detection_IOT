#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* firebaseHost = "https://pir-system-default-rtdb.firebaseio.com";
const int pirPin = 13;
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
}

void sendMotionStatus(bool status) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(firebaseHost) + "/motion.json";
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    String payload = status ? "true" : "false";
    int httpResponseCode = http.PUT(payload);

    if (httpResponseCode > 0) {
      Serial.println("Firebase update successful");
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}

void loop() {
  bool motion = digitalRead(pirPin);

  digitalWrite(ledPin, motion);
  Serial.println(motion ? "Motion detected!" : "No motion");

  sendMotionStatus(motion);
  delay(1000); // Reduce frequency to avoid spamming Firebase
}
