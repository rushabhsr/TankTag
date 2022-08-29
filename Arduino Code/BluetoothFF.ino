//Declare the arduino pins
#include <Servo.h>

Servo myservo;

int lm1 = 4;
int lm2 = 5;
int rm1 = 6;
int rm2 = 7;
int fire = 12;
int fl = 3;
int bl = 2;
int pos=90;
int health=100;
int sensorPin = A0;
int gameon=8;
int gameoff=9;
int sensorValue = 0;
void setup()
{
  //initlize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
   pinMode(fire,OUTPUT);
   pinMode(fl,OUTPUT);
   pinMode(bl,OUTPUT);
   
   pinMode(sensorPin,INPUT);
   pinMode(gameoff,OUTPUT);
   pinMode(gameon,OUTPUT);

   myservo.attach(10);
   myservo.write(pos);
   //set the serial communication rate
  Serial.begin(9600);
}

void loop()
{
  //Motor PINS need this To ENABLE MOTION
  analogWrite(fl,255);
  analogWrite(bl,255);
  

  if(health>0){
    digitalWrite(gameon,HIGH);
    digitalWrite(gameoff,LOW);
  }
  if(health <=0 ){
    digitalWrite(gameoff,HIGH);
    digitalWrite(gameon,LOW);
  }
  if(Serial.available()){
  char val = Serial.read() ;//reads the signal
  
  /*********For Forward motion*********/
  
  if(val == 'W')
  {
    digitalWrite(lm1,HIGH);      digitalWrite(rm1,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  }
  if(val == 'w'){
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);  
  } 
    /*********For Backward Motion*********/
  if(val == 'S')
  {
    digitalWrite(lm2,HIGH);      digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
      
  }
  if(val == 's'){
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  
  }
   /*********RIGHT*********/
  if(val == 'D')
  {
    digitalWrite(lm1,HIGH);      digitalWrite(rm2,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);   
  }
  if(val == 'd'){
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  
  }
   /*********LEFT*********/
  if(val == 'A')
  {
   Serial.println("Right");
    digitalWrite(lm2,HIGH);     digitalWrite(rm1,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm2,LOW);
    
  }
  if(val == 'a'){
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  
  }
   /*********Fire********/
 if(val == 'F')
  {
    digitalWrite(fire,HIGH);
     
  } 
  if(val == 'f'){
  digitalWrite(fire,LOW); 
  }
  if(val == 'B')
  {
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
     
  } 
  if(val == 'b'){
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);; 
  }
   if(val == 'Q'){  
    pos+=10;
    myservo.write(pos);
    delay(20);
    if(pos >= 180 ){
      pos=180;
    }   
  }
  
  if(val == 'E'){  
    pos-=10;
    myservo.write(pos);
    delay(20);
   if(pos <= 0 ){
     pos=0;   
   }   
  }
  
}

 ///////////ALWAYS CHECK READINGS FIRST OF THE ENVIRONMENT AND  CHECK LASER READINGS TOO
sensorValue = analogRead(sensorPin);
 

if ((sensorValue >=140 && sensorValue <= 280)){
  health-=10;
  Serial.print("H");
  delay(1000); 
}
 //Serial.println(sensorValue);// checking for environment light
// delay(500);
} 
  
