#include "external_int.hpp"
#include "util/delay.h"
#include "IO.hpp"
#include "liquidcrystal.hpp"
#include "adc_comp.hpp"

using namespace external_int;
using namespace liquidcrystal;
int tick = 0;
int comp_std = 0;
int main(){
	digitalIO::DigitalIO(3).output().set_low();
	Liquidcrystal my_lcd(Lcd2EN_4bits(12,13,4,11,10,9,8));
	external_int::External_int()
		.event_on(_INT0_, DOWN, [](){
			tick++;
		});
	comparator::Adc_comparator().set_event(comparator::ANY, []()-> void{
		if(comparator::Adc_comparator().get_output()){
			digitalIO::DigitalIO(3).set_high();
			comp_std = 1;
		}
		else{
			digitalIO::DigitalIO(3).set_low();
			comp_std = 0;
		}
	})
	.enable();

	for(;;){
		my_lcd.init(40, 4)
		.set_cursor(0,0)
		.write("- TICKS: ")
		.set_cursor(0, 10)
		.write(tick)
		.set_cursor(1, 0)
		.write("COMP:")
		.set_cursor(1, 10)
		.write(comp_std);
	}
	return 0;
}