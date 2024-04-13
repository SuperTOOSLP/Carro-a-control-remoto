#include <IRremote.h>
int SENSOR = 11;
IRrecv irrecv(SENSOR);
decode_results results;

int motor_izquierda = 7;
int motor_derecha = 8;

void setup()
{
   Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(motor_izquierda, OUTPUT);
  pinMode(motor_derecha, OUTPUT);
}

void loop ()
{
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    irrecv.resume();}
    delay(100);

    if(results.value == 0x41048B7){ //////////para avanzar
      digitalWrite(motor_izquierda, HIGH);
      digitalWrite(motor_derecha, HIGH);
    }

    if(results.value == 0x410A857){ //////////para detenerse
      digitalWrite(motor_izquierda, LOW);
      digitalWrite(motor_derecha, LOW);
    }

     if(results.value == 0x41028D7){ //////////para girar a la DERECHA
      digitalWrite(motor_izquierda, HIGH);
      digitalWrite(motor_derecha, LOW);
    }
    
     if(results.value == 0x4106897){ //////////para girar a la izquierda
     digitalWrite(motor_izquierda, LOW);
      digitalWrite(motor_derecha, HIGH);
}
}
