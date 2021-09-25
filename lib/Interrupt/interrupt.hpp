#ifndef _INTERRUPT_HPP
#define _INTERRUPT_HPP

#include "avr/io.h"
#include "avr/interrupt.h"
#include <interrupt_handle.hpp>
interrupt::Interrupt handler;

ISR(TIMER0_OVF_vect){
    //PORTD ^= 0xFF;
    exec(handler, TIMER0_OVF_vect_num);
}
#endif