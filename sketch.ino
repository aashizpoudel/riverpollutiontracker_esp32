#include <WiFi.h>
#include <WiFiClient.h>
#include "Arduino.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
// #include "ESP32MQTTClient.h"


// Test Mosquitto server, see: https://test.mosquitto.org
char *server = "mqtt://broker.hivemq.com:1883";

char *subscribeTopic = "foo";
char *publishTopic = "bsen860/tds";
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, "broker.hivemq.com", 1883);

Adafruit_MQTT_Publish photocell = Adafruit_MQTT_Publish(&mqtt,"bsen860/tds");

// void MQTT_connect();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  // mqttClient.loopStart();

}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }

  Serial.println("MQTT Connected!");
}

void loop() {
  // put your main code here, to run repeatedly:
  MQTT_connect();
  // Serial.print("Analog: ");?
  int data = analogRead(36);
  data = 1000*data/4095; // Conversion of 12 bit value to tds range of 0 to 1000 ppm.
  photocell.publish((uint32_t)data);
  Serial.print("Published:");
  Serial.println(data);
  delay(1000); // this speeds up the simulation
}
