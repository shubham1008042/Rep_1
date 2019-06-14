#include <IRremote.h>           //Library for IR Remote
IRsend irsend;
int sensor = 6;                 // PIR Sensor Pin  
int LED = 13;                   // LED indicates if IR LED is sending the signal
boolean status=false;           // Status of AC either ON/OFF
boolean temp;                   // Temorary variable to store the previous status of AC  
void setup() 
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{

if(digitalRead(sensor) == HIGH )        // If motion detected
{
  delay(1500);
  if(digitalRead(sensor) == HIGH )      // If motion detected
  {
  delay(1500);
    if(digitalRead(sensor) == HIGH )    // If motion detected continuously for 4500 ms then ON Signal is sent to AC.
    {
    delay(1500);
     
    Serial.println("Motion Detected");  // Message on Serial if no moment detected.
    status=true;
    if (status != temp)
     {
     irsend.sendNEC(0x8800A4E,28);
     Serial.println("ON    REMOTE SIGNAL SENT");
     digitalWrite(LED, HIGH);       // turn the LED on (HIGH is the voltage level)
     delay(50);                     // wait for a second
     digitalWrite(LED, LOW);        // turn the LED off by making the voltage LOW
     delay(50); 
     }
     
     temp = status;
     delay(1000);
     }  
  }
}
else{
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2500);
  if(digitalRead(sensor) == LOW )     // If motion not detected
  {
  delay(2500);
  if(digitalRead(sensor) == LOW )     // If motion not detected continuously for 7500 ms then OFF Signal is sent to AC.
  {
  delay(2500);
  Serial.println("Waiting......");    // Message on Serial if no moment detected.
  //Serial.println("OFF Signal sent");
  status=false;
  if (status != temp)
  {
  
  irsend.sendNEC(0x88C0051,28); 
  Serial.println("OFF    REMOTE SIGNAL SENT");
  digitalWrite(LED, HIGH);            // turn the LED on (HIGH is the voltage level)
  delay(500);                         // wait for a second
  digitalWrite(LED, LOW);             // turn the LED off by making the voltage LOW
  }
  temp=status;
  delay(1000);
  }
  }  
  }
}
}
