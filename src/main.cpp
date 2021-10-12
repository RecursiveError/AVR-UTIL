#include <util/delay.h>
#include "display7seg.hpp"
#include "usart.hpp"
#include "adc.hpp"

void usart_print_num(unsigned int value);

int main(){
	uint16_t result{0};
	adc::Adc scanner;
	usart::Usart output;
	display7seg::Display my_display(7, 6, 5, 4, 3, 2, 19, 15, 16, 17, 18);
	my_display.init();
	scanner.init(adc::AVCC);
	output.enable();
	for(;;){
		result = scanner.read(adc::ADC0);
		my_display.write(result);
		my_display.update();
		usart_print_num(result);
		_delay_ms(1);
	}
	return 0;
} 

void usart_print_num(unsigned int value){
	if(value > 9999u) return;
    uint8_t M = (value/1000)%10;
    uint8_t C = (value/100)%10;
    uint8_t D = (value/10)%10;
    uint8_t U = (value/1)%10;
	usart::Usart().transmit(M+'0');
	usart::Usart().transmit(C+'0');
	usart::Usart().transmit(D+'0');
	usart::Usart().transmit(U+'0');
	usart::Usart().transmit('\n');
}