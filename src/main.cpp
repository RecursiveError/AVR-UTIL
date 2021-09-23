#include "liquidcrystal.hpp"
#include <WString.h>


using namespace liquidcrystal;

int main(){
	Liquidcrystal(Lcd595(4,13,12,2,3))
		.init(16,2)
		.write("ola, mundo!")
		.set_cursor(1,10)
		.write("TESTE");

	Liquidcrystal(Lcd2EN_4bits(7,6,5,8,9,10,11))
		.init(40, 4)
		.write("ola, mundo!")
		.set_cursor(1,0)
		.write("bom dia")
		.set_cursor(2,10)
		.write("123456789");

	for(;;);
	return 0;
}