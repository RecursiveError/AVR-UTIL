#include "IO.hpp"
#include "expander_74hc595.hpp"
#include "liquidcrystal.hpp"
#include <WString.h>
#include <util/delay.h>
#include <Arduino.h>



using namespace liquidcrystal;

int main(){
	/*
	Liquidcrystal(Lcd_4bits(7,6,8,9,10,11))
		.init(16,2)
		.write("BOM DIA")
		.set_cursor(1,10)
		.write("TESTE");
	*/
	Liquidcrystal(Lcd2EN_4bits(7,6,5,8,9,10,11))
	.init(40, 4)
	.write("bom dia")
	.set_cursor(1,0)
	.write("glr ")
	.set_cursor(2,10)
	.write("asihfbaeiyfgsae9ufgh");                        
	for(;;);
	return 0;
}