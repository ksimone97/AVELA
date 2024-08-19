/* Change these values based on your observations */

#define wetSoil ? // put the max value we consider soil 'wet'
#define drySoil ? // put the min value we consider soil 'dry'

// Define analog input
#define sensorPin A0

void setup() { 
  Serial.begin(?); // put the baud rate we need to use
}

void loop() {
  // Read the Analog Input and print it
  int moisture = analogRead(sensorPin);
  Serial.print("Analog output: ");
  Serial.println(moisture);

  // Determine status of our soil
  if (moisture < ?) { // put the name of the variable for wet soil
    Serial.println("Status: Soil is too wet");
  } else if (moisture < ?) { // put the name of the variable for dry soil
    Serial.println("Status: Soil moisture is perfect");
  } else {
    Serial.println("Status: Soil is too dry - time to water!");
  }
  Serial.println();

  // Take a reading every second
  delay(?); // put what 1 second is equivalent to in milliseconds 
}