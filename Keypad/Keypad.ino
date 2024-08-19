`//Used libraries
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>`
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  

//The string that will hold the phone number
String phone = "";

//Setup keypad
const byte ROWS = 4;
const byte COLS = 3;
byte R1 = A0; // Row one (Top most row containing: 1 2 3)
byte R2 = A1; // Row two 
byte R3 = A2; // Row three
byte R4 = A3; // Row four (Bottom most row containing: * 0 #)
byte C1 = 8;  // Column one (Left most column: 1 4 7 *)
byte C2 = 9;  // Column two
byte C3 = 10; // Column three (Right most column: 3 6 9 #)
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}};
byte rowPins[ROWS] = {R1, R2, R3, R4};
byte colPins[COLS] = {C1, C2, C3};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.backlight();
  lcd.init(); 
  Serial.begin(9600);
}

void loop() {
  Serial.println("Please enter the phone number");
  Serial.println("you wish to call:");
  Serial.println("");
  
  boolean isEmergency = callPhone();
  
  if(isEmergency == true) {
    //Create a for loop that prints the following message 3 times:
    //EMERGENCY
    //Calling 911
    //...
    for(?; ?; ?) {
      ?
    }
  } else {
    Serial.print("Calling: ");
    Serial.println(phone);
    Serial.println("");
  }
  
  //Reset the phone to being empty
  phone = "";
}

//Check keypad inputs and returns true if the inputs are 911
//or false if it's an actual 10 digit phone number
boolean callPhone() {
  //Create a while loop that repeats while the length of the
  //phone is less than 10
  while(?) {
    //Save a single pressed key value
    char digit = ?;
    
    //Create a conditional to make sure the digit is valid to add
    //to the phone number. To be valid:
    //1. An actual digit must be pressed (the digit cannot be NO_KEY)
    //2. The digit cannot be '*'
    //3. The digit cannot be '#'
    //To create multiple conditions use '&&' like: 
    //if(condition1 && condition2 && condition3) {}
    if(?) { // '!=' means 'does not equal'
      //Add the new digit to the phone number
      phone += ?;
      Serial.print(digit);
    }
    
    //Create a conditional that check if the phone equals "911"
    //If it equals "911" print a new line then return true to exit the function
    if(?) {
      ?
    }
  }
  
  //Print a new line and return false
  ?
  ?
}