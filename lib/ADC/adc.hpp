#ifndef _ADC_HPP
#define _ADC_HPP
#include<avr/io.h>
#include<avr/interrupt.h>

ISR(ANALOG_COMP_vect);

namespace adc{
    class Adc : public adc_comparator, public adc_converter{

    };

    class adc_converter{

    };

    class adc_comparator{

    };

    Adc default_adc;
}

#endif