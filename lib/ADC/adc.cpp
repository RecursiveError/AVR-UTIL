#include "adc.hpp"
#include <avr/io.h>
namespace adc{
    Adc& Adc::init(Tref ref, uint8_t prescaler, bool adjust){
        ADMUX |= (ref << REFS0) | (adjust << ADLAR);
        ADCSRA |= (1<<ADEN) | (prescaler<<ADTS0);
        return *this;
    }

    Adc& Adc::disable(){
        ADCSRA = 0;
        DIDR0 = 0;
        return *this;
    }

    Adc& Adc::trigger(Ftrigger trigger){
        ADCSRA |= (1<<ADATE);
        ADCSRB |= (trigger<<ADTS0) & 0X0F;
        return *this;
    }

    Adc& Adc::start(){
        ADCSRA |= (1<<ADSC);
        return *this;
    }

    Adc& Adc::set_event(handler_func callback){
        ADCSRA |= (1<<ADIE);
        interrupt::handler.set_handle(ADC_vect_num, callback);
        interrupt::handler.enable();
        return *this;
    }

    uint16_t Adc::read(channel adc_pin){
        this->start();
        DIDR0 |= (1<<adc_pin);
        while(!(ADCSRA & (1<<ADSC)));
        DIDR0 |= (0<<adc_pin);
        return (uint16_t) (ADCL|(ADCH<<8));
    }

    bool Adc::get_flag(){
        return ADCSRA & (1<<ADIF);
    }
}