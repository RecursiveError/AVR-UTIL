#include "external_int.hpp"
#include "interrupt.hpp"
#include "util/delay.h"
#include "IO.hpp"
#include "liquidcrystal.hpp"

using namespace external_int;
using namespace liquidcrystal;
int tick = 0;
int main(){

	Liquidcrystal my_lcd(Lcd2EN_4bits(7,6,5,8,9,10,11));
	external_int::External_int()
		.event_on(_INT0_, _DOWN_, [](){
			tick++;
		});

	for(;;){
		my_lcd.init(40, 4)
		.write("- TICKS: ")
		.set_cursor(0, 10)
		.write(tick);
	}
	return 0;
}