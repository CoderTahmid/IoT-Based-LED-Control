/*************************************************************
  Blynk LED Control with ESP32
  This code allows you to control an LED from the Blynk Cloud.
*************************************************************/

#if __has_include("secrets.h")
  #include "secrets.h"
#else
  // Blynk Template Information
  #define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
  #define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
  #define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

  // WiFi Credentials
  const char ssid[] = "YOUR_WIFI_NAME";
  const char pass[] = "YOUR_WIFI_PASSWORD";
#endif

// Include Required Libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the LED Pin
const int ledPin = 23;

// This function runs when the Blynk switch (Virtual Pin V0) changes state
BLYNK_WRITE(V0)
{
  int switchState = param.asInt();  // Read the value from the Blynk switch

  if (switchState == 1)
  {
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    Serial.println("LED ON");
  }
  else
  {
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    Serial.println("LED OFF");
  }
}

void setup()
{
  // Start Serial Monitor
  Serial.begin(115200);

  // Initialize LED Pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure LED is OFF initially

  // Connect to Blynk Cloud
  Serial.println("Connecting to WiFi and Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  // Run Blynk
  Blynk.run();
}
