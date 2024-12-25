# Air Defense System Project

This project demonstrates an Arduino-based Air Defense System using ultrasonic sensors for threat detection and response. The system uses various components to simulate the detection and engagement of targets.

## Features
- Detects objects using the HC-SR04 ultrasonic sensor.
- Controls two servo motors for targeting.
- Uses a laser diode to simulate target locking.
- Activates an LED and buzzer as alerts.

## Components Required
1. **Arduino Uno**
2. **Breadboard**  
3. **HC-SR04 Ultrasonic Sensor**  
4. **Servo Motors (2)**  
5. **Laser Diode**  
6. **LED**  
7. **Resistor 220 OHM**  
8. **Buzzer**
9. **Dual Axis XY Servo Bracket**

## Circuit Diagram
(Add a diagram or a link to the circuit design here if available)

## Installation and Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/achmadrzm/air_defense_system.git
2. Open the project in the Arduino IDE.
3. Connect the components as per the circuit diagram.
4. Upload the code to the Arduino Uno.
5. Power the Arduino and observe the system in action.

## How It Works
1. The ultrasonic sensor continuously scans for objects within its range.
2. If an object is detected, the servo motors adjust to target the object.
3. The laser diode, LED, and buzzer are activated to simulate the engagement process.
