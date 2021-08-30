/*
Programa: liquidcrystal.h
Autor: RecursiveError

header para gerenciar LCDs
*/
#ifndef _LIQUIDCRYSTAL_H
#define _LIQUIDCRYSTAL_H
#include <stdarg.h>
#include "lcd/lcd_baseclass.h"

#define new_liquidcrystal(type, mode, ...) _liquidcrystal_C(type, mode,(int[]){__VA_ARGS__})
//TIPOS DE DISPLAYS disponeveis
typedef enum{
    _NORMAL_ = 1,
    _SHIFT_74HC595_ = 6
}lcd_type;

typedef struct liquidcrystal{
    liquidcrystal_base *super;
    lcd_type type;
    void (*init)(struct liquidcrystal *const);
    void (*write)(struct liquidcrystal *const, char *);
    void (*write_char)(struct liquidcrystal *const, char);
    void (*write_number)(struct liquidcrystal *const, int8_t);
    void (*set_position)(struct liquidcrystal *const, uint8_t, uint8_t);
    void (*command)(struct liquidcrystal *const, uint8_t);
}liquidcrystal;

liquidcrystal* _liquidcrystal_C(lcd_type type, operating_mode mode, int pins[static 11]);



#endif