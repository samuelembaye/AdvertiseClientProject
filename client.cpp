#include "client.h"
#include <stdio.h>  // For the sprintf function
#include <string.h> 

// Default constructor
// client::client() {
//     name[0] = '\0';  // Initialize as empty string
//     text[0] = '\0';  // Initialize as empty string
//     payment = 0;
// }

// Constructor with name and text
// client::client(const char* clientName, const char* clientText) {
//     strncpy(name, clientName, sizeof(name) - 1);
//     name[sizeof(name) - 1] = '\0';  // Ensure null-terminated
//     strncpy(text, clientText, sizeof(text) - 1);
//     text[sizeof(text) - 1] = '\0';  // Ensure null-terminated
//     payment = 0;
// }

client::client(const char* name, const char* text, int payment) {
    // Copy name
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';  // Ensure null-terminated

    // Copy text
    strncpy(this->text, text, sizeof(this->text) - 1);
    this->text[sizeof(this->text) - 1] = '\0';  // Ensure null-terminated

    // Assign payment
    this->payment = payment;
}


// Getters
const char* client::getName() const {
    return name;
}

const char* client::getText() const {
    return text;
}

int client::getPayment() const {
    return payment;
}

// Setters
// void client::setName(const char* clientName) {
//     strncpy(name, clientName, sizeof(name) - 1);
//     name[sizeof(name) - 1] = '\0';  // Ensure null-terminated
// }

// void client::setText(const char* clientText) {
//     strncpy(text, clientText, sizeof(text) - 1);
//     text[sizeof(text) - 1] = '\0';  // Ensure null-terminated
// }

// void client::setPayment(int clientPayment) {
//     payment = clientPayment;
// }

// Display client information (For debugging or serial output)
// void client::display() const {
//     char buffer[150];  // Buffer to format the client info
//     printf(buffer, sizeof(buffer), "Name: %s, Text: %s, Payment: %d", name, text, payment);
//     printf("\n";
//     // Serial.println(buffer);  // Send the output to the serial monitor
// }
