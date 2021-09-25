#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "interrupt.hpp"
#include "IO.hpp"

int main(){
	digitalIO::DigitalIO led(2);
	led.output().set_high();
	TCCR1A = 0x00;//timer em modo normal
	TCCR1B = 0x3;//prescaler de 64
	TIMSK1 = (1<<TOIE0);//interrupção no overflow do timer
	sei();
	interrupt::handler.set_handle(TIMER1_OVF_vect_num, [](){
		digitalIO::DigitalIO(2).toggle();
		return;
	});
	
	for(;;);
	return 0;
}