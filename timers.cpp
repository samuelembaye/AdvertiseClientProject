// timers.cpp
#include "timers.h"

// Timer variables
volatile uint16_t uart_timer = 0;
volatile uint16_t lcd_timer = 0;
volatile bool uart_timer_flag = false;
volatile bool lcd_timer_flag = false;
volatile uint16_t scroll_ms_counter = 0; 
volatile bool scroll_ms_counter_flag = false; // Delay flag

void Timer1_Init() {
    TCCR1B |= (1 << WGM12);  // Configure Timer1 in CTC mode
    OCR1A = 15624;           // Set the compare value for 1 second (16MHz/1024)
    TCCR1B |= (1 << CS12) | (1 << CS10);  // Prescaler 1024
    TIMSK1 |= (1 << OCIE1A); // Enable Timer1 compare interrupt
    sei();                   // Enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
    // PORTB ^= (1 << PB0); // Toggle an LED on pin PB0 (digital pin 8 on Arduino Uno)
    // Decrement and set flags for USART timer
    if (uart_timer > 0) {
        uart_timer--;
        if (uart_timer == 0) {
            uart_timer_flag = true;
        }
    }

    // Decrement and set flags for LCD timer
    if (lcd_timer > 0) {
        lcd_timer--;
        if (lcd_timer == 0) {
            lcd_timer_flag = true;
        }
    }
     // Decrement and set flags for LCD timer
    if ( scroll_ms_counter > 0) {
        scroll_ms_counter--;
        if (scroll_ms_counter == 0) {
            scroll_ms_counter_flag = true;
        }
    }
}

void set_uart_timer(uint16_t seconds) {
    uart_timer = seconds;
    uart_timer_flag = false;
}

void set_lcd_timer(uint16_t seconds) {
    lcd_timer = seconds;
    lcd_timer_flag = false;
}

void set_delay_timer(uint16_t ms) {
    scroll_ms_counter = ms;
    scroll_ms_counter_flag = false;
}

bool is_delay_elapsed() {
    return scroll_ms_counter_flag;
}