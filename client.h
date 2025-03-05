#ifndef client_H
#define client_H

class client {
private:
    char name[50];   // Max 50 characters for the name
    char text[100];  // Max 100 characters for the text
    int payment;     // Payment amount
public:
    // Constructors
    // client();
    // client(const char* clientName, const char* clientText);
    client(const char* name, const char* text, int payment);

    // Getters
    const char* getName() const;
    const char* getText() const;
    int getPayment() const;

    // Setters
    // void setName(const char* clientName);
    // void setText(const char* clientText);
    // void setPayment(int clientPayment);

    // Display client information
    void display() const;

};

#endif // client_H
