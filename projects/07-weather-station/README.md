# Project 07: Weather Station ⭐⭐

> See the real temperature and humidity on your own screen — a mini weather station!

## What you will build

Your own weather station that shows the temperature and how humid the air is on a real LCD screen.
The numbers update every 2 seconds so you can watch as the room changes.
Try breathing on the sensor — watch the humidity jump!

## What you need

- 1 × DHT11 sensor (small blue component with 3 or 4 legs)
- 1 × LCD 16×2 screen (the long display with 16 pins)
- 1 × Resistor (10k ohm — **brown, black, orange, gold** stripes) — for the DHT11 sensor
- 1 × Potentiometer — for adjusting the LCD screen brightness
- Many jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐ — lots of wires for the LCD, but each one is simple. Take it step by step!

## Wiring

This project has two parts: the **DHT11 sensor** and the **LCD screen**.

### Part 1: DHT11 Sensor

The DHT11 has 3 or 4 pins. Look at the label on the sensor or its board:

| DHT11 pin | Wire to |
|-----------|---------|
| VCC (or +) | Arduino 5V |
| DATA (or OUT) | Arduino pin 2 AND one end of the 10k resistor |
| GND (or −) | Arduino GND |
| 10k resistor other end | Arduino 5V |

> 💡 The 10k resistor connects DATA to 5V — this is called a "pull-up resistor" and helps the signal stay clean.

### Part 2: LCD Screen

The LCD has 16 pins numbered 1–16 along the bottom. Count carefully from left to right!

| LCD pin | Name | Wire to |
|---------|------|---------|
| 1 | VSS (GND) | Arduino GND |
| 2 | VDD (5V) | Arduino 5V |
| 3 | V0 (contrast) | Potentiometer middle leg |
| 4 | RS | Arduino pin 7 |
| 5 | R/W | Arduino GND |
| 6 | E | Arduino pin 8 |
| 7–10 | D0–D3 | Not connected |
| 11 | D4 | Arduino pin 9 |
| 12 | D5 | Arduino pin 10 |
| 13 | D6 | Arduino pin 11 |
| 14 | D7 | Arduino pin 12 |
| 15 | LED+ (backlight) | Arduino 5V |
| 16 | LED− (backlight) | Arduino GND |

### Part 3: Potentiometer (for LCD contrast)

| Potentiometer leg | Wire to |
|-------------------|---------|
| Left leg | Arduino GND |
| Middle leg | LCD pin 3 (V0) |
| Right leg | Arduino 5V |

> ⚠️ **Important:** If the screen shows nothing after uploading, slowly turn the potentiometer knob until the text appears. This adjusts the contrast!

### Step-by-step summary

1. Wire the DHT11 sensor (3–4 wires + pull-up resistor as shown above).
2. Wire the potentiometer (3 wires).
3. Wire the LCD screen pins 1, 2 to power and GND.
4. Wire LCD pin 3 to potentiometer middle.
5. Wire LCD pins 4 (RS) and 6 (E) to Arduino pins 7 and 8.
6. Leave LCD pins 7–10 (D0–D3) unconnected.
7. Wire LCD pins 11–14 (D4–D7) to Arduino pins 9–12.
8. Wire LCD pins 15–16 (backlight) to 5V and GND.

## How to upload the code

1. Open the file `07-weather-station/07-weather-station.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- The screen first shows **"Weather Station!"** for 2 seconds.
- Then it shows the temperature on the top row and humidity on the bottom row.
- The numbers update every 2 seconds.

## How does it work?

The DHT11 sensor has a tiny computer inside that measures temperature and humidity and sends the numbers to the Arduino.
The Arduino then passes those numbers to the LCD screen, which displays them using its built-in character display.

## Want to learn more? (optional)

Try breathing warm air onto the DHT11 sensor — what happens to the humidity number?
Can you change the code to show temperature in Fahrenheit? (Hint: multiply Celsius by 1.8 and add 32!)
