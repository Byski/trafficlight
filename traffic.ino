============================================================
        TRAFFIC LIGHT SYSTEM WITH PEDESTRIAN CONTROL
                     by Ebokosia Ebube Joy
============================================================

PROJECT OVERVIEW
----------------
This Arduino-based project simulates a **smart traffic light system** 
with pedestrian button control, visual alerts using LEDs and RGB lights, 
sound feedback via a buzzer, and a clear LCD display for pedestrians.

It demonstrates **real-world traffic light behavior**, where the system:
- Cycles through normal car traffic signals (Green → Orange → Red)
- Responds to a **pedestrian button** to allow safe crossing
- Uses **sound cues** for visually impaired pedestrians
- Displays crossing status on a **16x2 LCD**

------------------------------------------------------------
COMPONENTS USED
------------------------------------------------------------

• LiquidCrystal LCD (16x2)
• Red, Orange, Green Traffic LEDs
• RGB LED for Pedestrian Light (Red, Green, Blue)
• Passive Buzzer/Speaker
• Push Button (for pedestrian request)
• Arduino Board (Uno, Mega, etc.)
• Jumper wires and breadboard

------------------------------------------------------------
PIN CONFIGURATION
------------------------------------------------------------

- LCD Pins         : 7, 6, 5, 4, 3, 2
- LED Red          : Pin 9
- LED Orange       : Pin 8
- LED Green        : Pin 7
- RGB Red          : Pin 10
- RGB Green        : Pin 11
- RGB Blue         : Pin 12
- Speaker          : Pin 6
- Pedestrian Button: Pin 13

------------------------------------------------------------
TRAFFIC FLOW LOGIC
------------------------------------------------------------

1. **Normal Mode (Cars Move Freely)**
   - Green LED is ON
   - Pedestrian RGB stays RED (Don't Cross)
   - System continuously checks if the button is pressed

2. **Pedestrian Request Detected**
   - Button is pressed (Pin 13 HIGH)
   - Traffic light cycles to ORANGE then RED
   - Pedestrian RGB turns WHITE (safe to cross)
   - LCD displays "CROSS"
   - Speaker beeps for alert

3. **Crossing Time Expires**
   - RGB turns ORANGE then RED again
   - LCD displays "WAIT"
   - System returns to normal traffic cycle

------------------------------------------------------------
TIMINGS (in milliseconds)
------------------------------------------------------------

- RED_LIGHT_TIME          : 1000
- ORANGE_LIGHT_TIME       : 1000
- GREEN_LIGHT_TIME        : 1000
- PEDESTRIAN_GO_TIME      : 2500
- PEDESTRIAN_PROMPT_TIME  : 2000

All delays can be adjusted to simulate real-world scenarios.

------------------------------------------------------------
FUNCTIONS EXPLAINED
------------------------------------------------------------

• **setup()**  
  Initializes the LCD and configures all component pins.

• **loop()**  
  Continuously checks traffic and pedestrian states.

• **normalTrafficOperation()**  
  Activates regular traffic lights and listens for button presses.

• **pedestrianCrossing()**  
  Switches traffic lights, enables pedestrian cross, LCD alerts, and beeping.

• **checkPedestrianButton()**  
  Reads the pedestrian button input and updates the system state.

• **beepSpeaker(freq, duration)**  
  Produces audible beeps using the buzzer.

------------------------------------------------------------
USAGE
------------------------------------------------------------

1. Upload the code to your Arduino board.
2. Connect the components to the specified pins.
3. Power the board and observe:
   - Normal traffic light operation.
   - Pedestrian button response.
   - LCD instructions ("WAIT" and "CROSS").
   - RGB and buzzer guidance for crossing.

------------------------------------------------------------
CREDITS
------------------------------------------------------------

Project Author : Ebokosia Ebube Joy  
Year           : 2025  
License        : MIT – Free to use, share, and modify with credit.

============================================================
   FOR EDUCATIONAL DEMOS, CLASS PROJECTS, AND IoT SIMULATIONS
============================================================
