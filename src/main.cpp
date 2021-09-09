#include "IO.hpp"
#include "expander_74hc595.hpp"
#include "liquidcrystal_expander_595.hpp"
#include <util/delay.h>


int main(){
	auto led1 = serial_output::Expander_74hc595{4, 13, 12}.init();
	auto my_lcd = liquidcrystal::Liquidcrystal595_4bits{4, 13, 12, 2, 3}.init(16,2)
		.config(0x01)
		.write("1234567891011\0")
		.set_curso(1,0)
		.write("hello world\0");
	while(true){
		_delay_ms(500);
		led1.send(0b00010000);
    	_delay_ms(500);
		led1.send(0b00000000);
  	}
	return 0;
}

