# Project 05: Rainbow RGB ⭐⭐

> Turn a knob to slide through every color of the rainbow — with just ONE LED!

## What you will build

A single LED that can glow in any color you choose.
Turn the knob slowly and watch it glide through red, orange, yellow, green, cyan, blue, and purple.
Inside the LED are three tiny colored lights mixed together — just like mixing paint!

## What you need

- 1 × RGB LED (the one with **4 legs** — it is a COMMON ANODE type)
- 3 × Resistor (220 ohm — **red, red, brown, gold** stripes)
- 1 × Potentiometer (the round knob component)
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐ — slightly tricky wiring, but the result is magical!

## Wiring

### About the RGB LED

The RGB LED has **4 legs**. Hold it so the legs point down:

```
 [R]  [longest = 5V]  [G]  [B]
  |         |          |    |
pin 9      5V        pin10 pin11
```

The **longest leg** is the common anode — it goes to **5V** (not GND!).
Each shorter leg goes through its own 220 ohm resistor to its Arduino pin.

> ⚠️ **Important:** This LED is a COMMON ANODE type. The longest leg connects to **5V**, NOT to GND. This is different from a regular LED!

### Step-by-step

1. Push the RGB LED into the breadboard. Find the **longest leg** — this is the common anode (+).
2. Connect the **longest leg** to **5V** on the Arduino.
3. Connect the **R (red) leg** → through a 220 ohm resistor → to **pin 9**.
4. Connect the **G (green) leg** → through a 220 ohm resistor → to **pin 10**.
5. Connect the **B (blue) leg** → through a 220 ohm resistor → to **pin 11**.
6. Push the potentiometer into the breadboard. It has 3 legs.
7. Connect the **left leg** of the potentiometer to **GND**.
8. Connect the **middle leg** to **A0** on the Arduino.
9. Connect the **right leg** to **5V**.

> 💡 **Tip:** If the LED glows the wrong color or not at all, double-check that the longest leg is connected to 5V — not GND!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| RGB longest leg (common anode) | Arduino 5V |
| RGB Red leg → 220 ohm resistor | Arduino pin 9 |
| RGB Green leg → 220 ohm resistor | Arduino pin 10 |
| RGB Blue leg → 220 ohm resistor | Arduino pin 11 |
| Potentiometer left leg | Arduino GND |
| Potentiometer middle leg | Arduino A0 |
| Potentiometer right leg | Arduino 5V |

## How to upload the code

1. Open the file `05-rainbow-rgb/05-rainbow-rgb.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

Turn the knob slowly from one end to the other.
The LED should glide smoothly through the full rainbow:
**red → yellow → green → cyan → blue → purple → red**

## How does it work?

Inside the RGB LED are three tiny colored lights: red, green, and blue.
By mixing them at different brightnesses — just like mixing paint — you can make any color.
The potentiometer tells the Arduino where you are in the rainbow, and the Arduino sets each color's brightness to match.

## Want to learn more? (optional)

Can you find the position that makes **white**? (Hint: white = all three colors at equal brightness!)
Can you find **orange**? **Pink**?
Try looking up the RGB values for your favorite color and writing code to show just that one color!
