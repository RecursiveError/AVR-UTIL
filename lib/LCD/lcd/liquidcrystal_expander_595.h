/*
Programa: liquidcrystal_expander_595.h
Autor: RecursiveError

biblioteca para o displays compativeis com o HD44780 usando o shift-register 74hc595

essa biblioteca também é compatível com controladores semelhantes ao shift-register 74hc595
*/

#ifndef _LCD_595_H
#define _LCD_595_H


#include <stdint.h>

#include "serial_output.h"//inclue o controlador

//"objeto" para o LCD
typedef struct liquidcrystal_expander_595{
    serial_output controler;
    uint8_t resister_select;
    uint8_t enable;
}LCD;

//default values
#define RS 8
#define EN 9
void lcd_init(LCD *const self, uint8_t register_select, uint8_t enable);
void lcd_send_char(LCD *const self, char value);
void lcd_send_string(LCD *const self, char string[]);
void lcd_send_number(LCD *const self, int value);
void lcd_set_position(LCD *const self, int linha, int coluna);
void lcd_pulse(LCD *const self);
void lcd_command(LCD *const self, char value);



#endif