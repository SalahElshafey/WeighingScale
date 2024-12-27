#include <ESP8266WiFi.h>  // Use <WiFi.h> for ESP32
#include <PubSubClient.h>
#include <HX711.h>

// Wi-Fi credentials
const char* ssid = "Ali Gaber";
const char* password = "Aligaber24!";

// MQTT broker
const char* mqtt_server = "broker.hivemq.com"; // Public broker
const char* topic = "weight_monitoring";      // Topic for publishing weight data

WiFiClient espClient;
PubSubClient client(espClient);

HX711 scale;

// HX711 pins
#define DT D5
#define SCK D6

void setup() {
  Serial.begin(9600);

  // Initialize HX711
  scale.begin(DT, SCK);

  // Connect to Wi-Fi
  connectToWiFi();

  // Set up MQTT broker
  client.setServer(mqtt_server, 1883);
  connectToMQTT();
}

void loop() {
  // Reconnect if disconnected
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();

  // Read weight data from HX711
  if (scale.is_ready()) {
    long weight = scale.get_units(10); // Get average of 10 readings
    String weightString = String(weight);
    Serial.println("Weight: " + weightString);

    // Publish to MQTT topic
    client.publish(topic, weightString.c_str());
  } else {
    Serial.println("HX711 not ready.");
  }
  delay(1000); // Delay between readings
}

void connectToWiFi() {
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected!");
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (client.connect("ESPClient")) {
      Serial.println("Connected to MQTT!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
