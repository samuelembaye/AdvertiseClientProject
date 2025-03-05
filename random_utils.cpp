// random_utils.cpp
#include <stdlib.h>  // For srand() and rand()
#include <avr/io.h>  // For AVR I/O registers
#include <avr/interrupt.h>  // For interrupts
#include "random_utils.h"
#include "uart.h"
#include "client.h"
#include "timers.h"

// Global counter for pseudo-time
// uint32_t pseudoTime = 0;



// Seed the random number generator using pseudo-time
// void seedRandom() {
//     // Use pseudoTime as the seed for srand()
//     srand(pseudoTime);
// }

// Get a weighted random index from a list of clients
int getWeightedRandomIndex(client clients[], int numclients, int previousIndex) {
    int totalPayment = 0;

    // Calculate the total weight (sum of payments)
    for (int i = 0; i < numclients; ++i) {
        totalPayment += clients[i].getPayment();
    }

    while (true) {
        // Generate a random number within the range of total weights
        int randomValue = rand() % totalPayment;

        int cumulativeWeight = 0;

        // Loop through clients to select a weighted random index
        for (int i = 0; i < numclients; ++i) {
            cumulativeWeight += clients[i].getPayment();

            if (randomValue < cumulativeWeight) {
                // Check for exclusion of previousIndex
                if (i != previousIndex) {
                    return i;
                }

                // If same as previousIndex, restart selection
                break;
            }
        }
    }

    // Fallback case (should never occur)
    return 0;
}

