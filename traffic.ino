
 
#include <LiquidCrystal.h>

// Liquid Crystal Display
LiquidCrystal LCD(7, 6, 5, 4, 3, 2);
 
// Traffic Light Colours Components
const int LEDRed = 9;
const int LEDOrange = 8;
const int LEDGreen = 7;

// Traffic Light Speakers Component
const int Speaker = 6;

// Traffic Light RGB Components
const int RGBRed = 10;
const int RGBGreen = 11;
const int RGBBlue = 12;

// Traffic Light Button Component
const int Button = 13;

// Normal Traffic Light Timer (ms)
const int RED_LIGHT_TIME = 1000;
const int ORANGE_LIGHT_TIME = 1000;
const int GREEN_LIGHT_TIME = 1000;

// Pedestrian Crossing Timer (ms)
const int PEDESTRIAN_GO_TIME = 2500;
const int PEDESTRIAN_PROMPT_TIME = 2000;

// To change to Pedestrian Crossing operation
boolean changeToPedestrian = false;

// Get the button value
int buttonValue = 0;



/*******************

   Arduino Functions

********************/

void setup() {
   configureComponents();
}

void loop() {
   if (!changeToPedestrian)
      normalTrafficOperation(); // Cars are moving
   else
      pedestrianCrossing(); // Pedestrians are now crossing
      
}



/************************

   User-defined Functions

*************************/

// Configuring Components
void configureComponents() {
   // Setup the LCD screen
   LCD.begin(16, 2);
   LCD.print("Wait!");
   
   // Setup LED
   pinMode(LEDRed, OUTPUT);
   pinMode(LEDOrange, OUTPUT);
   pinMode(LEDGreen, OUTPUT);
   
   // Setup Speaker
   pinMode(Speaker, OUTPUT);
   
   // Setup RGB
   pinMode(RGBRed, OUTPUT);
   pinMode(RGBGreen, OUTPUT);
   pinMode(RGBBlue, OUTPUT);
   
   // Setup Button
   pinMode(Button, OUTPUT);
}

void setupLCD() {
   pinMode(LED_BUILTIN, OUTPUT);
   
   // Setup the LCD's number of columns and rows:
   LCD.begin(16, 2);
   
   // Print a message to the LCD
   LCD.print("Ebube");
   delay(1000);
   
   LCD.setCursor(5, 1); // set the cursor to column 5, line 1
   LCD.print("Traffic Light"); // print the year
   delay(1000);
   
   LCD.clear(); // Clear the display
}
// End of Configuring Components




// Traffic Light Operation
void normalTrafficOperation() {
   // Ensure the pedestrian crossing light is on red
   digitalWrite(RGBRed, LOW);
   digitalWrite(RGBGreen, HIGH);
   digitalWrite(RGBBlue, HIGH);
  
   
   // Turn on Green
   digitalWrite(LEDRed, LOW);
   digitalWrite(LEDOrange, LOW);
   digitalWrite(LEDGreen, HIGH);
   
   
   // Check if the Pedestrian Button is being clicked
   checkPedestrianButton();
}

void checkPedestrianButton() {
   buttonValue = digitalRead(Button);
   
   if (buttonValue > 0)
      changeToPedestrian = true;
}

void pedestrianCrossing() {   
   // Pedestrians should still wait
   beepSpeaker(1000, 50);
   beepSpeaker(1000, 50);
   beepSpeaker(1000, 50);   
   beepSpeaker(1000, 50);
   
   // Turn on Orange
   digitalWrite(LEDRed, LOW);
   digitalWrite(LEDOrange, HIGH);
   digitalWrite(LEDGreen, LOW);
   
   beepSpeaker(ORANGE_LIGHT_TIME, 50);
   
   // Turn on RED
   beepSpeaker(1000, 50);
   digitalWrite(LEDRed, HIGH);
   digitalWrite(LEDOrange, LOW);
   digitalWrite(LEDGreen, LOW);
   
   beepSpeaker(RED_LIGHT_TIME, 50);   
   
   // Pedestrians can cross now
   // Ensure the pedestrian crossing light is on white
   digitalWrite(RGBRed, HIGH);
   digitalWrite(RGBGreen, LOW);
   digitalWrite(RGBBlue, HIGH);
   
   // Set the Display to say the pedestrians can go
   LCD.clear();
   LCD.begin(16, 2);
   LCD.print("Cross");
   
   beepSpeaker(500, PEDESTRIAN_GO_TIME);
   
   // Set the pedestrian crossing light to be on orange
   digitalWrite(RGBRed, LOW);
   digitalWrite(RGBGreen, LOW);
   digitalWrite(RGBBlue, HIGH);
   delay(PEDESTRIAN_PROMPT_TIME);
   
   // Set the Display to say the pedestrians to wait
   LCD.clear();
   LCD.begin(16, 2);
   LCD.print("Wait");

   // Turn on Orange traffic light
   digitalWrite(LEDRed, LOW);
   digitalWrite(LEDOrange, HIGH);
   digitalWrite(LEDGreen, LOW);
   
   delay(ORANGE_LIGHT_TIME / 1.2);
   
   // Resume normal traffic operation
   changeToPedestrian = false;
   
}

void beepSpeaker(int freq, int duration) {
   tone(Speaker, freq, duration);
   delay(duration);
   noTone(Speaker);
   delay(1000);
}
// End of Traffic Light Operation

#pragma GCC pop_options

