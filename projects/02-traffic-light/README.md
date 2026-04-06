# Project 02: Traffic Light ⭐

> Watch three LEDs cycle just like a real traffic light — red, yellow, green!

## What you will build

Three LEDs that switch automatically, just like the traffic lights on the street.
Red stays on for 3 seconds, yellow for 1 second, then green for 3 seconds — then it starts all over again!

## What you need

- 1 × red LED
- 1 × yellow LED
- 1 × green LED
- 3 × Resistor (220 ohm — **red, red, brown, gold** stripes)
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐ — three LEDs, six wires — still easy!

## Wiring

Wire all three LEDs the same way. Each LED gets its own resistor.

### Step-by-step

1. Push the **red LED** into the breadboard.
   Connect its **long leg (+)** → through a resistor → **Arduino pin 2**.
   Connect its **short leg (−)** → **Arduino GND**.

2. Push the **yellow LED** into the breadboard.
   Connect its **long leg (+)** → through a resistor → **Arduino pin 3**.
   Connect its **short leg (−)** → **Arduino GND**.

3. Push the **green LED** into the breadboard.
   Connect its **long leg (+)** → through a resistor → **Arduino pin 4**.
   Connect its **short leg (−)** → **Arduino GND**.

> 💡 **Tip:** If any LED does not light up, try flipping it around — LEDs only work one way!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Red LED long leg (+) → resistor | Arduino pin 2 |
| Red LED short leg (−) | Arduino GND |
| Yellow LED long leg (+) → resistor | Arduino pin 3 |
| Yellow LED short leg (−) | Arduino GND |
| Green LED long leg (+) → resistor | Arduino pin 4 |
| Green LED short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `02-traffic-light/02-traffic-light.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- 🔴 Red LED on for 3 seconds → stop!
- 🟡 Yellow LED on for 1 second → get ready...
- 🟢 Green LED on for 3 seconds → go!
- 🟡 Yellow LED on for 1 second → slow down...
- Repeats forever!

## How does it work?

The Arduino turns one LED on at a time and waits before switching to the next — just like a real traffic light controller box on a street corner.
The `allOff()` function is a shortcut that turns all three LEDs off at once, so they never accidentally overlap.

## Want to learn more? (optional)

Real traffic lights in many cities stay red for 60 seconds or more!
Try changing `delay(3000)` to `delay(60000)` and see how long that feels.
Can you add a pedestrian light that turns green at the same time as the car light turns red?
