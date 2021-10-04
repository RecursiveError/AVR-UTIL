/*  Autor:RecursiveError
biblioteca com as funções basicas de perifericos E operações para manipulação de bits
*/

#include "IO.hpp"
#include <avr/io.h>

namespace digitalIO{
    DigitalIO& DigitalIO::output(void){
        if(this->_pin < 8){
            DDRD |= (1<<this->_pin);
        }else{
            DDRB |= (1<<(this->_pin - 8u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::input(void){
        if(this->_pin < 8){
            DDRD &= ~(1<<this->_pin);
        }else{
            DDRB &= ~(1<<(this->_pin - 8u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::input_pullup(void){
        if(this->_pin < 8){
            DDRD &= ~(1<<this->_pin);
            this->set_high();
        }else{
            DDRB &= ~(1<<(this->_pin - 8u));
            this->set_high();
        }
        return *this;
    }

    DigitalIO& DigitalIO::set_high(void){
        if(this->_pin < 8){
            PORTD |= (1<<this->_pin);
        }else{
            PORTB |= (1<<(this->_pin - 8u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::set_low(void){
        if(this->_pin < 8){
            PORTD &= ~(1<<this->_pin);
        }else{
            PORTB &= ~(1<<(this->_pin - 8u));
        }
        return *this;
    }

    DigitalIO& DigitalIO::toggle(void){
        if(this->_pin < 8){
            PORTD ^= (1<<this->_pin);
        }else{
            PORTB ^= (1<<(this->_pin - 8u));
        }
        return *this;
    }

    bool DigitalIO::read(void){
        if(this->_pin < 8){
            return (PIND & (1<<this->_pin));
        }else{
            return (PINB & (1<<(this->_pin-8)));
        }
    }
    

}