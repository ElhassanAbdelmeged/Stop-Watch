# Stop Watch System

This mini project implements a Stop Watch system with the following specifications:

1. Utilizes an ATmega32 Microcontroller operating at a frequency of 1MHz.

2. Configures Timer1 in ATmega16 with CTC (Clear Timer on Compare Match) mode to count the Stop Watch time.

3. Utilizes six Common Anode 7-segment displays.

4. Connects the six 7-segment displays using multiplexing technique. A 7447 decoder is used for all 7-segments, and each 7-segment is enabled/disabled using an NPN BJT transistor connected to one of the MCU pins.

5. Implements multiplexing to display one 7-segment at a time, switching between them using transistors. This technique takes advantage of persistence of vision to create the illusion of a continuous display.

6. Connects the 7447 decoder's 4 pins to the first 4 pins in PORTC.

7. Uses the first 6 pins in PORTA as enable/disable pins for the six 7-segments.

8. The Stop Watch counting starts automatically when power is connected to the MCU.

9. Configures External Interrupt INT0 with a falling edge trigger. Connects a push button with an internal pull-up resistor. When a falling edge is detected, the Stop Watch time is reset.

10. Configures External Interrupt INT1 with a rising edge trigger. Connects a push button with an external pull-down resistor. When a rising edge is detected, the Stop Watch time is paused.

11. Configures External Interrupt INT2 with a falling edge trigger. Connects a push button with an internal pull-up resistor. When a falling edge is detected, the Stop Watch time is resumed.



![image](https://github.com/ElhassanAbdelmeged/Stop-Watch/assets/88130561/bd264306-fdd0-4d52-9ec3-96a7e2076e65)

