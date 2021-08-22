/*
Programa: serial_output.h
Autor: recursiveError

Header para gerenciar os includes para os expansores de saidas
*/

#ifndef _SERIAL_OUTPUT_H
#define _SERIAL_OUTPUT_H
    #if defined (__SHIFT_74HC595__)
        #include "expander/expander_74hc595.h"
    #else 
        /* default include */
        #include "expander/expander_74hc595.h"
    #endif
#endif