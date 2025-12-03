#include <WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

// Relay pin
#define RELAY_PIN 5 // GPIO 5 is idle for Relay

// WiFi credentials
const char* WIFI_SSID = "";  // Give Your Wifi Name in Parenthesis
const char* WIFI_PASS = "";  // Give Your Wifi Password in Parenthesis

// SinricPro credentials
#define APP_KEY    "d2fc2beb-5c57-41d8-86bc-955d375d8e84"
#define APP_SECRET "9e4856b4-428a-4034-adda-d2ca6d24dc81-5c26e71a-b2fc-4f5d-98b7-06e42aead211"
#define DEVICE_ID "692f7ba26dbd335b28ec5a7b"

bool onPowerState(const String &deviceId, bool &state) {

  // Print the device ID and new state ("ON" or "OFF") to the serial monitor
  // state == true  → user requested power ON
  // state == false → user requested power OFF
  Serial.printf("Device %s turned %s\r\n", deviceId.c_str(), state ? "ON" : "OFF");

  // Control the relay.
  // Many relay modules are "Active LOW":
  //  LOW Signal  -> Relay ON  (circuit closed / power ON)
  //  HIGH Signal -> Relay OFF (circuit open  / power OFF)
  //
  // If state == true  ->  (write LOW) -> turn ON 
  // If state == false ->  (write HIGH) -> turn OFF
  digitalWrite(RELAY_PIN, state ? LOW : HIGH);

  // Return true to acknowledge to SinricPro that the command was processed successfully
  return true;
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // OFF

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  SinricProSwitch &mySwitch = SinricPro[DEVICE_ID];
  mySwitch.onPowerState(onPowerState);
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle();
}
