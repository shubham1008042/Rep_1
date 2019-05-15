Using the RTC DS3231 module as the RTC for a raspberry pi.
This allows correct timekeeping, even without an Internet connection, through power down cycles.

Using the clock will be demonstrated shell programming. This will include:
    Setting up I2C on the pi and addressing the RTC
    Upon boot, initializing and using the RTC for timekeeping.
    Setting the time

The steps to follow are:
    Enable the I2C interfacing 	
    Connect the RTC
    Configure I2C on your Pi
    Final Test
    


Step 1 : First of all Enable the I2C interfacing of our Raspberry Pi.
	
Step 2 : The I2C peripheral is not turned on by default. To enable it, do the following.

	    Run sudo raspi-config.
	    Use the down arrow to select the Interfacing Options
	    Arrow down to P5 I2C.
	    Select yes when it asks you to enable I2C,
	    Also select yes if it asks about automatically loading the kernel module.
	    Use the right arrow to select the <Finish> button.
	    Select yes when it asks to reboot.
 
Step 3 : Connect the RTC
Step 4 : Install the required essentials using the script.This will automatically install important tools and also loads the clock at boot-time.
Step 5 : The Final Test

	The final test is to determine if the RTC module is keeping time and that the Pi will use that time when it boots. The best way to do 		that is to :

    	Power down the Pi
    	Remove the power cable
    	Remove the network connection
    	Leave it after some time.
    	Power it up and use “date” to see what time the Pi thinks it is !!
