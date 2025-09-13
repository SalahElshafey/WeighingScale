# WeighingScale – IoT Weight Monitoring System

An IoT-enabled smart weighing system built using **ESP8266**, **HX711 load cell**, and **MQTT protocol**, with real-time data visualization via a **Flask web app**.  

The system is designed to measure weight, process the data on the ESP8266 microcontroller, and publish readings to an MQTT broker. A Python Flask server subscribes to the broker, streams live updates to the web interface, and enables seamless monitoring from anywhere.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Software Components](#software-components)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Benefits](#benefits)
- [Future Enhancements](#future-enhancements)
- [Contributors](#contributors)
- [License](#license)

---

## Overview

The **WeighingScale** project addresses the need for remote and automated weight monitoring across industries such as **logistics, healthcare, and agriculture**.  

By leveraging **ESP8266 Wi-Fi connectivity**, **HX711 weight sensing**, and **MQTT lightweight messaging**, the system achieves reliable, low-cost, and scalable real-time weight monitoring.

---

## Features

- **Real-time weight monitoring** with averaged sensor readings (10 samples for accuracy).  
- **Wi-Fi connectivity** with automatic reconnection for robustness.  
- **MQTT-based communication** using the `weight_monitoring` topic.  
- **Flask web interface** for live visualization of weight data.  
- **Debugging support** via Serial Monitor for ESP8266.  
- **Lightweight and scalable** IoT design with low hardware cost.  

---

## System Architecture

1. **ESP8266** connects to Wi-Fi, reads weight from HX711, and publishes readings to **HiveMQ public MQTT broker**.  
2. **MQTT broker** manages topic-based message exchange (`weight_monitoring`).  
3. **Flask web server** subscribes to MQTT and streams weight updates to a live web dashboard.  

---

## Hardware Components

- **ESP8266 microcontroller** – Wi-Fi-enabled IoT controller.  
- **HX711 load cell amplifier** – Converts load cell analog signals to digital.  
- **Load Cell** – Measures applied weight.  
- **USB power supply** – Powers the ESP8266.  

**Pin configuration:**  
- HX711 `DT → D5`  
- HX711 `SCK → D6`  

---

## Software Components

### Arduino (ESP8266 firmware)
- **Language:** C++ (Arduino IDE)  
- **Libraries:**  
  - `ESP8266WiFi.h` – Wi-Fi connectivity  
  - `PubSubClient.h` – MQTT communication  
  - `HX711.h` – Load cell data acquisition  

### Python Backend (Flask app)
Located in `script.py`:
- Subscribes to MQTT broker (`broker.hivemq.com`, port 1883).  
- Streams messages to Flask app via Server-Sent Events (SSE).  
- Serves a simple web dashboard (`index.html`) with real-time updates.  

---

## Project Structure

```
├── first_try.ino              # ESP8266 Arduino firmware
├── script.py                  # Flask + MQTT backend
├── WeightScalingreport.pdf    # Full technical report
├── Education Poster.jpg       # Project poster
├── templates/index.html       # Web dashboard (not included in upload)
├── .gitignore
└── README.md                  # Documentation
```

---

## Installation

### ESP8266 Setup
1. Open `first_try.ino` in Arduino IDE.  
2. Install required libraries:
   - ESP8266WiFi
   - PubSubClient
   - HX711  
3. Update Wi-Fi SSID & password in the code.  
4. Upload code to ESP8266.

### Flask Server Setup
```bash
# Clone the repo
git clone https://github.com/SalahElshafey/WeighingScale.git
cd WeighingScale

# Create a virtual environment
python -m venv env
source env/bin/activate   # Linux/Mac
env\Scripts\activate    # Windows

# Install dependencies
pip install flask paho-mqtt
```

Run the server:
```bash
python script.py
```
Access the dashboard at: `http://127.0.0.1:5000`

---

## Usage

1. Power up the ESP8266 with HX711 + load cell connected.  
2. The ESP8266 publishes weight data to the MQTT broker.  
3. Flask app subscribes to MQTT and streams live data to the web dashboard.  
4. Users monitor weights in real time from any browser.  

---

## Benefits

- **Remote accessibility** from anywhere with internet.  
- **Low-cost** solution using affordable components.  
- **Scalable** for integration with more IoT devices.  
- Applicable in **logistics, agriculture, healthcare**, and more.  

---

## Future Enhancements

- 🔒 **TLS encryption & authentication** for secure MQTT.  
- 🗄 **Data logging** in a database for trend analysis.  
- 📱 **Mobile/web apps** with rich dashboards.  
- 📩 **Notification system** (email/SMS) for threshold alerts.  
- 🔋 **Power optimization** for portable deployments.  

---

## Contributors

- **Salaheldin Elshafey** – Developer  
- **Ali Gaber** – Developer  
- **Laila Labib** – Developer  
- **Hania Helmy** – Developer  

---

## License

This project is licensed under the [MIT License](LICENSE).
