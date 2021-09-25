#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "interrupt.hpp"
#include "IO.hpp"

int main(){
	digitalIO::DigitalIO led(2);
	led.output().set_high();
	TCCR0A = 0x00;//timer em modo normal
	TCCR0B = 0B101;//prescaler de 64
	TIMSK0 = (1<<TOIE0);//interrupção no overflow do timer
	sei();
	handler.set_handle(TIMER0_OVF_vect_num, [](){
		digitalIO::DigitalIO(2).toggle();
		return;
	});


	for(;;){
	}
	return 0;
}