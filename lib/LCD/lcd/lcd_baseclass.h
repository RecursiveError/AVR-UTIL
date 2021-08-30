#ifndef _LCD_BASECLASS_H
#define _LCD_BASECLASS_H

#include<stdint.h>
#include<serial_output.h>

typedef enum{
    _4BITS_ = 1,
    _8BITS_,
    FULL
}operating_mode;

typedef struct liquidcrystal_base{
    union{
        serial_output *controler;
        struct{
            uint8_t pins[8]; 
        };
    };
    uint8_t register_select, read_write, enable;
    int mode;
    void (*push_data)(struct liquidcrystal_base *const, uint8_t, uint8_t);
    void (*pulse)(struct liquidcrystal_base *const);
}liquidcrystal_base;
#endif
