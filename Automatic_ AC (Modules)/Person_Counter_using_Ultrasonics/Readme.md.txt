###Program to count the number of people in a room

Here, we are going to design a system that will count the number of people in the room i.e. person counting system. As soon as the system knows that there is no one in the room, it will switch off AC/Light saving a lot of electricity. We need to detect if the person got in or came out of the room.

First thing to decide is which sensor to use. I used ultrasonic sensor i.e. HC-SR04 which returns distance from the obstacle. I can suggest alternatives like using LDR sensor with Laser diode, or may be motion sensor like PIR which will not count the number of people but detect motion. But for long range ultrasonic sensors are a good choice. With only one sensor used, we cannot detect if the person got in or out of the room. So I will be using two ultrasonic sensors placed in such a way that their waves don’t interfere with each other.

###Logic 

To qualify that the person entered the room, this sequence of actions should be followed. Sensor 1 should be triggered first, then both sensors or sensor 2 must be triggered followed by no sensor is triggered. This will increment the person count by 1. The reverse is the criteria for someone leaving the room. Sensor 2 must be triggered first, then both sensors or sensor 1 followed by no sensor is triggered. This will decrease the person count by 1. If any of the sequences breaks then the loop will start again.This algorithm can count the number of people in the room easily.Serial.print will show the counted person in the room. 

##Hardware Used
Arduino UNO
2 ultrasonic sensors (HC-SR04)

##Connections 
Connections are too easy to implement.
Though if required you can take referece from:
http://electronicshacking.com/how-to-interface-ultrasonic-sensor-with-arduino-hc-sr04/

##Working

I have mentioned most of the things in the comments, but if you still didn’t understand then here is the best explanation I can provide. The code starts with declaring some variables and initializing the pins as input or output. Next I have made two functions sensor1 and sensor2 which will return the updated distance whenever called. Before writing an ‘if’ statement I call the sensor1 and sensor2 functions to get the new updated distance. Starting with the loop that will verify if someone entered the room or not, the code checks if sensor 1 is triggered. If yes then next it checks if sensor 2 is triggered after that. The do while loop will make sure that the program waits till the next action/step. If the sensor 2 is also triggered then it will check if none of the sensors are triggered now. If that happens then we can say that someone entered the room and the count is incremented by 1. The same reverse procedure is followed for someone leaving the room. If you still don’t get the logic then please do mention it in the comment section below.

So this was the simple I have written that is based on timing. You can modify it further according to your requirements.