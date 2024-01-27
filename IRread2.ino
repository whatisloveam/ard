#include "IRremote.h"

IRrecv irrecv(2);
decode_results results;

void setup() {
  irrecv.enableIRIn();
}

void loop() 
{
  if ( irrecv.decode( &results )) 
  {
    switch ( results.value ) 
    {
      case 0xFFA857:
        digitalWrite( 13, HIGH );
        break;
      case 0xFFE01F:
        digitalWrite( 13, LOW );
        break;
    }    
    irrecv.resume();
  }
}
