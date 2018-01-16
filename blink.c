#define F_CPU 1000000UL // Set CPU speed so the delay util correctly converts milliseconds to CPU ticks.

#include <avr/io.h>     // Provides DDRx and PORTx registers
#include <util/delay.h> // Provides delay functionality.

int main(void)
{
    DDRB |= 0b00000111; // Set the first three B registers to be output
    PORTB = 0;          // Reset all outputs to start
    // The following is a polyrithm pattern. 
    // Register 0 toggles twice per cycle.
    // Register 1 toggles three times per cycle.
    // Register 2 toggles four time sper cycle.
    while( 1 )
    {
        PORTB ^= 0b111;
        _delay_ms(600);
        PORTB ^= 0b100;
        _delay_ms(200);
        PORTB ^= 0b010;
        _delay_ms(400);
        PORTB ^= 0b101;
        _delay_ms(400);
        PORTB ^= 0b010;
        _delay_ms(200);
        PORTB ^= 0b100;
        _delay_ms(600);
    }

    return 0; // unreachable
}
