# Project 04: Buzzer Doorbell ⭐

> Press the button and hear it BEEP — your very own doorbell!

## What you will build

A real working doorbell!
Press the button and the buzzer makes a loud beep. Let go and it goes quiet.
You can put it by your bedroom door and make your family knock before entering!

## What you need

- 1 × Active buzzer (the small black round component with a sticker on top)
- 1 × Tact-switch button
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐ — only 4 wires, and no resistors needed!

## Wiring

### Step-by-step

1. Look at the buzzer. It has **two legs**. The **longer leg is +** (positive). Some buzzers also have a **+** printed on top.
2. Connect the **long leg (+)** of the buzzer to **pin 8** on the Arduino.
3. Connect the **short leg (−)** of the buzzer to **GND** on the Arduino.
4. Push the **button** into the breadboard so its legs straddle the **center gap**.
5. Connect one leg of the button to **pin 2** on the Arduino.
6. Connect the **opposite leg** of the button to **GND** on the Arduino.

> 💡 **Tip:** If the buzzer makes no sound, try flipping it around (swap the + and − legs). Like LEDs, buzzers only work one way!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |
| Button leg 1 | Arduino pin 2 |
| Button leg 2 (opposite side) | Arduino GND |

## How to upload the code

1. Open the file `04-buzzer-doorbell/04-buzzer-doorbell.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- Button **not pressed** → silence
- Button **pressed** → BEEEEEP!
- Button **released** → silence again

## How does it work?

The buzzer has a tiny vibrating disc inside called a piezo element.
When electricity flows in, the disc bends back and forth very fast — and that vibration makes sound, just like a speaker!
This type of buzzer is called an "active buzzer" because it has its own sound-making circuit built in.

## Want to learn more? (optional)

Try connecting both the LED from Project 03 and the buzzer to the same button!
When you press it, you get both a light AND a sound — a proper alarm!
(Hint: you can connect more than one component to the same Arduino pin.)
