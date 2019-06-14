#define echoPin1 8             // Ultrasonic Sensor 1
#define trigPin1 7
#define echoPin2 4             // Ultrasonic Sensor 2
#define trigPin2 2

long duration1=0,distance1=0; // Distance measured by First Ultrasonic Sensor
long duration2=0,distance2=0; // Distance measured by Second Ultrasonic Sensor
 
int count=0;                  // Counter to count number of person Entering or leaving the room
 
void setup() {
Serial.begin(9600);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
}
 
int sensor1()                  // Function to calculate the distance from First sensor 
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1=pulseIn(echoPin1,HIGH);
distance1=(duration1/2)/29.1;
//Serial.print("NUM 1  -  ");  // Uncomment these two lines if you want to display distance in console       
//Serial.println(distance1);
return(distance1);
}

int sensor2()                  // Function to calculate the distance from First sensor
{
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2=pulseIn(echoPin2,HIGH);
distance2=(duration2/2)/29.1;
//Serial.print("NUM 2  -  ");
//Serial.println(distance2);
return(distance2);
}
 
void loop() {
 
sensor1();
sensor2();
 
//------------- Enter Loop starts: Checking if someone got inside---------------
// Distance 1 and Distance 2 threshold values are taken 
// according to my requirement you can vary it according to yours 
if((distance1<36) && (distance2>33)) //sensor 1 triggered - step 1 completed
{
do
{
delay(50);
sensor1();
sensor2();
if((distance1>37) && (distance2>33)) //person doesn't enter the room - loop breaks
break;
}
while(!(distance2<33)); //sensor 2 is triggered - step 2 completed
 
if(distance2<33) //rechecking
{
do
{
delay(50);
sensor1();
sensor2();
}
while(!(distance1>36 && distance2>33)); //none of the sensor are triggered - step 3 completed
 
if(distance1>36 && distance2>33) //rechecking last step
{
count++; //all steps completed - person entered successfully
Serial.println(count);
}
}
}
// ----------- Enter Loop ENDS------------------
//-------------Exit loop starts-----------------
if((distance1>36) && (distance2<33)) //Sensor 2 triggered - step 1 completed
{
do
{
delay(10);
sensor1();
sensor2();
if((distance1>36) && (distance2>33)) //person goes back in the room - loop breaks
break;
}
while(!(distance1<36)); //sensor 1 triggered - step 2 completed
 
if(distance1<36) //rechecking sensor 1
{
do
{
delay(50);
sensor1();
sensor2();
}
while(!((distance1>36) && (distance2>33))); //none of the sensor is triggered - step 3 completed
 
if(distance1>36 && distance2>33) //rechecking both sensors
{
count--; //person exits the room - loop completed
if(count<0)
count=0;
Serial.println(count);
}
}
}
//-----------------Exit Loop Ends--------------------------------
 
// Switch ON or OFF appliances according to the count
if(count>=1){
// Write the code what you want to do if counter is above 1
}
else{
// Write the code what you want to do if counter is 0.
}

delay(1000);
Serial.print("Counter = "); // To show counter value in the console. 
Serial.println(count);
}
