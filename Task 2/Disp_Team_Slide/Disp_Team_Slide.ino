//Program to display ARDU_PI in sliding manner

#define latchPin D1
#define clockPin D0
#define dataPin D2

byte leds = 240;
//Array to define sequence for column multiplexing
byte countdown[32] = { 7, 10, 7, 0, 15, 10, 5, 0, 15, 9, 6, 0, 14, 1, 14, 0, 1, 1, 1, 0, 15, 10, 4, 0, 9, 15, 9, 0, 0, 0, 0, 0 };
int j = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  //Loop through each column
  for (int i = 0; i < 4; i++) {
    leds = leds ^ (1 << (7 - i));
    int c = (j / 200) - i;
    //If previous column is less than 0, then take the corresponding last columns in the array
    if (c < 0)
      c = 32 + c;
    leds = leds | countdown[c];
    updateShiftRegister();
    //Reset leds' status to B11110000
    leds = 240;
    delay(2);
    j = j + 1;
    //If all letters are shown, start from beginning
    if (j / 200 == 32)
      j = 0;
  }
}

//Function to update shift register values
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}