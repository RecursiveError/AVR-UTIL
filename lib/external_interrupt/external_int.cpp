#include "external_int.hpp"
#include <interrupt.hpp>
#include "IO.hpp"


namespace external_int{
    External_int& External_int::config(int pin, int mode){
        switch(pin){
            case _INT1_:
                EICRA |= (mode <<= 2);
                EIMSK |= 1<<1;
                digitalIO::DigitalIO(3).input_pullup();
                break;
            case _INT0_:
                EICRA |= mode;
                EIMSK |= 1<<0;
                digitalIO::DigitalIO(2).input_pullup();
                break;
        }
        interrupt::handler.enable();
        return *this;
    }

    External_int& External_int::event_on(int pin, handler_func callback){
        switch(pin){
            case _INT0_:
                interrupt::handler.set_handle(INT0_vect_num, callback);
                break;
            case _INT1_:
                interrupt::handler.set_handle(INT1_vect_num, callback);
                break;
        }
        return *this;
    }
}