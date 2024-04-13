///Pasa esta esta programación a tu placa de arduino para ver los codigos del control remoto. Sigue los pasos del video
/// SuperTOOLSLP

#include <IRremote.h>
int SENSOR = 11;
IRrecv irrecv(SENSOR);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop ()
{
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();}
    delay(100);
}
