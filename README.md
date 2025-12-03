# Project1-Google-Home-Automation-with-Voice-control LED
Light that can be controlled using Voice and Google Assistant


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
Component	Purpose
ESP32	Main microcontroller
Relay module	Switches AC power to the light
Light bulb	Controlled load
Jumper wires	Electrical connections
#  ESP32 Pinout
Pin	Description
GPIO 5	Relay control pin
VCC	Relay power (typically 5V or 3.3V depending on your module)
GND	Ground

 Note: Most relay modules are Active LOW (LOW = ON, HIGH = OFF).

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

Replace:

"" const char* WIFI_SSID = ""; ""

"" const char* WIFI_PASS = ""; ""

