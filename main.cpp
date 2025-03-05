#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include "lcd.h"
#include "uart.h"
#include "client.h"
#include "random_utils.h"
#include "timers.h"


#define LED_PIN 2
#define BUTTON_PIN 1 

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


#define BUTTON_IS_CLICKED(PINB,BUTTON_PIN) !BIT_CHECK(PINB,BUTTON_PIN)

 void allInit(){
    init_serial();
    // Initialize timers
    Timer1_Init();
    sei(); 
    
}

int main(void){    
    
    HD44780 lcd;
    lcd.Initialize(); // Initialize the LCD
    lcd.Clear();
    allInit();
    int lastIndex = 1;
    int index = 0;
    
    set_uart_timer(3); // Set USART action every 10 seconds
    set_lcd_timer(2);    // Set LCD update every 2 seconds

    client advertise[] = {
        client("Harry", "Kop bil hos Harry", 5000),
        client("Anka", "Kop paj hos Farmor Anka", 3000),
        client("Petter", "Lat Petter bygga at dig", 1500),
        client("Langben", "Mysterier? Ring Langben", 1000)

    };

    int  numclients = sizeof(advertise) / sizeof(advertise[0]);
    // Clear the LCD
    lcd.Clear();
    
    lcd.WriteText("NACKADEMIN I0T24 ");

    // // main loop to debug
    // volatile uint16_t timer_count = TCNT1;
    // printf("Timer count: %d\n", timer_count);
    
    while(true) {
        if (uart_timer_flag) {
            uart_timer_flag = false;
            char inchar;
            set_uart_timer(5); // Reset USART timer

            printf("Admin info: \n");            
            // printf("Waiting for input.\n");
            for (int i = 0; i < numclients; ++i) {
                        printf("Client : %s  Amount Paid: %d\n",  advertise[i].getName(), advertise[i].getPayment());
                    }

            // // Correct way to get a character from input
            // if (scanf(" %c", &inchar) == 1) { // Use ' %c' to ignore leading whitespace
            //     // printf("You entered: %c\n", inchar);
            //     if (inchar == 'a') {
            //         // printf("You pressed 'a'.\n");
            //         for (int i = 0; i < numclients; ++i) {
            //             printf("Client : %s  Amount Paid: %d\n",  advertise[i].getName(), advertise[i].getPayment());
            //         }
            //     } else if (inchar == 'b') {
            //         // printf("You pressed 'b'.\n");
            //         for (int i = 0; i < numclients; ++i) {
            //             printf("Text: %s\n", advertise[i].getText());
            //         }
            //     } else if (inchar == 'c') {
            //         // printf("You pressed 'c'.\n");
            //         for (int i = 0; i < numclients; ++i) {
            //             printf("Amount Paid: %d\n", advertise[i].getPayment());
            //         }
            //     } else {
            //         printf("Invalid input.\n");
            //     }
                // } 
                // else {
                //     printf("Error reading input.\n");
                // }
            }

        // Handle LCD actions every 2 seconds
        if (lcd_timer_flag) {
            lcd_timer_flag = false;
            set_lcd_timer(2); // Reset LCD timer
            // Get a weighted random index
            index = getWeightedRandomIndex(advertise, numclients, lastIndex);
            // Clear the LCD
            lcd.Clear();
            // lcd.WriteText((char *)advertise[index].getText());
            lcd.ScrollText(advertise[index].getText(), 0);
            lastIndex = index;
            // printf("Index: %d\n", index);
            // _delay_ms(1000);
            // printf(advertise[index].getName());
            // printf("\n");
         }
    
    
    }
     return 0;
}
