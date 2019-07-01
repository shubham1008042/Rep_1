
Automatic AC System using Arduino is a very useful project as you need not worry about turning on and off the switches every time you want to turn on the AC. The main components of this project are Arduino, PIR Sensor and the IR LED(For sending the .

Out of the three components, the PIR Sensor is the one in focus as it is the main device that helps in detecting humans and human motion.

In fact, the Automatic AC can be considered as one major application of the PIR Sensor. A similar concept is being already implemented in automatic toilet flush valves, hand dryers, etc.

  ###Components Required for Automatic Room Lights using Arduino

Arduino UNO 
PIR Sensor 
IR LED
LED 
Connecting Wires
Breadboard
Power Supply

 ###Connections

PIR is connected to the Pin #6 of Arduino(5V and GND).
LED is connected with the Pin #13.
and IR LED is attached to the Pin #3 of Arduino UNO(3V).  

 ###Decode AC Remote Signals

irsend.sendNEC(0x8800A4E,28);
Here, this signal is send to the AC to power it ON. 

irsend.sendNEC(0x88C0051,28);
Here, this signal is send to the AC to power it OFF. 

These Decode Signals can be easily obtained from the Examples of the <IRremote.h> library.

  ###Working

PIR detects continuously if there is any continuous moment for 4.5 Seconds,you can vary it as per requirement.If yes,it turns on the AC by sending the ON signal throug the IR LED.

Also if PIR detects no motion for continuous 7.5s,again,you can vary it as per your requirement.If yes,it will turn AC OFF.
