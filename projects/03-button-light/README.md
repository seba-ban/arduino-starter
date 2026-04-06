# Project 03: Button Light ⭐

> Press the button to turn the light on — your first interactive project!

## What you will build

A light switch you control with your finger.
Hold the button down and the LED glows. Let go and it turns off.
It responds instantly — every single time!

## What you need

- 1 × LED (any color)
- 1 × Resistor (220 ohm — **red, red, brown, gold** stripes)
- 1 × Tact-switch button (the small square one with 4 legs)
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐ — your first interactive project! Only 4 wires.

## Wiring

### Step-by-step

1. Push the **button** into the breadboard so its legs straddle the **center gap** (this is important — it needs to bridge the two halves of the breadboard).
2. Connect one leg of the button to **pin 2** on the Arduino.
3. Connect the **opposite leg** (diagonally across) of the button to **GND** on the Arduino.
4. Push the **LED** into the breadboard. The **longer leg is +**, the **shorter leg is −**.
5. Connect the **long leg (+)** of the LED → through a **resistor** → to **pin 9** on the Arduino.
6. Connect the **short leg (−)** of the LED to **GND** on the Arduino.

> 💡 **Tip:** If the LED does not respond to the button, try flipping the LED around — LEDs only work one way!

> 💡 **Button tip:** A tact-switch has 4 legs but only 2 electrical connections — the legs on the same side are already connected inside. Make sure you wire two legs that are on **opposite sides** of the button.

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Button leg 1 | Arduino pin 2 |
| Button leg 2 (opposite side) | Arduino GND |
| LED long leg (+) → resistor | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `03-button-light/03-button-light.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- Button **not pressed** → LED is **OFF**
- Button **pressed and held** → LED is **ON**
- Button **released** → LED turns **OFF** again

## How does it work?

The button connects pin 2 to GND when you press it. The Arduino reads this as LOW and turns the LED on.
When you let go, a tiny resistor built inside the Arduino pulls the pin back up to HIGH — and the LED turns off.
This built-in resistor is called a "pull-up resistor" and it means we do not need an extra resistor for the button!

## Want to learn more? (optional)

Can you change the code so the LED **stays ON** after you press the button, even after you let go?
(Hint: you need to remember whether the button was pressed — look up "toggle" in Arduino tutorials!)
