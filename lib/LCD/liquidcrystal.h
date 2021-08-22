/*
Programa: liquidcrystal.h
Autor: RecursiveError

header para gerenciar LCDs
*/
#ifndef _LIQUIDCRYSTAL_H
#define _LIQUIDCRYSTAL_H

    #if defined (__LCD_8BITS__)
        #error "LCD 8bits ainda não foi implementado"
    #elif defined (__LCD_595__)
        #include "lcd/liquidcrystal_expander_595.h"
    #elif defined (__LCD_I2C__)
        #error "LCD I2C ainda não foi implementado"
    #elif defined (__LCD_4BITS__)
        #error "LCD 4bits ainda não foi implementado"
    #else 
        /*Default include*/
        #include "lcd/liquidcrystal_expander_595.h"
    #endif


#endif