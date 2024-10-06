#include <iostream>

using namespace std;

void cancelTicket() {
    int trainNumber;
    cout << "Enter the train number to cancel ticket: ";
    cin >> trainNumber;

    // Assuming you have a function to cancel the ticket
    // For demonstration purposes, we'll just print a success message
    cout << "Ticket cancelled successfully!" << endl;
}

int main() {
    int choice;
    cout << "Welcome to Railyatri" << endl << "What would you like to do?" << endl;
    cout << "1. See available train data" << endl;
    cout << "2. Book a ticket" << endl;
    cout << "3. Cancel a ticket" << endl;
    cout << "Choose: 1, 2, or 3: ";
    cin >> choice;

    if (choice == 3) {
        cancelTicket();
    }

    return 0;
}
