# Stop Watch System

This mini project implements a Stop Watch system with the following specifications:

1. **Microcontroller:** Utilizes an ATmega32 Microcontroller operating at a frequency of 1MHz.

2. **Timer Configuration:** Configures Timer1 in ATmega32 with CTC (Clear Timer on Compare Match) mode to count the Stop Watch time.

3. **Display:** Utilizes six Common Anode 7-segment displays.

4. **Display Multiplexing:** Connects the six 7-segment displays using a multiplexing technique. A 7447 decoder is employed for all 7-segments, with each 7-segment enabled/disabled using an NPN BJT transistor connected to one of the MCU pins.

5. **Persistence of Vision:** Implements multiplexing to display one 7-segment at a time, utilizing transistors for switching. This technique leverages persistence of vision to create the illusion of a continuous display.

6. **Connections:** Connects the 7447 decoder's 4 pins to the first 4 pins in PORTC.

7. **Control Pins:** Uses the first 6 pins in PORTA as enable/disable pins for the six 7-segments.

8. **Automatic Start:** The Stop Watch counting starts automatically when power is connected to the MCU.

9. **Reset Functionality:** Configures External Interrupt INT0 with a falling edge trigger. Connects a push button with an internal pull-up resistor. When a falling edge is detected, the Stop Watch time is reset.

10. **Pause Functionality:** Configures External Interrupt INT1 with a rising edge trigger. Connects a push button with an external pull-down resistor. When a rising edge is detected, the Stop Watch time is paused.

11. **Resume Functionality:** Configures External Interrupt INT2 with a falling edge trigger. Connects a push button with an internal pull-up resistor. When a falling edge is detected, the Stop Watch time is resumed.

**Drivers:**
- GPIO
- Timer
- External Interrupts
- 7-Segment Display

**Microcontroller:**
- ATmega32

This project provides a practical implementation of a stopwatch with multiplexed 7-segment displays controlled by external interrupts for reset, pause, and resume functions.
**schematic:**

![image](https://github.com/ElhassanAbdelmeged/Stop-Watch/assets/88130561/3b1d6220-4cef-4724-8246-d33641f232c6)
