#include <Servo.h>

Servo myservo;              // Servo object
int buttonState = 0;        // State placeholder
float lx = 5.00;            // Left time
float rx = 6.00;            // Right time
float last = 5.50;          // Last time placeholder
const int startPin = 3;     // Start button
const int leftPin = 2;      // Left button
const int rightPin = 4;     // Right button
const int servoPin = 9;		// Servo pin


void setup()
{
  Serial.begin(9600);
  pinMode(startPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  myservo.attach(servoPin);
  myservo.write(40); 		// Reset servo to default position
}

void loop()
{  
  buttonState = digitalRead(startPin);	// Check if start pin is pressed
  if(buttonState == HIGH)
  {
    last = (rx+lx)/2.00;	// Divide the current left and right values to determine the middle
    myservo.write(25);		// Move servo 10 degrees to "press the button"
    //Serial.println(last);
    delay(last*1000.00);	// Hold button for 1 second times the value of 'last'
    myservo.write(40);		// Set the servo back to original position - release the button
  }
  buttonState = digitalRead(leftPin);	// Check if left pin is pressed
  if(buttonState == HIGH)
  {
   lx = last; 
  }
  buttonState = digitalRead(rightPin);	// Check if right pin is pressed
  if(buttonState == HIGH)
  {
   rx = last; 
  }
}
