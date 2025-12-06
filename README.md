# Project1 — Google Home Automation with Voice-Controlled LED 

Control your home lighting using Google Assistant, Sinric Pro, and an ESP32.
This project demonstrates how to turn a light bulb ON/OFF via voice commands, using a relay connected to the ESP32 as the switching interface.

#  Overview

This project integrates:

Sinric Pro IoT platform

Google Home voice assistant

ESP32 microcontroller

Once configured, you can say:

“Hey Google, turn ON the light.”

The ESP32 receives the command through Sinric Pro and switches the connected relay, which controls an AC-powered light bulb.

#  Architecture

Google Home → Sinric Pro Cloud → ESP32 → Relay Module → Light Bulb

The ESP32 runs a lightweight loop where it listens for events (ON/OFF) from Sinric and toggles GPIO5 accordingly.

#  Hardware Used
## Component	Purpose

ESP32	Main microcontroller

Relay module	Switches AC power to the light

Light bulb	Controlled load

Jumper wires	Electrical connections

## ESP32 Pinout

##Pin	Description

GPIO 5	Relay control pin

VCC	Relay power (typically 5V or 3.3V depending on your module)

GND	Ground

 Note: Most relay modules are Active LOW (LOW = ON, HIGH = OFF).

 ```

ESP32 VCC -> Relay VCC

ESP32 GND -> Relay GND

ESP32 GPIO D5 -> Relay Input


```

#  Software / Platforms Used

Arduino IDE

Sinric Pro IoT Platform

Google Home

#  Setup Instructions
## 1️. Sinric Pro Setup

Create a device of type Switch or Smart Plug

Copy the:

APP Key

APP Secret

Device ID

## 2️. Google Home

Connect your Sinric Pro account

Assign the device

Name it: Light, Room Lamp, etc.

## 3️. ESP32 Firmware

Open Arduino IDE

Install:

WiFi library (default with ESP32 core)

SinricPro Library (through Library Manager)

## Replace the below details in code with your Wifi SSID and Password

```
const char* WIFI_SSID = ""; 
const char* WIFI_PASS = "";

```
## Replace the below details in code with the API, Device Id , App secret details of your Sinric Pro Account:

```
#define APP_KEY    ""
#define APP_SECRET ""
#define DEVICE_ID ""

```

# How Voice Control Works

You speak a command:

"Hey Google, turn on the light"

Google Home sends the request → Sinric Pro cloud

Sinric forwards the command to the ESP32

ESP32:

Executes callback onPowerState

Switches GPIO5 → Relay toggles

Bulb turns ON/OFF

# Safety Warning

 Relay controls HIGH VOLTAGE AC.

Always isolate AC and low-voltage (ESP32) circuits.

Never touch wiring while powered.

Use proper casing, connectors, and fuses.

# Project Status

1. Working prototype
2. Voice control
3. Google Home integration
4. Future improvements:

# Author

Project Name: Google Home Automation with Voice-Controlled LED

Created by: Shiva Panjugula

Feel free to fork, improve, and experiment!

