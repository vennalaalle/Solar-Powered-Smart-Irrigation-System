# Solar Powered Smart Irrigation System

## Overview

This project implements a solar-powered smart irrigation system using Arduino and various sensors to optimize water usage in agriculture. The system monitors soil moisture levels and controls a water pump accordingly to maintain optimal moisture conditions for crops. It also integrates IoT functionality using the ESP8266 WiFi module.

## Components

- Arduino Mega 2560
- Soil Moisture Sensor
- Temperature Sensor (LM35)
- Humidity Sensor
- Solar Panel
- L293D Motor Driver
- Water Pump
- ESP8266 WiFi Module

## Setup

1. **Hardware Connections:**

   - Connect the Soil Moisture Sensor, Temperature Sensor, and Humidity Sensor to the Arduino.
   - Connect the Water Pump to the L293D Motor Driver and then to the Arduino.
   - Power the system using a solar panel and batteries.
   - Connect the ESP8266 module for IoT functionality.

2. **Arduino Code:**

   - The Arduino code is located in the `CODE/main.ino` file.
   - Upload the code to the Arduino Mega 2560 using the Arduino IDE.

3. **ThingSpeak Configuration:**
   - Configure your ThingSpeak account to receive data from the ESP8266 module.
   - Replace the placeholder API keys in the code with your ThingSpeak API keys.

## Usage

Once the hardware is set up and the code is uploaded:

- The system will automatically monitor soil moisture levels.
- When moisture levels drop below the threshold, the pump will activate and irrigate the field.
- Data is sent to ThingSpeak for remote monitoring.

## Results

- The system efficiently manages irrigation, conserving water by only irrigating when necessary.
- The results can be viewed on ThingSpeak.

## Contributing

Feel free to fork this repository and submit pull requests for any improvements.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
