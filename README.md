# 🔥 Firefighting Robot — Autonomous Arduino-Based System 🤖🚨

An Arduino-powered autonomous firefighting robot that detects, navigates to, and extinguishes flames using embedded control logic. This project showcases the practical application of automatic control systems in replacing humans in hazardous environments.

---

## 📌 Table of Contents

1. [Overview](#Overview)
2. [Features](#Features)
3. [Components Required](#components-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Software Requirements](#software-requirements)
6. [Installation & Setup](#installation--setup)
7. [Usage](#usage)
8. [Code Structure & Snippets](#code-structure--snippets)
9. [How It Works](#how-it-works)
10. [Project Structure](#project-structure)
11. [Team & Acknowledgements](#team--acknowledgements)
12. [License](#license)

---

## 🧠 Overview

This firefighting robot was developed as part of our control systems coursework. Equipped with a 5-channel flame sensor array, differential-drive DC motors, and a servo-controlled water pump, the robot autonomously:

- **Scans** for fire sources
- **Navigates** toward detected flames
- **Extinguishes** fires by spraying water
- **Triggers** an alarm upon engagement

It demonstrates how automatic control and embedded systems can revolutionize industrial safety, disaster response, and smart infrastructure solutions.

---

## ✨ Features

-  **Flame Detection**: Digital flame sensors (LEFT, FORWARD, RIGHT)
-  **Differential Drive**: Controlled via L298N (or L293D) motor driver
-  **Servo-Controlled Nozzle**: Directs water precisely
-  **Autonomous Suppression**: Activates pump and sweeps nozzle
-  **Emergency Buzzer**: Alerts during fire engagement
-  **Modular Design**: Sensor/control logic separation for flexibility

---

## 🧰 Components Required

- Arduino Uno
- USB-A to Micro-USB cable
- Car chassis kit
- L298N motor driver module (or L293D alternative)
- 5-channel flame sensor module
- Servo motor
- Mini DC submersible water pump
- Relay module
- Buzzer
- 12V rechargeable battery pack
- On/off switch & DC female connector jack
- Jumper wires and hookup cables
- Soldering iron & solder wire
- Hot glue gun & glue sticks

---

## 🔌 Circuit Diagram

### 🌀 L298N Motor Driver

| Driver Pin | Arduino Pin       | Description                       |
|------------|-------------------|-----------------------------------|
| ENA        | 3                 | PWM speed control (left motors)   |
| IN1        | 12                | Left motor direction A            |
| IN2        | 4                 | Left motor direction B            |
| IN3        | 7                 | Right motor direction A           |
| IN4        | 2                 | Right motor direction B           |
| ENB        | 5                 | PWM speed control (right motors)  |
| 12V        | Battery +12V      | Motor power supply                |
| GND        | Battery GND       | Common ground (also Arduino GND)  |
| 5V         | Arduino 5V        | Logic power                       |

### 🎛️ Servo Motor

| Servo Pin | Arduino Pin   | Description         |
|-----------|---------------|---------------------|
| VCC       | 5V            | Power supply        |
| GND       | GND           | Common ground       |
| Signal    | 11            | PWM control signal  |

### 🔥 Flame Sensor Module

| Sensor Pin    | Arduino Pin | Description           |
|---------------|-------------|-----------------------|
| VCC           | 5V          | Power supply          |
| GND           | GND         | Common ground         |
| DO (LEFT)     | 10          | Digital output left   |
| DO (FORWARD)  | 8           | Digital output front  |
| DO (RIGHT)    | 9           | Digital output right  |

> ⚠️ Ensure all grounds (battery, Arduino, modules) are interconnected.

---

## 💻 Software Requirements

- Arduino IDE (v1.8.x or later)
- Required Libraries:
  - `Servo.h`
  - `AFMotor.h` (if using Adafruit Motor Shield)
  - `SoftwareSerial` (if serial comms are used)

---

## 🛠️ Installation & Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/<your-username>/firefighting-robot.git
   cd firefighting-robot
   ```
2. **Open** `firefighterRobot.ino` in the Arduino IDE.
3. **Install** libraries via **Sketch → Include Library → Manage Libraries**.
4. **Assemble and wire** according to the [circuit diagrams](#circuit-diagram).
5. **Upload** the code to the Arduino Uno.
6. **Power on** with the 12V battery and switch.

---

## ▶️ Usage

1. Set the robot on a test surface.
2. Light a small flame (e.g., candle) or simulate a heat source.
3. The robot will patrol and scan automatically.
4. Upon detecting a flame, it navigates and extinguishes it.
5. The buzzer indicates successful engagement.

---

## 🧾 Code Structure & Snippets

- `firefighterRobot.ino` — Main sketch
- `control_logic.h/.cpp` — Handles motor control and fire suppression logic
- `sensors.h/.cpp` — Sensor initialization and readings

### 🔧 Snippet: Fire Suppression Logic

```cpp
void put_off_fire(Servo &servo) {
  stopMotors();
  digitalWrite(PUMP_PIN, HIGH);
  delay(500);
  for (int pos = 50; pos <= 130; pos++) { servo.write(pos); delay(10); }
  for (int pos = 130; pos >= 50; pos--) { servo.write(pos); delay(10); }
  digitalWrite(PUMP_PIN, LOW);
  servo.write(90);
}
```

---

## 🔄 How It Works

1. **Setup**: All peripherals initialized.
2. **Scan**: Continuously read flame sensor states.
3. **Navigate**: Adjust wheel directions based on detection.
4. **Engage**: Stop, spray water, activate buzzer.
5. **Reset**: Center nozzle, resume patrol.

---

## 🗂️ Project Structure

```
firefighting-robot/
├── assets/
│   ├── circuit_diagram.png
│   └── images/
├── src/
│   ├── firefighterRobot.ino
│   ├── control_logic.cpp
│   └── sensors.cpp
├── README.md
└── LICENSE
```

---

## 👥 The Byte Builders Team & Acknowledgements

- **Team Members**: Mazen Mohamed, Mohamed Abdel Moneim, Mohamed Hamed, Muhamad Reda, Mohamed El-Basyouni
- **Mentor**: Dr. Heba Selim

Special thanks to our teaching assistants, lab engineers, and the open-source community.

---

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for full terms.

