#include "Technician.h"
#include <iostream>

using namespace std;

// Default constructor
Technician::Technician()
    : technicianId(0), name(""), specialization("") {
}

// Parameterized constructor
Technician::Technician(int id, string n, string spec)
    : technicianId(id), name(n), specialization(spec) {
}

// Destructor
Technician::~Technician() {
}

// Display technician information
void Technician::display() const {
    cout << "\n--- Technician Details ---\n";
    cout << "Technician ID : " << technicianId << endl;
    cout << "Name          : " << name << endl;
    cout << "Specialization: " << specialization << endl;
}

// Handle ticket
void Technician::handleTicket() const {
    cout << name << " is handling the ticket." << endl;
}

// Getters
int Technician::getTechnicianId() const {
    return technicianId;
}

string Technician::getName() const {
    return name;
}

string Technician::getSpecialization() const {
    return specialization;
}