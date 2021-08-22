#include "liquidcrystal.h"
#include "IO.h"
#define F_CPU 16000000L
int main(){
  LCD my_lcd;
  lcd_init(&my_lcd, RS, EN);
  lcd_send_string(&my_lcd, "teste\0");
  for(;;){
  }
  return 0;
}