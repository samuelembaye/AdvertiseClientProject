// timers.h 
#ifndef TIMERS_H
#define TIMERS_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

// Timer Flags
extern volatile uint16_t uart_timer; // Timer for USART actions
extern volatile uint16_t lcd_timer;   // Timer for LCD actions
extern volatile bool uart_timer_flag;
extern volatile bool lcd_timer_flag;
extern volatile uint16_t scroll_ms_counter; 
extern volatile bool scroll_ms_counter_flag; 

// Initialize Timer1 for 1-second intervals
void Timer1_Init();

// Set timers
void set_uart_timer(uint16_t seconds);
void set_lcd_timer(uint16_t seconds);
void set_delay_timer(uint16_t ms);
bool is_delay_elapsed();

#endif // TIMERS_H
