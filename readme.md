# AVR-UTIL
esse projeto é uma extensão do repositório:

[AVR](https://github.com/RecursiveError/AVR)

tem o objetivo de criar uma coleção de bibliotecas para AVR usando C++ com técnica modernas de programação   

#### AVISO
Esse repositório tem apenas o intuito de demostrar os usos de C++ moderno em ambientes embarcados bare-metal 

as bibliotecas apenas terão porte para o microcontrolador Atmel328p 

## fase atual:
melhorias nas bibliotecas do repositório 
[AVR](https://github.com/RecursiveError/AVR)
### bibliotecas em melhoria:
#### Cancelado
- [x] [IO](lib/IO)
- [x] [Serial_output](lib/SO)
- [x] [LCD](lib/LCD)
- [x] [melhoria na lib ADC](lib/ADC)
- [x] [melhoria na lib Serial](lib/USART)
- [ ] ~~melhoria na lib Console~~
- [ ] melhoria na lib Timer
- [x] [melhoria na lib Interrupt](lib/Interrupt)

### novidades 
- [lib de interrupções externas](lib/external_interrupt)
- [lib para o comparador adc](lib/adc_comp)
- [lib para displays 7 segmentos](lib/disp7seg)

### Conclusão:

Eu iniciei esse projeto para aprender C++ e sistemas embarcados ao mesmo tempo, e com isso tirar minhas próprias conclusões sobre o uso de C++, nesses 3 meses de pesquisa e estudo, C++ provou trazer muitas vantagens em relação a C, é possível seguir na mesma linha do C mas com a vantagem de coisas como generics, que te ajudam a abstrair sem pesar no runtime.

Então porque esse projeto está chegando a o fim? quando comecei esse projeto eu não tinha noção do uso de C++, o que acabou gerando vários códigos com overenginner e overhead, além  de todos os códigos aqui são versões modificadas do repositório AVR, agora que eu tenho uma melhor noção das técnicas de desenvolvimento e o poder da linguagem, C++ vai entrar como minha nova linguagem principal em embarcados,  e vai fazer parte do repositório principal de AVR.
