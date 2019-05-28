			Documentation on automatically switch off the AC if no-one is present in the room

The first and foremost step is to choose the right sensor for this purpose,I have searched and found these two as the best options for our project. 

							SENSORS:
1- OMRON-D6T sensor:
D6T sensor seems like the perfect sensor for detecting human presence in a room.
**Omron's D6T Series MEMS Thermal Sensors are a super-sensitive infrared temperature sensor that makes full use of Omron's proprietary MEMS sensing technology. Unlike typical pyroelectric human presence sensors that rely on motion detection, the D6T thermal sensor is able to detect the presence of stationary humans by detecting body heat, and can therefore be used to automatically switch off unnecessary lighting, air conditioning, etc. when people are not present. As the D6T sensor is also able to monitor the temperature of a room, it can also be used to continually maintain optimal room temperature levels, instantly sense unusual changes in temperature thereby detecting factory line stoppages, or discover areas of overheating for early prevention of fire outbreaks.

Features
OMRON’s unique MEMS and ASIC technologies achieve a high SNR
Superior noise immunity with a digital output
High-precision area temperature detection with low crosstalk field of view characteristics

Field of View Characterstics - D6T.png linked below

REFERENCIAL CODE: https://forum.arduino.cc/index.php?topic=217394.0

2-PIR

Features:
PIR sensor is used for detecting infrared heat radiations. This makes them useful in the detection of moving living objects that emit infrared heat radiations.
The output (in terms of voltage) of PIR sensor is high when it senses motion; whereas it is low when there is no motion (stationary object or no object).
PIR sensors are used in many applications like for room light control using human detection, human motion detection for security purpose at home, etc.

Connections:
Connecting PIR sensors to a microcontroller is really simple. The PIR acts as a digital output, it can be high voltage or low voltage, so all you need to do is listen for the pin to flip high (detected) or low (not detected) by listening on a digital input on your Arduino
Its likely that you'll want reriggering, so be sure to put the jumper in the H position!
Power the PIR with 5V and connect ground to ground. Then connect the output to a digital pin. 

REFERENCIAL CODE FOR PIR: 
https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/using-a-pir-w-arduino


NEXT STEP is to Integrate the System with selected Sensor and also to build an IR Remote Control system for AC.
This further includes two steps:
	1:To decode the remote signals
	2:Use Remote to control the devices with arduino commands


Other References to control AC Using IR and PIR
References:
https://www.instructables.com/id/Controlling-an-IR-Air-Conditioner-With-Android-and/
https://learn.adafruit.com/ir-sensor/using-an-ir-sensor

// Automaticcally Control AC using DHT 
https://create.arduino.cc/projecthub/BuddyC/ir-controller-for-air-conditioner-5bd0a2

Documentation on IR Remote controller to switch On/Off the AC.


