#include<avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>


void InitSystem(void){

 // Connect leds to port B
 // Set pins low and output
 DDRB=0xff;
 PORTB = 0x00; 
 
 // Set all port D pins to be an input
 DDRD = 0x00;   
 PORTD = 0xff;

}

void buttonPressed(uint8_t *mode){

 // Change rgb led color on button press
 switch(*mode) {

   case 0:
      PORTB = 0xff;
      *mode = 1;
      break; 
	
   case 1:
      PORTB = (1 << PB1);
      *mode = 2;
      break;

   case 2:
      PORTB = (1 << PB2);
      *mode = 3;
      break;

   default :
      PORTB = (1 << PB3);
      *mode = 0;
      break;
 }

}

int main(void){
	
 uint8_t ledMode = 0;
 InitSystem();
 sei();

 while(1) {
	
        // If button is pressed
	if(!(PIND & (1<<PD0))) {
	  buttonPressed(&ledMode);
          _delay_ms(200); 
	}

  }
}


