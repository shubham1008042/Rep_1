int in1 = 9;
int sensor = 8;
int led = 13;
unsigned long t=0;
unsigned long t2=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(in1,HIGH);
  digitalWrite(led,LOW);

  while(millis()<3000)
  {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
  }
  digitalWrite(led,LOW);
  
}


void loop() 
{
  if(digitalRead(sensor) == HIGH)
  {
  Serial.println("Sensor ON.... ");
  t=millis();
  digitalWrite(in1,HIGH);
  while(millis()<(t+3000))
  
  {
  Serial.print("W1...... ");
  digitalWrite(in1,HIGH); 
  digitalWrite(led,LOW);
  if((millis()>(t+100))&&(digitalRead(sensor)==HIGH))
      {
       Serial.print(" =========== "); 
       t=millis();
      }
  Serial.println("Checking if on after  0.1s...... ");
  }
  Serial.println("ENDIF");
  }
 
  else{
  Serial.println("Sensor OFF.... ");
  t2=millis();
  while(millis()<(t2+3000))
  {
    
  digitalWrite(in1,LOW); 
  digitalWrite(led,HIGH);
  if((millis()>(t2+1500))&&(digitalRead(sensor)==LOW))
      {
       t2=millis();
      }
  }
  }
}
