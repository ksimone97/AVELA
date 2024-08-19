//Used libraries
#include <Keypad.h>

/* Change these values based on your observations */

// Define variables
#define wetSoil ? // put the max value we consider for the soil to be 'wet'
#define drySoil ? // put the min value we consider for the soil to be 'dry'

int val = 0;  // set the integer variable val equal to the value before the sensor gets wet
#define waterWarning 425  // Put the value we consider for the water level to be approaching low
#define waterDanger 350  // Put the value we consider for the water level to be very low

// Define analog input
#define soilMoisturePin ?  // For soil moisture sensor
#define waterLevelPin ?  // For water level sensor

// Define water level output pins
#define green ?  // Define the pin number the green LED is connected to
#define yellow ?  // Define the pin number the yellow LED is connected to
#define red ?  // Define the pin number the red LED is connected to

// Define water pump power pin
#define waterPumpPower ?  // define the pin number plugged in for the VCC of water pump

//Setup keypad
const byte ROWS = 4;
const byte COLS = 3;
byte R1 = 11; // Row one (Top most row containing: 1 2 3)
byte R2 = 10; // Row two 
byte R3 = 9; // Row three
byte R4 = 8; // Row four (Bottom most row containing: * 0 #)
byte C1 = 7;  // Column one (Left most column: 1 4 7 *)
byte C2 = 6;  // Column two
byte C3 = 5; // Column three (Right most column: 3 6 9 #)
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}};
byte rowPins[ROWS] = {R1, R2, R3, R4};
byte colPins[COLS] = {C1, C2, C3};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Set pins for water level as inputs/outputs
  pinMode(green, ?);  // set the pin mode to OUTPUT
  pinMode(yellow, ?);  // set the pin mode to OUTPUT
  pinMode(red, ?);  // set the pin mode to OUTPUT

  // Set pin mode for water pump
	pinMode(waterPumpPower, ?);  // Set the pin mode to INPUT

	// Set to LOW so no power flows through the sensors
  digitalWrite(waterPumpPower, ?); // set the pin mode to LOW

  Serial.begin(?); // put the baud rate we need to use
}

void loop() {
  waterLevel();

  bool pumpWater = soilMoisture();  // returns whether the plant needs more water
  waterPump(pumpWater);  // Controls the water pump

  // Take a reading every second
  delay(?);  // Put what 1 second is equivalent to in miliseconds
}

// Declare a function called waterLevel to use in getting water level readings
void waterLevel() {
	float level = analogRead(waterLevelPin);		// Read the analog value from sensor

  Serial.print(?); // print "Water level: "
	Serial.println(?); // print the level variable

  // Controls the LEDs corresponding to each water level
  if (level <= waterDanger) {
    digitalWrite(red, ?);  // Turn the red LED on
    digitalWrite(yellow, ?);  // Turn the yellow LED off
    digitalWrite(green, ?);  // Turn the yellow LED off
  } else if (level <= waterWarning) {
    digitalWrite(red, ?);  // Turn the yellow LED off
    digitalWrite(yellow, ?);  // Turn the yellow LED on
    digitalWrite(green, ?);  // Turn the yellow LED off
  } else {
    digitalWrite(red, ?);  // Turn the yellow LED off
    digitalWrite(yellow, ?);  // Turn the yellow LED off
    digitalWrite(green, ?);  // Turn the green LED on
  }
}

bool soilMoisture() {
    // Read the Analog Input and print it
  int moisture = analogRead(soilMoisturePin);
  Serial.print("Analog output: ");
  Serial.println(moisture);

  bool waterPlants = false;

  // Determine status of our soil
  if (moisture >= ?) { // put the name of the variable for wet soil
    Serial.println("Status: Soil is too wet");
    waterPlants = ?;  // Put what the input to the water pump should be
  } else if (moisture > ?) { // put the name of the variable for dry soil
    Serial.println("Status: Soil moisture is perfect");
    waterPlants = ?;  // Put what the input to the water pump should be
  } else {
    Serial.println("Status: Soil is too dry - time to water!");
    waterPlants = ?;  // Put what the input to the water pump should be
  }
  Serial.println();
  
  return waterPlants;
}

void waterPump(bool pumpWater) {
  if (pumpWater) {
    digitalWrite(waterPumpPower, ?);  // Turn on water pump
  } else {
    digitalWrite(waterPumpPower, ?);  // Turn off water pump
  }
}