#include "external_int.hpp"
#include "interrupt.hpp"
#include "util/delay.h"
#include "IO.hpp"

using namespace external_int;
int main(){

	external_int::External_int()
		.config(_INT0_,_DOWN_)
		.event_on(_INT0_, [](){
		digitalIO::DigitalIO(4).output().toggle();
		});
	sei();
	for(;;){
		digitalIO::DigitalIO(3).output().toggle();
		_delay_ms(500);
	}
	return 0;
}