/*
 * Project 10: Servo Wave
 *
 * What this does: a servo motor arm sweeps back and forth —
 *                 like a robot waving hello!
 *
 * Parts needed:
 *   - 1 × servo motor MG-90S (with 3-wire cable)
 *   - female-to-male jumper wires (to connect to servo cable)
 *
 * The servo cable has 3 wires:
 *   - Brown or Black = GND
 *   - Red            = 5V (power)
 *   - Orange or Yellow = signal (control)
 *
 * Written for children — every line is explained!
 */

#include <Servo.h>   // include the Servo library — it makes controlling motors easy

#define SERVO_PIN 9  // the servo signal wire connects to pin 9

Servo myServo;  // create a Servo object named "myServo"
                // think of it as a remote control for the motor

// setup() runs once when the Arduino turns on
void setup() {
  myServo.attach(SERVO_PIN);  // tell myServo which pin it is connected to
}

// loop() runs over and over, forever
void loop() {
  // Sweep from 0 degrees to 180 degrees, one step at a time
  for (int angle = 0; angle <= 180; angle++) {  // angle goes from 0 up to 180
    myServo.write(angle);  // move the servo arm to this angle
    delay(15);             // wait 15 milliseconds — gives the motor time to move
  }

  // Sweep back from 180 degrees to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {  // angle goes from 180 down to 0
    myServo.write(angle);  // move the servo arm to this angle
    delay(15);             // wait 15 milliseconds
  }

  // now loop() starts again — the arm keeps waving back and forth!
}
