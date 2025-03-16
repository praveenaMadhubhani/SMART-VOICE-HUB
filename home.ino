#define BLYNK_TEMPLATE_ID "TMPL6fXlVSUNW"
#define BLYNK_TEMPLATE_NAME "Home"
#define BLYNK_AUTH_TOKEN "EWyY7CJdSHZnHo3741WXvow2GutD_aQl"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace with your network credentials
char ssid[] = "Noname";
char pass[] = "1122334455";

// Define the relay pins
#define RELAY1_PIN D1
#define RELAY2_PIN D2
#define RELAY3_PIN D3
#define RELAY4_PIN D4 

// Initialize Blynk
BlynkTimer timer;

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set relay pins as output
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);

  // Ensure all relays are off initially (inactive state)
  digitalWrite(RELAY1_PIN, HIGH); // Active-Low: Set to HIGH to turn OFF
  digitalWrite(RELAY2_PIN, HIGH);
  digitalWrite(RELAY3_PIN, HIGH);
  digitalWrite(RELAY4_PIN, HIGH);
}

void loop() {
  // Run Blynk
  Blynk.run();

  // You can add a timer to check or update things periodically if needed
  timer.run();
}
 
// Virtual pins for controlling relays in Blynk app
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();  // Get the button state (0 or 1)
  digitalWrite(RELAY1_PIN, pinValue ? LOW : HIGH);  // Invert logic for Active-Low
}

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  digitalWrite(RELAY2_PIN, pinValue ? LOW : HIGH);
}

BLYNK_WRITE(V3) {
  int pinValue = param.asInt();
  digitalWrite(RELAY3_PIN, pinValue ? LOW : HIGH);
}

BLYNK_WRITE(V4) {
  int pinValue = param.asInt();
  digitalWrite(RELAY4_PIN, pinValue ? LOW : HIGH);
}
