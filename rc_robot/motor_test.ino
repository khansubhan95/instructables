int lm=9;//pin 9 of arduino to pin 7 of ic
int lmr=8;//pin 8 of arduino to pin 2 of ic 
int rm=10;//pin 10 of arduino to pin 10 of ic
int rmr=11;//pin 11 of arduino to pin 15 of ic



void setup()
{
  pinMode(lm,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(rmr,OUTPUT);
}

void loop()
{
  digitalWrite(lm,LOW);   //both move forward
  digitalWrite(lmr,HIGH);
  digitalWrite(rm,HIGH);
  digitalWrite(rmr,LOW);
}
  