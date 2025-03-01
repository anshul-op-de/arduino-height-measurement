# arduino-height-measurement
This project is an automated height measurement system that uses an ultrasonic sensor to determine the height of an object or person. The measured height is displayed on an LCD screen, and the system can be turned on or off using a switch. The project is built using an Arduino Uno as the microcontroller
Working Principle:
When the system is turned ON using the switch, the ultrasonic sensor starts measuring the distance from the sensor to the top of the object or person.
The Arduino Uno calculates the height based on the difference between the sensor's fixed position and the measured distance.
The calculated height is displayed on the 16x2 LCD screen in real time.
The system can be turned OFF using the switch to save power.

Formula Used:
Height=Sensor Fixed Height−Measured Distance

Applications:
Measuring a person's height in medical checkups.
Height measurement for industrial and educational purposes.
Use in smart homes or automated fitness tracking systems.
