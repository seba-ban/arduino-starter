# Project 09: Parking Sensor ⭐⭐

> Beep faster and faster as your hand gets closer — just like a car's parking sensor!

## What you will build

A distance sensor that beeps faster the closer you get!
Move your hand slowly toward the sensor and the beeping speeds up.
Get very close and it becomes one long continuous beep.
It works exactly like the parking sensor in a car when you reverse into a space!

## What you need

- 1 × HC-SR04 ultrasonic distance sensor (the one that looks like two big round eyes)
- 1 × Active buzzer
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐ — the sensor has 4 labeled pins, easy to connect!

## Wiring

The HC-SR04 sensor has 4 pins labeled on the board: **VCC**, **TRIG**, **ECHO**, **GND**.

### Step-by-step

1. Connect the sensor's **VCC** pin to **5V** on the Arduino.
2. Connect the sensor's **TRIG** pin to **pin 9** on the Arduino.
3. Connect the sensor's **ECHO** pin to **pin 10** on the Arduino.
4. Connect the sensor's **GND** pin to **GND** on the Arduino.
5. Connect the **long leg (+)** of the buzzer to **pin 8** on the Arduino.
6. Connect the **short leg (−)** of the buzzer to **GND** on the Arduino.

> 💡 **Tip:** If the buzzer makes no sound, try flipping it around — buzzers only work one way!

> 💡 **Sensor tip:** Point the two "eyes" of the sensor straight at the object you want to measure. Objects at an angle may not be detected.

### Connection table

| Wire from | Wire to |
|-----------|---------|
| HC-SR04 VCC | Arduino 5V |
| HC-SR04 TRIG | Arduino pin 9 |
| HC-SR04 ECHO | Arduino pin 10 |
| HC-SR04 GND | Arduino GND |
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `09-parking-sensor/09-parking-sensor.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

Move your hand slowly toward the sensor:

| Distance | Beeping |
|----------|---------|
| More than 50 cm | Slow beep — beep . . . beep |
| 20–50 cm | Medium beep — beep . beep |
| 5–20 cm | Fast beep — beepbeepbeep |
| Less than 5 cm | Continuous — BEEEEEEP! |
| Nothing detected | Silence |

## How does it work?

The HC-SR04 sends out a sound wave that is too high for humans to hear (ultrasound).
When the sound hits an object, it bounces back — just like an echo in a cave.
The sensor measures how long it takes for the echo to return, and the Arduino uses that time to calculate the distance.
This is exactly how bats navigate in the dark!

## Want to learn more? (optional)

Open the **Serial Monitor** in Arduino IDE (click the magnifying glass) to see the distance numbers as you move your hand.
What is the smallest distance it can detect? What is the largest?
Try measuring the distance to a wall from different spots — can you use it as a ruler?
