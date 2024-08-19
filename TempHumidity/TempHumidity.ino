#include dht // Include library

#define dhtPin ? // put the pin number the sensor is connected to


dht DHT; // Creates a DHT object


void setup() {
Serial.begin(?); //put the baud rate we need to use
}

void loop() {
int readData = DHT.read11(dhtPin);
? t = DHT.temperature; // put the data type that holds decimals in front of t
? h = DHT.humidity; // put the data type that holds decimals in front of h

Serial.print("Temperature = ");

Serial.print(t);

Serial.print("°C | ");

Serial.print((t*9.0)/5.0+32.0); // Convert celsius to fahrenheit

Serial.println("°F ");

Serial.print("Humidity = ");

Serial.print(h);

Serial.println("% ");

Serial.println("");

delay(?); // put what 2 seconds is equivalent to in milliseconds 
}