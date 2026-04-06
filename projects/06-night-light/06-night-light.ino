/*
 * Project 06: Night Light
 *
 * What this does: the LED turns ON automatically when it gets dark,
 *                 and turns OFF when there is enough light.
 *                 Just like a real night light!
 *
 * Parts needed:
 *   - 1 × photoresistor (the small component that looks like a snail shell)
 *   - 1 × resistor (10k ohm — brown, black, orange, gold stripes)
 *   - 1 × LED (any color)
 *   - 1 × resistor (220 ohm — red, red, brown, gold stripes) for the LED
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define LIGHT_PIN A0   // photoresistor is on analog pin A0
#define LED_PIN   9    // LED is on pin 9

// This is the brightness level where we decide it is "dark enough"
// 0 = completely dark, 1023 = very bright light
// Change this number if your room is unusually bright or dark
#define DARK_THRESHOLD 400

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(LED_PIN, OUTPUT);   // pin 9 will send electricity to the LED
  Serial.begin(9600);         // start communication with the computer
                              // (so we can see the light level numbers)
}

// loop() runs over and over, forever
void loop() {
  // Read how much light the sensor sees (0 = very dark, 1023 = very bright)
  int lightLevel = analogRead(LIGHT_PIN);

  // Print the number to the computer so we can watch it change
  Serial.print("Light level: ");
  Serial.println(lightLevel);  // println adds a new line after the number

  if (lightLevel < DARK_THRESHOLD) {
    // The light level is LOW — it is dark! Turn the LED on.
    digitalWrite(LED_PIN, HIGH);  // LED ON
  } else {
    // The light level is HIGH — there is light. Turn the LED off.
    digitalWrite(LED_PIN, LOW);   // LED OFF
  }

  delay(200);  // check the light 5 times per second (200ms × 5 = 1000ms = 1 second)
}
