# Project 06: Night Light ⭐⭐

> A light that turns itself on when it gets dark — just like a real night light!

## What you will build

A smart light that watches how bright the room is.
When you cover the sensor (or turn off the lights), the LED turns on automatically.
When there is light again, it turns off by itself!

## What you need

- 1 × Photoresistor (the small component that looks like a **snail shell** with a squiggly pattern)
- 1 × Resistor (10k ohm — **brown, black, orange, gold** stripes) — for the light sensor circuit
- 1 × LED (any color)
- 1 × Resistor (220 ohm — **red, red, brown, gold** stripes) — for the LED
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐ — two separate circuits to build, but each one is simple.

## Wiring

This project has two parts: the **light sensor circuit** and the **LED circuit**.

### Step-by-step

**Light sensor circuit (voltage divider):**

1. Push the photoresistor into the breadboard. It has two legs — direction does not matter.
2. Connect one leg of the photoresistor to **5V** on the Arduino.
3. Connect the other leg of the photoresistor to **A0** on the Arduino AND to one end of the **10k ohm resistor**.
4. Connect the other end of the **10k ohm resistor** to **GND** on the Arduino.

**LED circuit (same as Project 01):**

5. Push the LED into the breadboard. The **longer leg is +**, the **shorter leg is −**.
6. Connect the **long leg (+)** → through a **220 ohm resistor** → to **pin 9**.
7. Connect the **short leg (−)** to **GND**.

> 💡 **Tip:** In step 3, one point connects to THREE things: photoresistor leg, A0 wire, AND resistor leg. Use the same breadboard row for all three!

> 💡 **Tip:** If the LED does not respond, try flipping it around — LEDs only work one way!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Arduino 5V | Photoresistor leg 1 |
| Photoresistor leg 2 | Arduino A0 |
| Photoresistor leg 2 | 10k resistor end 1 (same breadboard row as A0) |
| 10k resistor end 2 | Arduino GND |
| LED long leg (+) → 220 ohm resistor | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `06-night-light/06-night-light.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- Room is bright → LED is **OFF**
- Cover the sensor with your hand → LED turns **ON**
- Uncover → LED turns **OFF** again

## How does it work?

The photoresistor changes how much electricity it lets through depending on the light — more light means less resistance.
We use a second resistor (10k) to turn this change into a voltage that the Arduino can read as a number from 0 to 1023.
When the number falls below 400 (our "dark" level), the Arduino turns the LED on.

## Want to learn more? (optional)

Open the **Serial Monitor** in Arduino IDE (click the magnifying glass icon in the top right).
Watch the numbers change as you cover and uncover the sensor!
What number does your room show? Try changing `DARK_THRESHOLD` in the code to a number close to your room's value.
