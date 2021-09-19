#include "IO.hpp"
#include "expander_74hc595.hpp"
#include "liquidcrystal.hpp"
#include <WString.h>
#include <util/delay.h>
#include <Arduino.h>


using namespace liquidcrystal;

int main(){
	Liquidcrystal(Lcd595_4bits(4,13,12,2,3))
	.init(16, 2)
	.write("unique_ptr teste")
	.set_cursor(1,0)
	.write("ola mundo 123");

	Liquidcrystal(Lcd2EN_4bits(7,6,5,8,9,10,11))
	.init(40, 4)
	.write("just a teste 2")
	.set_cursor(1,0)
	.write("just a teste 2")
	.set_cursor(3,0)
	.write("123456789");                        


	for(;;);
	return 0;
}