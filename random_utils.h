// Random_utils.h:
#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include "client.h"  // Assuming the client class is defined in client.h

// Function to seed the random number generator using the current time
void seedRandom();

// Function to get a weighted random index based on payment and excluding the previous index
int getWeightedRandomIndex(client clients[], int numclients, int previousIndex);

#endif // RANDOM_UTILS_H
