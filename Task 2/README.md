# Task 2

## Problem Statement

Create a 4x4 LED matrix using a shift register and write programs to display various figures on the matrix

## Solution

### Milestone 1 - Continuity Checker

The continuity checker is made by simply connecting one jumper to the 3.3V terminal and another jumper to the GND terminal of the NodeMCU. A 220 ohm resistor is connected to the jumper connected to 3.3V. To test an LED, the LED is connected between the resistor and the jumper connected to GND. The working LEDs will glow.

Breadboard Implementation:

![Ardu_Pi_Milestone_1_BB](https://user-images.githubusercontent.com/97270737/217781839-a5f8e1ab-69c5-430f-98a1-e7fbdec178cc.jpg)

Output:

https://user-images.githubusercontent.com/97270737/217782414-65abfeda-278b-475a-a34c-b0cb302d3373.mp4

### Milestone 2 - Testing the LED Matrix

Code: ```Matrix_Test.ino```

Breadboard Implementation:

![Ardu_Pi_Matrix_BB](https://user-images.githubusercontent.com/97270737/217782555-31467ac8-b48e-4798-a4a1-594974bdfd84.jpg)

Output:

https://user-images.githubusercontent.com/97270737/217782686-66ceb821-cc09-4e42-aa9e-3a7f602d0c5b.mp4

### Milestone 3 - Print the Letter H on the Matrix

Code: ```Disp_H.ino```

Output:

https://user-images.githubusercontent.com/97270737/217784413-88b90d71-5d3a-4202-bfc0-90d5370c13ce.mp4

### Milestone 4 - Countdown Timer on LED Matrix

Code: ```Countdown.ino```

Output:

https://user-images.githubusercontent.com/97270737/217784529-ef3d0688-5792-4334-9b2a-e13d2210f309.mp4

### Milestone 5 - Display 'INDIA' on the LED Matrix Letter by Letter

Code: ```Disp_INDIA.ino```

Output:

https://user-images.githubusercontent.com/97270737/217784593-62a4cdb3-7e21-4b93-b37e-70220c380f45.mp4

### Bonus 1 - Print Team Name on the LED Matrix Letter by Letter

Code: ```Disp_Team.ino```

Output:

https://user-images.githubusercontent.com/97270737/217786034-6972ef3c-6c75-493f-83e2-165562032816.mp4

### Bonus 2 - Print Team Name on the LED Matrix in a Sliding Manner

Code: ```Disp_Team_Slide.ino```

Output:

https://user-images.githubusercontent.com/97270737/217791837-723e83d4-7bcb-49ca-ac4b-fbf6b74d8de4.mp4

> If videos and photos are not visible, they can be found [here](https://drive.google.com/drive/folders/1ua8AKECrDrI6KfGNXxiOqpk9MABb9HRi?usp=sharing).

## User Guide

1. Construct the circuit.
2. Open the desired program in Arduino IDE.
3. Coonect the NodeMCU to the computer and select NodeMCU 1.0 as the device (if not selected automatically).
4. Upload the code into the NodeMCU.
