#include <util/delay.h>
#include "display7seg.hpp"
#include "liquidcrystal.hpp"
#include "usart.hpp"
#include "adc.hpp"
#include "interrupt.hpp"
#include "IO.hpp"

int main(){
	digitalIO::DigitalIO red(7);
	digitalIO::DigitalIO blue(5);
	digitalIO::DigitalIO green(6);
	red.output().set_high();
	blue.output().set_high();
	green.output().set_high();

	int result_lux = 0;

	adc::Adc scanner(adc::AVCC, 7, false);
	liquidcrystal::Liquidcrystal my_lcd(liquidcrystal::Lcd_4bits(13,12,8,9,10,11));
	my_lcd.init(16, 2)
	  .write("LuximetroDigital")
	  .set_cursor(1,0)
	  .write("Lux:\0");
	for(;;){
		result_lux = scanner.read(adc::ADC0);
		my_lcd.set_cursor(1,10).write(result_lux);
		if(result_lux > 550){
			green.set_high();
			red.set_low();
		}else{
			red.set_high();
			green.set_low();
		}
		_delay_ms(75);
	}

	return 0;
} 

void usart_print_num(unsigned int value){
	if(value > 9999u) return;
    uint8_t M = (value/1000)%10;
    uint8_t C = (value/100)%10;
    uint8_t D = (value/10)%10;
    uint8_t U = (value/1)%10;
	usart::Usart().transmit(M+'0')
	.transmit(C+'0')
	.transmit(D+'0')
	.transmit(U+'0')
	.transmit('\n');
}