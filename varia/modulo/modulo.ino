#include "Arduino_LED_Matrix.h" 

#define ROWS 8
#define COLUMNS 12

ArduinoLEDMatrix matrix;
byte data[ROWS][COLUMNS];
int currLed = 0;

void setup() {
  matrix.begin();  
}

void loop() {
  for (int i = 0; i < ROWS * COLUMNS; i++) {
    int row = i / COLUMNS;
    int col = i % COLUMNS;
    data[row][col] = i == currLed;
  }
  currLed = (currLed + 1) % (ROWS * COLUMNS);

  matrix.renderBitmap(data, ROWS, COLUMNS);
  delay(100);
}
