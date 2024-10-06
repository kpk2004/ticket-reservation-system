#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Ticket {
    int ticketID;
    string passengerName;
    bool isCancelled;
};

class TicketManager {
private:
    vector<Ticket> tickets;

public:
    void bookTicket() {
        Ticket newTicket;
        newTicket.ticketID = tickets.size() + 1; // Simple ID assignment
        cout << "Enter passenger name: ";
        cin >> newTicket.passengerName;
        newTicket.isCancelled = false;

        tickets.push_back(newTicket);
        cout << "Ticket booked successfully! Ticket ID: " << newTicket.ticketID << endl;
    }

    void cancelTicket() {
        int ticketID;
        cout << "Enter Ticket ID to cancel: ";
        cin >> ticketID;

        if (ticketID <= 0 || ticketID > tickets.size()) {
            cout << "Invalid Ticket ID!" << endl;
            return;
        }

        Ticket &ticket = tickets[ticketID - 1]; // Array index adjustment
        if (ticket.isCancelled) {
            cout << "Ticket ID " << ticketID << " is already cancelled." << endl;
        } else {
            ticket.isCancelled = true;
            cout << "Ticket ID " << ticketID << " has been cancelled." << endl;
        }
    }

    void displayTickets() {
        if (tickets.empty()) {
            cout << "No tickets booked." << endl;
            return;
        }

        cout << "Booked Tickets:\n";
        for (const auto &ticket : tickets) {
            cout << "Ticket ID: " << ticket.ticketID 
                 << ", Passenger Name: " << ticket.passengerName
                 << ", Status: " << (ticket.isCancelled ? "Cancelled" : "Active") << endl;
        }
    }
};

int main() {
    TicketManager manager;
    int choice;

    do {
        cout << "\n1. Book Ticket\n2. Cancel Ticket\n3. Display Tickets\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.bookTicket();
                break;
            case 2:
                manager.cancelTicket();
                break;
            case 3:
                manager.displayTickets();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

