# Project 13: LED Matrix Art ⭐⭐⭐

> Make pictures and animations on the 96 tiny LEDs built right into your Arduino!

## What you will build

Animations and pixel art on the LED matrix built into the Arduino Uno R4 WiFi!
It shows a happy face, a sad face, a heart, built-in designs, and even an animated sequence.
The best part: **no extra wires or parts needed** — the display is already inside the Arduino!

## What you need

- 1 × Arduino Uno R4 WiFi (the display is built in — that is all!)
- 1 × USB cable (to connect to your computer)

## Difficulty

⭐⭐⭐ — no wiring needed! The creative challenge is designing your own pixel art pictures.

## Wiring

**No wiring needed for this project!**
Just plug your Arduino into the computer with the USB cable.

## How to upload the code

1. Open the file `13-led-matrix-art/13-led-matrix-art.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

The LED matrix cycles through these displays, one after another:

1. 😊 Custom happy face (1.5 seconds)
2. 😢 Custom sad face (1.5 seconds)
3. ❤️ Custom heart (1.5 seconds)
4. 😊 Built-in happy face (1.5 seconds)
5. 😢 Built-in sad face (1.5 seconds)
6. ❤️ Built-in big heart (1.5 seconds)
7. 🎬 Built-in startup animation (3 seconds)
8. Small heart (1 second)
9. Starts over!

## How does it work?

The LED matrix has 12 columns and 8 rows — that is 96 tiny LEDs in total.
We draw pictures by creating a grid of 1s and 0s: **1 = LED on**, **0 = LED off**.
It is just like pixel art in a video game — each LED is one pixel!

## Design your own pictures!

This is the fun part. Here is a blank 8×12 grid — fill in the squares you want to light up, then type 1s where the squares are filled and 0s where they are empty:

```
Row 0:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 1:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 2:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 3:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 4:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 5:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 6:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
Row 7:  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
```

Then add your picture to the code like this:

```cpp
byte myPicture[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 0
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 1
  // ... fill in your 1s and 0s here!
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 7
};
```

And show it with:
```cpp
matrix.renderBitmap(myPicture, 8, 12);
delay(1500);
```

> 💡 **Tip:** Use graph paper to design your picture first — draw a grid with 8 rows and 12 columns, fill in squares with a pencil, then type the 1s!

## Want to learn more? (optional)

Can you make an animation by creating several slightly different pictures and showing them one after another very fast?
What is the smallest picture you can make that still looks like something?
Try spelling out a letter like your first initial using 1s and 0s!
