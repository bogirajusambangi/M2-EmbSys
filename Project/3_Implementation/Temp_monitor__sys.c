#include <LiquidCrystal.h> // Header file to use Inbuilt LCD Commands
float temp;        // Variable Temp  to store sensor value
int sensor = A0;   // Assigning Analog0 To sensor
float tempc;       // It stores temperature in Centigrade
int set_value=50;  // Inital value to set 
int t=13;          // Buzzer connected to digital pin 13 of Arduino

LiquidCrystal lcd (12, 11, 5, 4, 3, 2); // This is instance of LCD pins connectd to arduino digital pins
void setup() {
lcd.begin (16, 2);                      // It tells LCD is in 16 x 2 Mode
pinMode(8,OUTPUT);                      //Transistor is connected to digital pin8 and making as a Output pin
pinMode(10,OUTPUT);                     // LED Connected to digital pin10 and making as a Output pin 

}

void loop() {
temp=analogRead(sensor);   // It stores Analog value from sensor
tempc=(temp*4.88)/10;      // Converting It into Centigrade
lcd.setCursor(0,0);        // Cursor position starts from 0,0
lcd.print("Temp in C = "); // Printing on LCD 
lcd.println(tempc);        // Printing on LCD
if(tempc >= set_value )    // Condition statement If Present Temperature increases graterthan or equal set value this Block will executes 
{  digitalWrite(10,HIGH);  // LIght Indication on By making Digital pin10 High
   delay(500);             // Delay of 0.5 seconds
   tone(t,450);            // Buzzer tone frequency
   delay(500);             // Delay of 0.5 seconds
   noTone(t);              // Removing tone
   delay(500);             // Delay of 0.5 seconds
   digitalWrite(8,HIGH);   // Cooler Or Heater on By making this pin High
  }
if(tempc<set_value)        // Condition statement If Present Temperature lessthan set value this Block will executes 
{ digitalWrite(10,LOW);    // LIght Indication off By making Digital pin10 Low
  digitalWrite(8,LOW);     // Cooler Or Heater off By making this pin  LOW
}
}
