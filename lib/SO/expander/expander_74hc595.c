/*
Programa: expander_74hc595
Autor: RecursiveError

biblioteca para expansão de portas OUTPUT usando o shift-Register 74hc595
*/
#include <stdint.h>
#include <stdlib.h>
#include "IO.h"
#include "expander_74hc595.h"


//gera clock no pino de data
static void pulse_data(serial_output *const self){
    digitalWrite(self->clock, HIGH);
    digitalWrite(self->clock, LOW);
}

//gera clock no pino EN
static void pulse_en(serial_output *const self){
    digitalWrite(self->enable, HIGH);
    digitalWrite(self->enable, LOW);
}


//envias as informaçãos bit a bit para o 74hc595
static void __so_write__f(serial_output *const self, char value){
    for(char i = 0; i < 8; i++){
        digitalWrite(self->data, value & 0x80);
        pulse_data(self);
        value <<= 1;
    }
    pulse_en(self);
}

serial_output* serial_output_C(uint8_t data, uint8_t clock, uint8_t enable){
    serial_output *temp = (serial_output*)malloc(sizeof(serial_output));
    temp->data = data;
    temp->clock = clock;
    temp->enable = enable;
    temp->write = __so_write__f;
    pinMode(data, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(enable, OUTPUT);
    return temp;
}