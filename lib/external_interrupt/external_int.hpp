#ifndef EXTERNAL_INT_HPP
#define EXTERNAL_INT_HPP
typedef void (*handler_func)();
namespace external_int{

    enum External_pin{
        _INT0_ = 0,
        _INT1_,
        _PCINT0_,
        _PCINT1_,
        _PCINT2_
    };

    enum mode{
        _LOW_,
        _ANY_,
        _DOWN_,
        _UP_
    };
    

    class External_int{
        public:
            //CONFIGURA O MODO DE FUNCIONAMENTO (HABILITA A CHAVE DE INTERRUPÇÃO GLOBAL!)
            External_int& config(int pin, int mode);
            //Desabilita a interrupção (NÃO DESABILITA A CHAVE DE INTERRUPÇÃO GLOBAL!)
            External_int& disable(int pin);
            //cria um handler para o evento
            External_int& event_on(int pin, handler_func callback);
    };
}
#endif