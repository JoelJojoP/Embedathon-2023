//Program to display ARDU_PI letter by letter

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 0;
//Array to define sequence for column multiplexing
byte countdown[8][4] = { { B01110111, B10111010, B11010111, B11100000 },
                         { B01110101, B10111010, B11011111, B11100000 },
                         { B01110110, B10111001, B11011111, B11100000 },
                         { B01111110, B10110001, B11011110, B11100000 },
                         { B01110001, B10110001, B11010001, B11100000 },
                         { B01110100, B10111010, B11011111, B11100000 },
                         { B01111001, B10111111, B11011001, B11100000 },
                         { B00000000, B00000000, B00000000, B00000000 } };
int j = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  //Loop through each column
  for (int i = 0; i < 4; i++) {
    leds = countdown[j / 500][i];
    updateShiftRegister();
    delay(2);
    j = j + 1;
    //If all letters are printed, restart from first letter
    if (j / 500 == 8)
      j = 0;
  }
}

//Function to update shift register values
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}