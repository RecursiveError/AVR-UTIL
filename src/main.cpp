#include "external_int.hpp"
#include "interrupt.hpp"
#include "util/delay.h"
#include "IO.hpp"

using namespace external_int;
int main(){

	external_int::External_int()
		.event_on(_INT0_, _DOWN_, [](){
			digitalIO::DigitalIO(4).output().toggle();
		})
		.event_on(_INT1_, _ANY_, [](){
			digitalIO::DigitalIO(6).toggle();
		});

	for(;;){
		digitalIO::DigitalIO(3).output().toggle();
		_delay_ms(500);
	}
	return 0;
}