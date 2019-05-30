
#include <IRremote.h>           //Library for IR Remote
const int trigPin1 = 8;         //1st Ultrasonic on Entry
const int echoPin1 = 9;         
const int trigPin2 = 10;        //2nd Ultrasonic on Exit
const int echoPin2 = 11;

long duration1;
long duration2;
int counter=0;                  //To manage the Person count
float distance1;                //Distance of First UltraSonic   
float distance2;                //Distance of Second UltraSonic

int in1 = 7;                    // Data Pin of Relay  
int sensor = 6;                 // PIR Sensor Pin
unsigned long t=0;            
unsigned long t2=0; 

#define Power  880074B          //Power Button Code
int receiver_pin = 5;           //IR Receiver Pin
IRrecv receiver(receiver_pin); 
decode_results output;
int status=0;                   // Status of AC ON/Off
 
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(in1, OUTPUT);       
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
//  digitalWrite(in1,HIGH);     //Uncomment if you want to turn the AC on startup   
  receiver.enableIRIn();        //Enable the IR Reciever
  }

void loop()
{
if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
       case Power:                  // Power button case
         if(status == 1) {          // Check status,if high then switch the relay off
            digitalWrite(in1,LOW); 
            status = 0;             // Update the status 
         } else {                      
             digitalWrite(in1,HIGH); 
             status = 1;   
             ultrasonic();          
              if (counter == 0)
              {
              PIR_OFF();
              }
              else
              {
              PIR_ON();
              }       
         }
          break; 
    }
}
}

void PIR_ON()
{
  if(digitalRead(sensor) == HIGH )     // If motion detected
  {
  delay(3000); 
  Serial.println(" Sensor ON.... ");
  t=millis();         // Variable to manage the time periods after which the next motion is to be detected.    
 // digitalWrite(in1,HIGH);     // Turn the relay ON
  while(millis()<(t+300000))      // Check the motion for 5 minutes.
  
  {
  Serial.print("W1...... ");
  digitalWrite(in1,HIGH); 
  if((millis()>(t+5000))&&(digitalRead(sensor)==HIGH)) // Loop to check the motion after every 5s      
  {
       Serial.print(" =========== "); 
       t=millis();          // if motion detected the while loop will be executed again as the time t is updated here.
      }
  Serial.println("Checking if on after  5s...... ");
  }
  Serial.println("ENDIF");
  }
}
void PIR_OFF()
{
  if(digitalRead(sensor)== LOW)
  {            // If no motion is detected

  Serial.println("Sensor OFF.... ");
  t2=millis();
  while(millis()<(t2+300000))     // Loop to check whether there is any further movement 
  {
    
  digitalWrite(in1,LOW); 
  if((millis()>(t2+5000))&&(digitalRead(sensor)==LOW)) // Check the Sensor readings after every 5s 
      {
       t2=millis();       // Update t2 variable if no motion detected.(thus the while loop goes on.)
      }
  }
  }
} 

void ultrasonic()
{
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);  
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);  
    digitalWrite(trigPin1, LOW); 
    duration1 = pulseIn(echoPin1, HIGH); 
    distance= duration*0.0343/2; 
  Serial.print("Distance1 = ");
  Serial.print(distance1); 
  Serial.println(" cm");

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);  
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);  
    digitalWrite(trigPin2, LOW); 
    duration1 = pulseIn(echoPin2, HIGH); 
    distance2= duration2*0.0343/2; 
  Serial.print("Distance2 = ");
  Serial.print(distance2); 
  Serial.println(" cm");
if(distance1>10 && distance1<250)                 // Skip 0-10 for Door 
{
  delay(100);
  if(distance2>10 && distance2<250)
  {
  counter += 1;                                   //Counter increment only if Person passes through both the Ultrasonic sensors
  } 
}
if(distance2>10 && distance2<250)
{
  if(distance1>10 && distance1<250)
  {
  counter -= 1;                                   //Counter decrement if the Person leaves the room
  } 
}
  Serial.print("Counter = ");
  Serial.print(counter);
  }
