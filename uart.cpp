#include <avr/io.h>
#include <stdio.h>

#include <util/setbaud.h>

void uart_init(void) 
{
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;
    
#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */ 
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */    
}

int uart_putchar(char c, FILE *stream = NULL) 
{
    if (c == '\n') {
        uart_putchar('\r');
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return(0);
}

int uart_getchar(FILE *stream=NULL) 
{
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

//FILE uart_output = FDEV_SETUP_STREAM(=uart_putchar, NULL, _FDEV_SETUP_WRITE);

static FILE uart_output;
static FILE uart_input; 

//FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

void init_serial() 
{
    uart_output.flags =_FDEV_SETUP_WRITE;
    uart_output.put =  uart_putchar;

    uart_input.flags =_FDEV_SETUP_READ;
    uart_input.get =  uart_getchar;

    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
}