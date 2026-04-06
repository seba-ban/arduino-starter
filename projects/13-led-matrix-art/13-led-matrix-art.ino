/*
 * Project 13: LED Matrix Art
 *
 * What this does: shows pictures and animations on the 12×8 dot display
 *                 built into the Arduino Uno R4 WiFi — no extra parts needed!
 *
 * Parts needed:
 *   - Just the Arduino Uno R4 WiFi (the display is built in!)
 *   - USB cable to connect to your computer
 *
 * The LED matrix has 12 columns and 8 rows = 96 tiny LEDs.
 * We draw pictures using a grid of 1s (LED ON) and 0s (LED OFF).
 *
 * Library used: Arduino_LED_Matrix (built into the Arduino R4 core)
 *
 * Written for children — every line is explained!
 */

#include "Arduino_LED_Matrix.h"  // include the library for the built-in LED matrix

// Create a matrix object — our "remote control" for the LED display
ArduinoLEDMatrix matrix;

// --- CUSTOM PICTURES ---
// Each picture is an 8-row by 12-column grid
// 1 = LED ON (lit up), 0 = LED OFF (dark)
// Row 0 is the TOP row, row 7 is the BOTTOM row

// A happy face :)
byte happyFace[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 0 — empty top
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },  // row 1 — eyes
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },  // row 2 — eyes
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 3 — gap
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },  // row 4 — smile corners
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },  // row 5 — smile sides
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },  // row 6 — smile bottom
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 7 — empty bottom
};

// A sad face :(
byte sadFace[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 0 — empty top
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },  // row 1 — eyes
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },  // row 2 — eyes
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 3 — gap
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },  // row 4 — frown top
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },  // row 5 — frown sides
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },  // row 6 — frown corners
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 7 — empty bottom
};

// A heart <3
byte heart[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },  // row 0
  { 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },  // row 1 — heart top bumps
  { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 },  // row 2
  { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },  // row 3
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },  // row 4
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },  // row 5
  { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },  // row 6
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },  // row 7 — heart point
};

// setup() runs once when the Arduino turns on
void setup() {
  matrix.begin();  // start the LED matrix display
}

// loop() runs over and over, forever
void loop() {
  // Show our custom happy face for 1.5 seconds
  matrix.renderBitmap(happyFace, 8, 12);  // display the happyFace picture
  delay(1500);                             // keep it on screen for 1.5 seconds

  // Show our custom sad face for 1.5 seconds
  matrix.renderBitmap(sadFace, 8, 12);    // display the sadFace picture
  delay(1500);

  // Show our custom heart for 1.5 seconds
  matrix.renderBitmap(heart, 8, 12);      // display the heart picture
  delay(1500);

  // Show a built-in happy face from the library's gallery
  matrix.loadFrame(LEDMATRIX_EMOJI_HAPPY);  // load a built-in happy face design
  delay(1500);

  // Show a built-in sad face from the library's gallery
  matrix.loadFrame(LEDMATRIX_EMOJI_SAD);    // load a built-in sad face design
  delay(1500);

  // Show a built-in big heart from the library's gallery
  matrix.loadFrame(LEDMATRIX_HEART_BIG);   // load a built-in heart design
  delay(1500);

  // Play a built-in animation — watch carefully!
  matrix.loadSequence(LEDMATRIX_ANIMATION_STARTUP);  // load the startup animation
  matrix.play(true);                                  // play it (true = loop it)
  delay(3000);                                        // let it run for 3 seconds

  // Stop the animation before going back to our pictures
  matrix.loadFrame(LEDMATRIX_HEART_SMALL);  // show a small heart to end the loop
  delay(1000);                              // keep it for 1 second
  // now loop() starts again!
}
