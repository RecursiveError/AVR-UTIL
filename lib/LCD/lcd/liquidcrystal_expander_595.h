/*
Programa: liquidcrystal_expander_595.h
Autor: RecursiveError

biblioteca para o displays compativeis com o HD44780 usando o shift-register 74hc595

essa biblioteca também é compatível com controladores semelhantes ao shift-register 74hc595
*/

#ifndef _LCD_595_H
#define _LCD_595_H


#include <stdint.h>
#include<lcd/lcd_baseclass.h>
#include "serial_output.h"
#define RS 8
#define EN 9

typedef liquidcrystal_base liquidcrystal_595;

liquidcrystal_595* _liquidcrystal_595_C(operating_mode mode, uint8_t data, uint8_t clock,uint8_t enable,\
                                       uint8_t register_select, uint8_t lcd_enable);
#endif