/*
 * Project 07: Weather Station
 *
 * What this does: reads temperature and humidity from a sensor
 *                 and shows them on a small LCD screen —
 *                 like a mini weather station!
 *
 * Parts needed:
 *   - 1 × DHT11 sensor (blue, 3 or 4 legs)
 *   - 1 × LCD 16x2 screen (the long blue display)
 *   - 1 × resistor (10k ohm — brown, black, orange, gold stripes) for DHT11
 *   - 1 × potentiometer (to adjust LCD contrast)
 *   - jumper wires
 *
 * Libraries used:
 *   - DHT sensor library (by Adafruit) — reads the DHT11
 *   - LiquidCrystal (built-in) — controls the LCD screen
 *
 * Written for children — every line is explained!
 */

#include <DHT.h>           // include the DHT sensor library
#include <LiquidCrystal.h> // include the LCD screen library

#define DHT_PIN  2         // DHT11 data wire connects to pin 2
#define DHT_TYPE DHT11     // tell the library we have a DHT11 (not DHT22)

// Create a DHT sensor object — this is our "remote control" for the sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Create an LCD object — tell it which Arduino pins it is connected to
// Order: RS pin, E pin, D4 pin, D5 pin, D6 pin, D7 pin
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// setup() runs once when the Arduino turns on
void setup() {
  dht.begin();       // start the DHT11 sensor
  lcd.begin(16, 2);  // start the LCD — 16 columns, 2 rows

  // Show a welcome message on the screen
  lcd.print("Weather Station!");
  delay(2000);       // keep the welcome message for 2 seconds
  lcd.clear();       // clear the screen before showing data
}

// loop() runs over and over, forever
void loop() {
  // Read the temperature in Celsius from the DHT11 sensor
  float temperature = dht.readTemperature();

  // Read the humidity as a percentage (0–100%)
  float humidity = dht.readHumidity();

  // Check if the readings are valid
  // isnan() means "is not a number" — sensors can fail sometimes
  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();               // clear the screen
    lcd.print("Sensor error"); // show an error message
    delay(2000);               // wait 2 seconds before trying again
    return;                    // skip the rest of loop() and start over
  }

  // --- Show temperature on the top row of the screen ---
  lcd.setCursor(0, 0);          // move cursor to column 0, row 0 (top-left)
  lcd.print("Temp: ");          // print the label
  lcd.print(temperature, 1);   // print temperature with 1 decimal place
  lcd.print(" C");              // print the unit

  // --- Show humidity on the bottom row ---
  lcd.setCursor(0, 1);          // move cursor to column 0, row 1 (bottom row)
  lcd.print("Humidity: ");      // print the label
  lcd.print(humidity, 0);       // print humidity as a whole number
  lcd.print("%");               // print the unit

  delay(2000);  // wait 2 seconds before reading again
}
