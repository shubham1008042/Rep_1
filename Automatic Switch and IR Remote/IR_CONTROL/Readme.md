Documentation on IR Remote controller to switch On/Off the AC.

Step two, is to use the Remote to control the arduino commands
In this, we are going to control LEDs using an IR sensor and a remote. The IR sensor is a 1838B IR receiver. Whenever a button on the remote is pressed, it will send an infrared signal to the IR sensor in the coded form. The IR sensor will then receive this signal and will give it to the Arduino.

WORKING:
Whenever a button is pressed on the remote, it sends an infrared signal in encoded form. This signal is then received by the IR receiver and given to the Arduino.
We will save the code for the buttons that we want to control the LEDs in the Arduino code. Whenever a button on the remote is pressed, the Arduino receives a code. The Arduino will compare this code with the codes already saved, and if any of them match, the Arduino will turn on the LED connected to that button.

Circuit Diagram and Arduino Code for this is Linked below here.

OUTPUT:
When the particular button is pressed from the IR remote the respective LED will turn On.


