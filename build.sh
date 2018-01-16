mkdir -p build
avr-gcc\
    -Os\
    -mmcu=atmega8a\
    -funsigned-char\
    -funsigned-bitfields\
    -fpack-struct\
    -fshort-enums\
    -ffunction-sections\
    -fdata-sections\
    -c\
    -o ./build/blink.o\
    ./blink.c
avr-gcc -mmcu=atmega8a ./build/blink.o -o ./build/blink
avr-objcopy -O ihex -R .eeprom ./build/blink ./build/blink.hex
avrdude -p m8 -c avrispmkII -U flash:w:./build/blink.hex
