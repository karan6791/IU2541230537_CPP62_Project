#include "Resolution.h"
#include <iostream>

using namespace std;

// Default constructor
Resolution::Resolution()
    : resolutionId(0), ticketId(0), technicianId(0),
      solution(""), resolutionDate("") {
}

// Parameterized constructor
Resolution::Resolution(int rId, int tId, int techId, string sol, string date)
    : resolutionId(rId), ticketId(tId), technicianId(techId),
      solution(sol), resolutionDate(date) {
}

// Destructor
Resolution::~Resolution() {
}

// Display resolution information
void Resolution::display() const {
    cout << "\n--- Resolution Details ---\n";
    cout << "Resolution ID  : " << resolutionId << endl;
    cout << "Ticket ID      : " << ticketId << endl;
    cout << "Technician ID  : " << technicianId << endl;
    cout << "Solution       : " << solution << endl;
    cout << "Resolution Date: " << resolutionDate << endl;
}

// Add resolution
void Resolution::addResolution() {
    cout << "Enter solution: ";
    getline(cin >> ws, solution);

    cout << "Enter resolution date: ";
    getline(cin, resolutionDate);
}

// Getters
int Resolution::getResolutionId() const {
    return resolutionId;
}

int Resolution::getTicketId() const {
    return ticketId;
}

int Resolution::getTechnicianId() const {
    return technicianId;
}

string Resolution::getSolution() const {
    return solution;
}

string Resolution::getResolutionDate() const {
    return resolutionDate;
}