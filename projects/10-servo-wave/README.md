# Project 10: Servo Wave ⭐⭐

> A motor arm that sweeps back and forth all by itself — like a robot waving hello!

## What you will build

A servo motor that swings its arm slowly from one side all the way to the other and back again.
Attach the small plastic arm that came with the servo and watch it wave!
You could even tape a paper flag to it for extra fun.

## What you need

- 1 × Servo motor MG-90S (with attached 3-wire cable)
- 3 × female-to-male jumper wires (to plug into the servo's connector)
- 1 × Arduino Uno R4 WiFi
- (No breadboard needed for this project!)

## Difficulty

⭐⭐ — only 3 wires! Very satisfying to watch.

## Wiring

The servo has a **3-wire cable** with a white plastic connector on the end.

### Wire colors

| Servo wire color | What it is | Wire to |
|-----------------|------------|---------|
| Brown or Black | GND (−) | Arduino GND |
| Red | 5V power (+) | Arduino 5V |
| Orange or Yellow | Signal | Arduino pin 9 |

> ⚠️ **Important:** Wire colors can vary slightly. If the servo does not move correctly, check that the Red wire goes to 5V and the signal wire goes to pin 9.

### Step-by-step

1. Use **female-to-male jumper wires** to connect to the servo's 3-pin connector.
2. Connect the **Brown or Black wire** (GND) to **GND** on the Arduino.
3. Connect the **Red wire** (power) to **5V** on the Arduino.
4. Connect the **Orange or Yellow wire** (signal) to **pin 9** on the Arduino.

> 💡 **Tip:** The connector is designed to plug in one way only. If it does not fit, flip it 180 degrees and try again.

### Connection table

| Servo wire | Wire to |
|------------|---------|
| Brown / Black (GND) | Arduino GND |
| Red (5V power) | Arduino 5V |
| Orange / Yellow (signal) | Arduino pin 9 |

## How to upload the code

1. Open the file `10-servo-wave/10-servo-wave.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

The servo arm slowly sweeps from **0° to 180°**, then sweeps back from **180° to 0°**, over and over.
One full sweep takes about 3 seconds in each direction.

## How does it work?

The servo has a tiny electric motor and a set of plastic gears inside.
The Arduino sends a special signal (called PWM) that tells the servo exactly what angle to go to.
Unlike a regular motor that just spins, a servo stops precisely at the angle you tell it — that is what makes it useful for robots!

## Want to learn more? (optional)

Try attaching the small plastic arm that came in the servo bag, and tape a paper flag to it.
Can you change the code so the servo stops at **90 degrees** (straight up) and waits when you press a button?
(You will need to add a button from Project 03!)
