# ESP32 MQTT Publisher

This project was developed for the course BSEN 860 (Instrumentation and Controls) at UNL. This project demonstrates how to use an **ESP32** to publish analog sensor data to an MQTT broker using the **Adafruit MQTT Library**. The code connects to Wi-Fi, reads from an analog pin, and publishes the data to a specified MQTT topic.

## Features
- Publishes analog sensor data (e.g., photocell or potentiometer readings) to the public MQTT broker.
- Uses the **Adafruit MQTT Library** for communication.
- Runs on ESP32 hardware with minimal setup.
- Simple webpage to visualize the published topic.

## Requirements
### Hardware
- ESP32 Development Board
- Analog sensor (e.g., photocell, potentiometer)
- Breadboard and jumper wires

### Software
- Arduino IDE (or PlatformIO)
- **Adafruit MQTT Library** (install from Library Manager)
- ESP32 Board Package for Arduino IDE

## Broker & Topic
- **Broker**: `broker.hivemq.com`  
- **Port**: `1883`  
- **Topic**: `bsen860/tds`  

## Setup
1. Connect the analog sensor to the ESP32:
   - Signal pin → `GPIO36` (VP)
   - VCC → `3.3V`
   - GND → `GND`
2. Install required libraries and upload the code using Arduino IDE.
3. Monitor the serial output for connection status and published data.

## Code Flow
1. Connects to the Wi-Fi network.
2. Establishes an MQTT connection to the broker.
3. Reads analog data from `GPIO36`.
4. Publishes the data to the topic: **bsen860/tds**.

## Simulation
Open [WokWi Project](https://wokwi.com/projects/416834940519585793) to simulate this project.
---


