#include <IRremote.h>

int lm=9;//pin 9 of arduino to pin 7 of l293d
int lmr=8;//pin 8 of arduino to pin 2 of l293d 
int rm=10;//pin 10 of arduino to pin 10 of l293d
int rmr=11;//pin 11 of arduino to pin 15 of l293d

int RECV_PIN = 6;//pin 6 of arduino to data pin of ir receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(lm,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(rmr,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
    }
   //bot moves front
    if(results.value==0x80BF53AC)
    {
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
    }
    //bot moves back
    if(results.value==0x80BF4BB4)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,LOW);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,HIGH);
    }
    //bot moves left
     if(results.value==0x80BF9966)
    {
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
    }
    //bot moves right
     if(results.value==0x80BF837C)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
    }
    //bot stops
    if(results.value==0x80BF738C)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
    }
}
    
    
    
    
    
    
    
