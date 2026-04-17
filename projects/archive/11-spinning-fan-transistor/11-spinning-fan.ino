/*
 * Project 11: Spinning Fan
 *
 * What this does: turn the knob to make a motor spin faster or slower —
 *                 like controlling the speed of a fan!
 *
 * Parts needed:
 *   - 1 × DC motor (small, with 2 wires)
 *   - 1 × NPN transistor BC547 (tiny black D-shape with 3 legs)
 *   - 1 × resistor (1k ohm — brown, black, red, gold stripes)
 *   - 1 × diode 1N4007 (small black cylinder with a silver stripe on one end)
 *   - 1 × ceramic capacitor 100nF (small yellow or orange disc)
 *   - 1 × potentiometer (round knob)
 *   - jumper wires
 *
 * WHY DO WE NEED A TRANSISTOR?
 *   The motor needs more electricity than an Arduino pin can give.
 *   The transistor works like a water tap:
 *     - A small signal on the Base pin controls a bigger flow through Collector and Emitter.
 *   So a tiny signal from pin 9 controls a much bigger current through the motor!
 *
 * WHY DO WE NEED A FLYBACK DIODE (1N4007)?
 *   Motors are like tiny electromagnets — when you switch them off they try to keep
 *   pushing current, creating a sudden reverse voltage spike.
 *   Without the diode this spike can damage the transistor or the Arduino.
 *   The diode sits across the motor wires (stripe toward 5V) and gives the spike
 *   a safe path to flow away harmlessly.
 *   The 100nF capacitor is a DIFFERENT protection — it smooths out high-frequency
 *   noise. You need BOTH the diode AND the capacitor!
 *
 * Written for children — every line is explained!
 */

#define MOTOR_PIN 9    // transistor Base connects through a resistor to pin 9 (PWM)
#define POT_PIN   A0   // potentiometer knob is on analog pin A0

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(MOTOR_PIN, OUTPUT);  // pin 9 will send PWM signals to the transistor
  Serial.begin(9600);          // start communication with the computer
}

// loop() runs over and over, forever
void loop() {
  // Read the knob — gives a number from 0 (all the way left) to 1023 (all the way right)
  int knobValue = analogRead(POT_PIN);

  // Convert the knob value (0–1023) to a motor speed (0–255)
  // analogWrite needs a number between 0 and 255
  // map() converts one range to another — like scaling a recipe!
  int motorSpeed = map(knobValue, 0, 1023, 0, 255);

  // Send the speed to the motor (through the transistor)
  // 0 = motor stopped, 255 = full speed
  analogWrite(MOTOR_PIN, motorSpeed);

  // Show the speed value in Serial Monitor so we can watch it
  Serial.print("Motor speed: ");
  Serial.println(motorSpeed);

  delay(50);  // small pause — check the knob 20 times per second
}
