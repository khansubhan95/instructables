//Connect the Transmitter data pin to Arduino pin 12 
//If you don't want to use pin 12 use vw_set_tx_pin(transmit_pin), with transmit_pin being desired pin ,in void setup
//Refer to the documentation in link for more details


#include <VirtualWire.h>

int xPin=0;
int yPin=1;

int ledPin=13;//led on pin 13 is ON except when transmitter is parallel to the ground

void setup() 
{
  vw_setup(2000);//Bits per second
  pinMode(ledPin,OUTPUT);
  //Serial.begin(9600);//Initialise the serial connection debugging
}

void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  
  //Serial.print("xval=");
  //Serial.println(xval);
  
  //Serial.print("yval=");
  //Serial.println(yval); 
  
  //delay(1000); //used to display values after 1s delay
  
  //Serial.print("\n");
  
  if ((xval>370 && xval<385) && (yval>360 && yval<380)) //stationary or stop(transmitter parallel to ground)
  {
    digitalWrite(ledPin,LOW);
    send("s");
  } 
  else 
  { 
    if ((xval>395 && xval<416) && (yval>360 && yval<380)) //forward(transmitter tilted forward)
    {
      digitalWrite(ledPin,HIGH);
      send("f");
      
    }
    if ((xval>345 && xval<365) && (yval>365 && yval<381)) //backward(transmitter tilted backward)
    {
      digitalWrite(ledPin,HIGH);
      send("a");
      
    }
    if ((xval>370 && xval<380) && (yval>335 && yval<355)) //left(transmitter tilted to left)
    {
      digitalWrite(ledPin,HIGH);
      send("l");
     }
     if ((xval>370 && xval<390) && (yval>385 && yval<395))//right(transmitter tilted to right)
    {
      digitalWrite(ledPin,HIGH);
      send("r");
      
    }
  }
  //delay(1000);
  
}


void send(char *message)//send function definition
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}