#include "IO.hpp"
#include "expander_74hc595.hpp"
#include "liquidcrystal_expander_595.hpp"
#include <util/delay.h>


int main(){
	int num;
	auto my_lcd = liquidcrystal::Liquidcrystal595_4bits{4, 13, 12, 2, 3}.init(16,2)
		.write("1234567891011\0")
		.set_curso(1,0)
		.write("hello world\0");

	my_lcd.config(0x01)
		.write("bomdia\0")
		.set_curso(1,0)
		.write("ola mundo\0");

	for(;;){
		//_delay_ms(1000);
		//my_lcd.write("teste\0");
  	}
	return 0;
}

