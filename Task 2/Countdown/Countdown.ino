//Program to countdown from 9 and display in matrix

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 0;
//Array to define a sequence for row multiplexing
byte countdown[10][4] = { { B00111000, B00110100, B01110010, B01110001 },
                          { B00001000, B10010100, B10010010, B00000001 },
                          { B00011000, B01110100, B01110010, B01110001 },
                          { B10111000, B10110100, B00110010, B00110001 },
                          { B00011000, B10010100, B01110010, B10010001 },
                          { B01111000, B00110100, B00010010, B01110001 },
                          { B00011000, B00110100, B01110010, B10010001 },
                          { B10011000, B01110100, B10110010, B00010001 },
                          { B10111000, B10110100, B10110010, B10110001 },
                          { B00011000, B01010100, B01010010, B00010001 } };
int j = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  //Loop through each row
  for (int i = 0; i < 4; i++) {
    leds = countdown[j / 500][i];
    updateShiftRegister();
    delay(2);
    j = j + 1;
    //If 0 is reached, reset to 9
    if (j / 500 == 10)
      j = 0;
  }
}

//Function to update shift register values
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}