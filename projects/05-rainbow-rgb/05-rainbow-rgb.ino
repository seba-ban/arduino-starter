/*
 * Project 05: Rainbow RGB
 *
 * What this does: turn the knob to make one LED glow in any color
 *                 of the rainbow!
 *
 * Parts needed:
 *   - 1 × RGB LED with 4 legs (COMMON ANODE type)
 *   - 3 × resistor (220 ohm — red, red, brown, gold stripes)
 *   - 1 × potentiometer (the round knob)
 *   - jumper wires
 *
 * IMPORTANT about this RGB LED:
 *   It is a COMMON ANODE type — the longest leg connects to 5V.
 *   This is the OPPOSITE of a normal LED!
 *   LOW (0)   = color fully ON
 *   HIGH (255) = color fully OFF
 *
 * Written for children — every line is explained!
 */

// PWM pins for each color inside the RGB LED
// PWM means we can control brightness (not just on/off)
#define RED_PIN   9    // red color — pin 9
#define GREEN_PIN 10   // green color — pin 10
#define BLUE_PIN  11   // blue color — pin 11
#define POT_PIN   A0   // the potentiometer knob — analog pin A0

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(RED_PIN,   OUTPUT);  // pin 9 controls red brightness
  pinMode(GREEN_PIN, OUTPUT);  // pin 10 controls green brightness
  pinMode(BLUE_PIN,  OUTPUT);  // pin 11 controls blue brightness
  // A0 is an analog input — no pinMode needed
}

// loop() runs over and over, forever
void loop() {
  // Read the knob position — gives a number from 0 to 1023
  int knobValue = analogRead(POT_PIN);

  // Convert the knob (0–1023) to a position in our color wheel (0–767)
  // 768 = 256 × 3 — three color sections in the rainbow
  int colorPosition = map(knobValue, 0, 1023, 0, 767);

  // Calculate how much red, green, and blue to show
  int red, green, blue;

  if (colorPosition < 256) {
    // Section 1: red fades out, green fades in → red to yellow to green
    red   = 255 - colorPosition;  // red goes from 255 (bright) down to 0 (off)
    green = colorPosition;        // green goes from 0 (off) up to 255 (bright)
    blue  = 0;                    // no blue in this section
  } else if (colorPosition < 512) {
    // Section 2: green fades out, blue fades in → green to cyan to blue
    red   = 0;
    green = 255 - (colorPosition - 256);  // green fades out
    blue  = colorPosition - 256;          // blue fades in
  } else {
    // Section 3: blue fades out, red fades in → blue to purple to red
    red   = colorPosition - 512;          // red fades in
    green = 0;
    blue  = 255 - (colorPosition - 512);  // blue fades out
  }

  // COMMON ANODE: subtract from 255 because LOW = ON, HIGH = OFF
  // (255 - 255 = 0 = full brightness; 255 - 0 = 255 = off)
  analogWrite(RED_PIN,   255 - red);    // send inverted red value to pin 9
  analogWrite(GREEN_PIN, 255 - green);  // send inverted green value to pin 10
  analogWrite(BLUE_PIN,  255 - blue);   // send inverted blue value to pin 11

  delay(10);  // small pause to keep the display smooth
}
