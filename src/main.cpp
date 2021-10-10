#include "util/delay.h"
#include <avr/pgmspace.h>
#include <usart.hpp>

const char text[] = "HELLO WORLD!\n\0";
int main(){
	usart::Usart my_output;
	my_output.enable();
	for(;;){
		for(int i = 0; text[i] != '\0'; i++){
			my_output.transmit(text[i]);
		}
		_delay_ms(1000);
	}
	return 0;
} 