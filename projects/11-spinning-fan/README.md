# Project 11: Spinning Fan ⭐⭐⭐

> Turn a knob to make a motor spin — faster, slower, or off!

## What you will build

A motor that you control with a knob, just like a fan speed dial.
Turn the knob all the way left and the motor stops.
Turn it slowly to the right and the motor starts spinning, getting faster and faster until it is at full speed.

## What you need

- 1 × DC motor (small, with 2 short wires coming out of it)
- 1 × BC547 transistor (looks like a tiny black D-shape with 3 legs)
- 1 × Resistor (1k ohm — **brown, black, red, gold** stripes)
- 1 × Ceramic capacitor 100nF (small yellow or orange disc — no polarity, any direction)
- 1 × Potentiometer (round knob)
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐⭐ — the transistor circuit is the trickiest part, but the table below makes it clear!

## Wiring

This project uses a **transistor** to control the motor because the motor needs more electricity than the Arduino pin can directly provide.

### About the BC547 transistor

The BC547 has **3 legs**. Hold it with the **flat face toward you** and legs pointing down:

```
   [ flat face ]
   |    |    |
   C    B    E
(Collector) (Base) (Emitter)
```

- **E** (Emitter) → Arduino **GND**
- **B** (Base) → through 1k resistor → Arduino **pin 9**
- **C** (Collector) → **Motor wire 1** (either wire)

### About the capacitor

The 100nF ceramic capacitor goes directly across the two motor wires.
It absorbs electricity spikes when the motor changes speed, protecting the Arduino.
Ceramic capacitors have **no polarity** — you can put them in either way!

### Step-by-step

1. Push the BC547 transistor into the breadboard with the flat face toward you.
2. Connect the **Emitter** (right leg) to **GND** on the Arduino.
3. Connect a **1k resistor** from the **Base** (middle leg) to **pin 9** on the Arduino.
4. Connect the **Collector** (left leg) to **one wire of the motor**.
5. Connect the **other wire of the motor** to **5V** on the Arduino.
6. Connect the **100nF capacitor** across the two motor wires (one leg on each).
7. Connect the potentiometer: left leg → **GND**, middle leg → **A0**, right leg → **5V**.

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Arduino pin 9 | 1k resistor end 1 |
| 1k resistor end 2 | BC547 Base (middle leg) |
| BC547 Emitter (right leg) | Arduino GND |
| BC547 Collector (left leg) | Motor wire 1 |
| Motor wire 2 | Arduino 5V |
| 100nF capacitor | Across Motor wire 1 and Motor wire 2 |
| Potentiometer left leg | Arduino GND |
| Potentiometer middle leg | Arduino A0 |
| Potentiometer right leg | Arduino 5V |

## How to upload the code

1. Open the file `11-spinning-fan/11-spinning-fan.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- Knob all the way **left** → motor **stopped**
- Turn knob **right** → motor **starts spinning and speeds up**
- Knob all the way **right** → motor at **full speed**

> 💡 **Tip:** Some motors need a minimum speed before they start turning. If the motor does not move at low knob positions, try turning the knob further right to get it started!

## How does it work?

The Arduino sends a PWM signal (rapid on/off pulses) to the transistor's Base leg.
The transistor amplifies this tiny signal into a larger current that powers the motor.
When the pulses are longer, more electricity flows and the motor spins faster.
When the pulses are shorter, less flows and the motor slows down.
PWM stands for **Pulse Width Modulation** — "width" means how long each pulse lasts!

## Want to learn more? (optional)

Open the **Serial Monitor** to watch the speed number change as you turn the knob.
What number does the motor start spinning at? (This is called the "stall speed".)
Can you connect a small piece of paper as a fan blade and feel the air moving?
