/*
Programa: expander_74hc595
Autor: RecursiveError

biblioteca para expansão de portas OUTPUT usando o shift-Register 74hc595
*/

#ifndef _EXPANDER_74hc595_H
#define _EXPANDER_74hc595_H

    
#include <stdint.h>

//defalut values
#define DATA 13
#define CLOCK 12
#define ENABLE 11

// "objeto" do expansor
typedef struct expander_74hc595{
    uint8_t data;
    uint8_t clock;
    uint8_t enable;
    void (*write)(struct expander_74hc595 *const, char);
    
}serial_output;

//construtor
serial_output* serial_output_C(uint8_t data, uint8_t clock, uint8_t enable);



#endif