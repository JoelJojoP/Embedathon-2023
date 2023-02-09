//Program to display INDIA letter by letter

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 0;
//Array to define sequence for column multiplexing
byte countdown[6][4] = { { B01111001, B10111111, B11011001, B11100000 },
                         { B01111111, B10110010, B11010100, B11101111 },
                         { B01110110, B10111001, B11011111, B11100000 },
                         { B01111001, B10111111, B11011001, B11100000 },
                         { B01110111, B10111010, B11010111, B11100000 },
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
    //Check if all letters has been printed...If YES then restart from first letter
    if (j / 500 == 6)
      j = 0;
  }
}

//Function to update shift register values
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}