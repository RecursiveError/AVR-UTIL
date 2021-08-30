#include "liquidcrystal.h"
#include "builder.h"
#include "IO.h"
#define F_CPU 16000000L
int main(){
  liquidcrystal *my_lcd = builder(liquidcrystal,_SHIFT_74HC595_, _4BITS_, 13, 12, 11, 8, 9);
  my_lcd->init(my_lcd);
  my_lcd->write(my_lcd,"teste4?\0");
  for(;;){
  }
  return 0;
}