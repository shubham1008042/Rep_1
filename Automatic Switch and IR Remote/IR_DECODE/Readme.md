Documentation on IR Remote controller to switch On/Off the AC.

   Step one, is to decode the remote signals to get codes of buttons for TempUP or TempDown or On/Off the AC.
We are going to decode the IR Remote Control using the arduino and IR remote library. We can also decode any tv remote control. And use those tv remote control code in the arduino sketch to run any application. As we have seen, some devices are running using the ir remote. There is some kind of IR communication between the ir remote and the receiver devices who receive the ir signal. This is not the simple IR transmitter and receiver as we use in different robotics and embedded sensors.

The transmitter IR  sends a frequency signal instead of a simple IR light. TV remote control or ir remote send the signal at long distance it sends the signal at some frequency like 38KHz.

At the receiver side, we use the IR receiver which is compatible to receive the frequency signal sent from the transmitter. If a signal is transmitted with a frequency of 38KHz then we need a receiver which is capable of receiving the signal of 38KHz.

Circuit Diagram and Arduino Code for this is Linked below here.

Directions: 

    Connect the output pin of TSOP1738 to Arduino digital pin 11 to get the decoded output
    Write the IRrecvDemo.ino sketch to the Arduino
    The open serial terminal at 9600 baud rate.
    Press the IR Remote button while pointing remote towards the IR Receiver
    You will see some hex value when pressing the button
    Note Down
    Repeat few times and make sure you are getting the same hex value for a single button.

OUTPUT:
	The Hexadecimal numbers in Serial Print is the code for the each pressed button on Remote respectively.

Now use these codes in arduino sketch. When these codes match with the stored one do something. Here we have written the code that decodes the IR remote control button and shows the button number on the serial monitor.

// DECODE THE SENSOR DATA
https://www.maxphi.com/ir-remote-control-decoder-using-arduino

