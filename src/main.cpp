#include "util/delay.h"
#include "display7seg.hpp"

unsigned int tick = 0;
int main(){
	display7seg::Display my_display(7, 6, 5, 4, 3, 2, 19, 15, 16, 17, 18);
	my_display.init();

	for(;;){
		my_display.write(tick/10);
		tick++;
		if(tick > 0xFFF8)tick = 0;
		my_display.update();
		_delay_ms(5);
	}
	return 0;
} 