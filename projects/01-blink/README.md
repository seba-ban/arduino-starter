# Project 01: Blink ⭐

> Make an LED flash on and off — your very first Arduino project!

## What you will build

An LED that flashes on and off by itself — like the heartbeat of your Arduino!
Every second it turns on, every second it turns off. It never stops.

## What you need

- 1 × LED (any color)
- 1 × Resistor (220 ohm — the one with **red, red, brown, gold** stripes)
- 2 × jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐ — great first project, only 2 wires!

## Wiring

### Step-by-step

1. Push the LED into the breadboard. Look at the legs — one is **longer** and one is **shorter**.
   The **longer leg is +** (positive). The **shorter leg is −** (negative).
> 💡 **Tip:** If your LED does not light up after uploading, try flipping it around in the breadboard — LEDs only work one way!
2. Connect one end of the **resistor** to the **longer leg** (+) of the LED.
3. Connect a **jumper wire** from the other end of the resistor to **pin 9** on the Arduino.
4. Connect a **jumper wire** from the **shorter leg** (−) of the LED to any **GND** pin on the Arduino.

> 💡 **Tip:** The resistor protects the LED from getting too much electricity. Without it, the LED could burn out!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| LED long leg (+) → resistor → | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `01-blink/01-blink.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

The LED flashes: **ON for 1 second**, then **OFF for 1 second**, forever!

## How does it work?

The Arduino is like a tiny brain that follows instructions very fast.
We tell it: "turn the light on, wait one second, turn the light off, wait one second — then start again."
The LED lights up when electricity flows through it, and goes dark when it stops.

## Want to learn more? (optional)

Try changing `delay(1000)` to `delay(500)` and upload again — that makes it blink twice per second, about as fast as a resting heartbeat!
Can you make it blink even faster? What is the smallest number you can use?
