# Task 2

## Problem Statement

Create a 4x4 LED matrix using a shift register and write programs to display various figures on the matrix

## Solution

### Milestone 1 - Continuity Checker

The continuity checker is made by simply connecting one jumper to the 3.3V terminal and another jumper to the GND terminal of the NodeMCU. A 220 ohm resistor is connected to the jumper connected to 3.3V. To test an LED, the LED is connected between the resistor and the jumper connected to GND. The working LEDs will glow.

Breadboard Implementation:



Output:



### Milestone 2 - Testing the LED Matrix

Code: ```Matrix_Test.ino```

Breadboard Implementation:



Output:



### Milestone 3 - Print the Letter H on the Matrix

Code: ```Disp_H.ino```

Output:



### Milestone 4 - Countdown Timer on LED Matrix

Code: ```Countdown.ino```

Output:



### Milestone 5 - Display 'INDIA' on the LED Matrix Letter by Letter

Code: ```Disp_INDIA.ino```

Output:



### Bonus 1 - Print tTeam Name on the LED Matrix Letter by Letter

Code: ```Disp_Team.ino```

Output:



### Bonus 2 - Print Team Name on the LED Matrix in a Sliding Manner

Code: ```Disp_Team_Slide.ino```

Output:



> If videos and photos are not visible, they can be found [here](https://drive.google.com/drive/folders/1ua8AKECrDrI6KfGNXxiOqpk9MABb9HRi?usp=sharing).

## User Guide

1. Construct the circuit.
2. Open the desired program in Arduino IDE.
3. Coonect the NodeMCU to the computer and select NodeMCU 1.0 as the device (if not selected automatically).
4. Upload the code into the NodeMCU.
