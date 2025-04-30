Firefighting Robot 🚒🤖

An Arduino-powered autonomous firefighting robot that detects, navigates to, and extinguishes flames using embedded control logic—demonstrating automatic control systems in hazardous-task automation.

---

📌 Table of Contents

1. Overview


2. Features


3. Components Required


4. Circuit Diagram


5. Software Requirements


6. Installation & Setup


7. Usage


8. Code Structure & Snippets


9. How It Works


10. Project Structure


11. Team & Acknowledgements


12. License




---

Overview

This Firefighting Robot was developed as part of our control systems coursework. Equipped with a 5-channel flame sensor array, differential-drive DC motors, and a servo-controlled water pump, the robot autonomously:

Scans for fire sources

Navigates toward detected flames

Extinguishes fires by spraying water

Signals an alarm upon engagement


It illustrates how automatic control and embedded systems can replace hazardous tasks in industrial safety, disaster response, and smart infrastructures.


---

Features

Autonomous Flame Detection via digital flame sensors (LEFT, FORWARD, RIGHT)

Differential Drive using L298N (or L293D) motor driver

Servo-Controlled Nozzle for precision water targeting

Water Pump Activation through a relay module

Emergency Alarm with a buzzer

Modular Design: separate sensor and control logic modules for easy extension



---

Components Required

Arduino Uno

USB-A to Micro-USB cable

Car chassis kit

L298N motor driver module (or L293D alternative)

5-channel flame sensor module

Servo motor

Mini DC submersible water pump

Relay module

Buzzer

12V rechargeable battery pack

On/off power switch & DC female connector jack

Jumper wires and hookup cables

Soldering iron & solder wire

Hot melt glue gun & glue sticks



---

Circuit Diagram

L298N Motor Driver


---

Servo Motor


---

5-Channel Flame Sensor Module

> ⚠ Ensure all grounds (battery, Arduino, modules) are tied together.




---

Software Requirements

Arduino IDE (v1.8.x or later)

Libraries:

Servo.h

AFMotor.h (Adafruit Motor Shield) or equivalent

SoftwareSerial (if using serial comms)




---

Installation & Setup

1. Clone the repo

git clone https://github.com/<your-username>/firefighting-robot.git
cd firefighting-robot


2. Open firefighterRobot.ino in the Arduino IDE.


3. Install any missing libraries via Sketch → Include Library → Manage Libraries.


4. Wire components as per the Circuit Diagram.


5. Upload the code to your Arduino Uno.


6. Power the system with the 12V battery and switch on.




---

Usage

1. Place the robot in a test area with a safe flame source (e.g., candle or LED flame simulator).


2. It will patrol by default, scanning for fires.


3. On detecting a flame, it will navigate toward it.


4. Once in range, the pump activates and the servo sweeps to extinguish the fire.


5. The buzzer sounds to indicate engagement, then the robot resumes patrol.




---

Code Structure & Snippets

firefighterRobot.ino: Main sketch, initializes modules and loops

control_logic.h/.cpp: Motion control & firefighting routines

sensors.h/.cpp: Sensor initialization and flame detection functions


Key Snippet: Fire Suppression Routine

void put_off_fire(Servo &servo) {
  // Stop movement
  stopMotors();
  // Start pump
  digitalWrite(PUMP_PIN, HIGH);
  delay(500);
  // Sweep nozzle
  for (int pos = 50; pos <= 130; pos++) { servo.write(pos); delay(10); }
  for (int pos = 130; pos >= 50; pos--) { servo.write(pos); delay(10); }
  digitalWrite(PUMP_PIN, LOW);
  servo.write(90); // Center
}


---

How It Works

1. Initialization: Pins and modules (motors, sensors, servo, pump, buzzer) are configured.


2. Patrol: Continuously poll left, forward, and right flame sensors.


3. Detection: On any sensor reading LOW, trigger firefighting sequence.


4. Navigation: Adjust motor directions to steer toward the detected flame.


5. Extinguish: Activate pump and servo sweep to douse the fire.


6. Reset: Turn off pump, re-center servo, sound buzzer, then resume patrol.




---

Project Structure

firefighting-robot/
├── assets/
│   ├── circuit_diagram.png
│   └── images/
├── src/
│   ├── firefighterRobot.ino
│   ├── control_logic.cpp
├── README.md
└── LICENSE


---

Team & Acknowledgements

Team Members: Mazen Mohamed

Mentor: Dr. Heba Selem


Thanks to our TA and lab staff for their support and to the open-source community for libraries and inspiration.


---

