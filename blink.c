#define F_CPU 1000000UL // Set CPU speed so the delay util correctly converts milliseconds to CPU ticks.

#include <avr/io.h>     // Provides DDRx and PORTx registers
#include <util/delay.h> // Provides delay functionality.

#define LEFT1 (1<<6)
#define LEFT2 (1<<7)

#define RIGHT1 (1<<5)
#define RIGHT2 (1<<4)
#define RIGHT3 (1<<3)
#define RIGHT4 (1<<2)
#define RIGHT5 (1<<1)

#define SIXTHEENTH          125
#define EIGHTH_STACC        100
#define EIGHTH_STACC_REST   150
#define EIGHTH              250
#define QUATER              500
#define DOTTED_QUATER       750

void halfBeatShort( int position )
{
    PORTB |= 1<<position;
    _delay_ms(600);
}

int main(void)
{
    char i;
    char isRestarted = 0;
    DDRB |= 0b11111110;
    PORTB = 0;

    while ( 1 )
    {
        for ( i = 0; i < 2; i++ )
        {
            // 1,3 -----
            PORTB ^= i == 0 && isRestarted ? LEFT1 | LEFT2 | RIGHT5 : LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= i == 0 && isRestarted ? LEFT1 | LEFT2 | RIGHT5 : LEFT1;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2;
            _delay_ms( EIGHTH );
            PORTB ^= LEFT2;

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            // 2,4 -----

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );
        }

        for ( i = 0; i < 2; i++ )
        {
            // 5, 9 -----
            PORTB ^= LEFT1 | RIGHT5;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT5;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2 | RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT4;
            _delay_ms( EIGHTH_STACC_REST );
            PORTB ^= LEFT2;

            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2 | RIGHT5;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2 | RIGHT5;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT4;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2 | RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2 | RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );


            // 6, 10 -----
            PORTB ^= LEFT1 | RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT4;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );
            PORTB ^= RIGHT4;

            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );
            PORTB ^= RIGHT3;


            // 7, 11 -----
            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= RIGHT2;
            _delay_ms( SIXTHEENTH );
            PORTB ^= RIGHT2 | RIGHT3;
            _delay_ms( SIXTHEENTH );

            PORTB ^= LEFT2 | RIGHT3 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );
            PORTB ^= LEFT2;

            PORTB ^= LEFT1 | RIGHT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2 | RIGHT2 | RIGHT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2 | RIGHT1;
            _delay_ms( EIGHTH_STACC_REST );


            // 8, 12 -----
            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2 | RIGHT1;
            _delay_ms( SIXTHEENTH );
            PORTB ^= LEFT2 | RIGHT1 | RIGHT2;
            _delay_ms( SIXTHEENTH );
            PORTB ^= RIGHT2;

            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT2 | RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2 | RIGHT4;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT5;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT5;
            _delay_ms( EIGHTH_STACC_REST );
        }


        for ( i = 0; i < 3; i++ )
        {
            // 13, 15, 17 ----
            PORTB ^= LEFT1 | LEFT2 | ( i == 3 ? RIGHT5 /*17*/ : RIGHT4 /*13, 15*/ );
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | LEFT2 | ( i == 3 ? RIGHT5 /*17*/ : RIGHT4 /*13, 15*/);
            _delay_ms( EIGHTH_STACC_REST );


            _delay_ms( EIGHTH );


            PORTB ^= RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | LEFT2 | RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | LEFT2 | RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | LEFT2 | RIGHT1;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | LEFT2 | RIGHT1;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= RIGHT2;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT2;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= RIGHT3;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= RIGHT3;
            _delay_ms( EIGHTH_STACC_REST );

            PORTB ^= LEFT1 | RIGHT4;
            _delay_ms( EIGHTH_STACC );
            PORTB ^= LEFT1 | RIGHT4;
            _delay_ms( EIGHTH_STACC_REST );


            if ( i == 0 || i == 2 )
            {
                // 14, 18 -----
                PORTB ^= LEFT2 | RIGHT3;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= RIGHT3;
                _delay_ms( EIGHTH_STACC_REST );


                _delay_ms( EIGHTH );


                PORTB ^= RIGHT5;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= RIGHT5;
                _delay_ms( EIGHTH_STACC_REST );

                _delay_ms( EIGHTH );

                PORTB ^= RIGHT3;
                _delay_ms( EIGHTH );

                PORTB ^= i == 0 ? /*14*/ LEFT2 | LEFT1 : /*16*/ 0;
                _delay_ms( EIGHTH );

                PORTB ^= i == 0 ? /*14*/ LEFT1 | LEFT2 : /*16*/ 0;
                _delay_ms( EIGHTH );

                PORTB ^= ( i == 0 ? /*14*/ LEFT2 | LEFT1 : /*16*/ 0 ) |
                    ( i == 0 ? RIGHT2 : RIGHT4 ) | RIGHT3;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= ( i == 0 ? /*14*/ LEFT1 : /*16*/ LEFT2 ) |
                    ( i == 0 ? RIGHT2 : RIGHT4 );
                _delay_ms( EIGHTH_STACC_REST );
            }
            else if ( i == 1 )
            {
                // 16 -----
                PORTB ^= LEFT2 | RIGHT3;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= RIGHT3;
                _delay_ms( EIGHTH_STACC_REST );

                PORTB ^= RIGHT3;
                _delay_ms( SIXTHEENTH );
                PORTB ^= RIGHT3 | RIGHT4;
                _delay_ms( SIXTHEENTH );

                PORTB ^= LEFT2 | LEFT1 | RIGHT4 | RIGHT3;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= RIGHT3;
                _delay_ms( EIGHTH_STACC_REST );

                PORTB ^= RIGHT2;
                _delay_ms( EIGHTH_STACC );
                PORTB ^= RIGHT2;
                _delay_ms( EIGHTH_STACC_REST );

                PORTB ^= LEFT1 | LEFT2 | RIGHT3;
                _delay_ms( QUATER );

                PORTB ^= LEFT2 | LEFT1;
                _delay_ms( EIGHTH );
                _delay_ms( SIXTHEENTH );
                PORTB ^= LEFT1 | RIGHT3;
                _delay_ms( SIXTHEENTH );
            }
        }

        // 19 -----
        PORTB ^= LEFT1 | LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2 | RIGHT3 | RIGHT4;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | RIGHT4 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= RIGHT3;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT2;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT2 | RIGHT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1;
        _delay_ms( EIGHTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT3 | RIGHT1;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT2 | RIGHT1;
        _delay_ms( SIXTHEENTH );

        // 20 -----
        PORTB ^= LEFT1 | LEFT2 | RIGHT2;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2 | RIGHT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT1;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2 | RIGHT1 | RIGHT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | RIGHT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= RIGHT3;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT2 | RIGHT3;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2 | RIGHT4;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2 | RIGHT4;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT1 | LEFT2;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | LEFT2;
        _delay_ms( SIXTHEENTH );

        PORTB ^= LEFT2 | RIGHT5;
        _delay_ms( EIGHTH );

        PORTB ^= LEFT2 | LEFT1;
        _delay_ms( SIXTHEENTH );
        PORTB ^= LEFT1 | RIGHT5;
        _delay_ms( SIXTHEENTH );

        isRestarted = 1;
    }

    // 2 -----

    return 0; // unreachable
}
