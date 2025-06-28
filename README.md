## 🖼️ Controller Image (JUST A PROTOTYPE, BODY IS NOT ASSEMBLED YET)

![Controller Setup](https://github.com/PurpleWolfDev/BasicJoystickControl/blob/main/photo_2025-06-29_03-01-40.jpg)

## 🎮 Demo Video

[![Watch the demo](https://img.youtube.com/vi/MepCem7zIws/hqdefault.jpg)](https://youtube.com/shorts/MepCem7zIws?feature=share)


# Arduino + Python PC Game Controller Using Joysticks

This project turns a dual-joystick Arduino setup into a PC game controller using Python. The Arduino reads analog joystick positions and button presses, then sends direction data to a Python script via serial. The Python script converts this into actual keyboard and mouse input, allowing the joysticks to control PC games.

---

## 🧠 Features

- **Arduino Uno** reads:
  - Two analog joysticks (for movement + boosting)
  - Two pushbuttons (mapped to right-click and shift)
- **Python script** handles:
  - Simulated keyboard movement (`W`, `A`, `S`, `D`)
  - Boost (`R` hold via joystick Y2)
  - Shift key and mouse click emulation via buttons

---

## 🕹️ Controls Mapping

| Arduino Input       | Python Action             |
|---------------------|---------------------------|
| Joystick 1 UP       | Press `W`                 |
| Joystick 1 DOWN     | Press `S`                 |
| Joystick 1 LEFT     | Press `W` + `A` (strafe)  |
| Joystick 1 RIGHT    | Press `W` + `D` (strafe)  |
| Joystick 2 UP       | Press/Hold `R` (boost)    |
| Switch 1            | Right Click (Mouse)       |
| Switch 2            | Press `SHIFT`             |
| Centered Joystick   | Release all movement keys |

---

## ⚠️ Important Notes

- **Joystick Orientation Matters**  
  The physical rotation of your joystick affects axis readings. This project assumes the joystick is oriented in a specific way.  
  If your joystick is rotated, you **must adjust the directional mapping** in the Arduino code accordingly.

- **ChatGPT Assistance Disclosure**  
  > ⚠️ Note: The Python side of this project was built with assistance from ChatGPT, I wanted to build this with nodejs using serial port and robotjs but i was having issues with installation of libraries, in future may be I'll write an updated code in nodejs.
---

## 📂 Files

- `controller.ino` – Arduino sketch that reads joystick + button data and sends serial commands
- `controller.py` – Python script that reads serial data and presses/releases keys/mouse buttons using `pynput`

---

## 🔧 Requirements

### Hardware
- Arduino Uno (or compatible)
- 2x Analog Joysticks
- 2x Pushbuttons
- USB cable

### Software
- Arduino IDE
- Python 3.x
- Python packages:
  ```bash
  pip install pynput pyserial
