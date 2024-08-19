//Code to test a water level sensor 

// Sensor pins
// #define sensorPower ? // define the pin number plugged in for the VCC
#define sensorPin A0 // define the pin number plugged in for the Signal output

// Variable that will hold water level value, if the sensor is not in water the value is 0
int val = ?;  // set the integer variable val equal to the value before the sensor gets wet

void setup() {
	// Set D7 as an INPUT
//	pinMode(sensorPower, ?); // set the pin mode to INPUT
	
	// Set to LOW so no power flows through the sensor
	//digitalWrite(sensorPower, LOW); // set the pin mode to LOW
	
	Serial.begin(9600); // set the baud rate to the integer value 9600
}

void loop() {
	//get the reading from the function below and print it
	int level = readSensor();
	
	Serial.print("water level: "); // print "Water level: "
	Serial.println(level); // print the level variable
	
	delay(1000); // 1 second but in milliseconds
}

// Declare a function called readSensor to use in getting water level readings
int readSensor() {
	// digitalWrite(sensorPower, );	// Turn the sensor ON
	// delay(10);							// wait 10 milliseconds
	val = analogRead(sensorPin);		// Read the analog value form sensor
	//digitalWrite(sensorPower, );		// Turn the sensor OFF
	return val;							// send current reading
}