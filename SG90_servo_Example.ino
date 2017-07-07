/**
 * Pinout:
 * ------------------------
 *   SG90           ARDUINO
 *   
 *   Data (yello)	  9	
 *   Vcc  (red)       5V
 *   Gnd  (brown)     Gnd
 **/

#include <Servo.h>

Servo servo1;
int sp = 0; // servo position

String readString;

void setup()
{
	servo1.attach(9); // Define the servo signal pins (PWM 3-5-6-9-10-11)
	Serial.begin(9600);
}

void loop()
{
	// Example 1
	/**/
	Serial.println("Left");
	turnLeft();
	delay(1000);
	Serial.println("Middle");
	turnMiddle();
	delay(1000);
	Serial.println("Right");
	turnRight();
	delay(1000);
	/**/

	// Example 2
	/*
	for (sp = 0; sp <= 180; sp++)
	{
	servo1.write(sp);
	delay(10);
	}

	for (sp = 180; sp >= 0; sp--)
	{
	servo1.write(sp);
	delay(10);
	}
	*/

	// Example 3
	/*
	readInput();

	if (readString.length() >0)
	{
	Serial.println("Input: " + readString);

	int value = readString.toInt();

	servo1.write(value);

	readString = "";
	}
	*/

}

void readInput()
{
	while (Serial.available()) {
		delay(3);  //delay to allow buffer to fill 
		if (Serial.available() >0) {
			char c = Serial.read();  //gets one byte from serial buffer
			readString += c; //makes the string readString
		}
	}
}

void turnLeft()
{
	servo1.write(180); // Turned to 0 degrees
}

void turnMiddle()
{
	servo1.write(90); // Turned to 0 degrees
}

void turnRight()
{
	servo1.write(0); // Turned to 0 degrees
}

