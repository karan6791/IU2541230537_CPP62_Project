#include "Ticket.h"
#include <iostream>

using namespace std;

// Default constructor
Ticket::Ticket()
    : ticketId(0), userId(0), issue(""), priority(""), status("Open"), technicianId(0) {
}

// Parameterized constructor
Ticket::Ticket(int tId, int uId, string i, string p, string s, int techId)
    : ticketId(tId), userId(uId), issue(i), priority(p), status(s), technicianId(techId) {
}

// Destructor
Ticket::~Ticket() {
}

// Display ticket information
void Ticket::display() const {
    cout << "\n--- Ticket Details ---\n";
    cout << "Ticket ID      : " << ticketId << endl;
    cout << "User ID        : " << userId << endl;
    cout << "Issue          : " << issue << endl;
    cout << "Priority       : " << priority << endl;
    cout << "Status         : " << status << endl;
    cout << "Technician ID  : " << technicianId << endl;
}

// Update ticket information
void Ticket::updateTicket() {
    cout << "Enter new issue: ";
    getline(cin >> ws, issue);

    cout << "Enter new priority: ";
    getline(cin, priority);

    cout << "Enter new status: ";
    getline(cin, status);
}

// Assign technician
void Ticket::assignTechnician(int techId) {
    technicianId = techId;
    status = "Assigned";
}

// Getters
int Ticket::getTicketId() const {
    return ticketId;
}

int Ticket::getUserId() const {
    return userId;
}

string Ticket::getIssue() const {
    return issue;
}

string Ticket::getPriority() const {
    return priority;
}

string Ticket::getStatus() const {
    return status;
}

int Ticket::getTechnicianId() const {
    return technicianId;
}