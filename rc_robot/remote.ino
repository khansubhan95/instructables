#include <IRremote.h>

int RECV_PIN = 6;//pin 6 of arduino to data pin of ir receiver
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
          delay(1000);

    }
}
