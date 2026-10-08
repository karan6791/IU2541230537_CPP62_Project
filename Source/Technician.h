#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include <string>
using namespace std;

class Technician {
protected:
    int technicianId;
    string name;
    string specialization;

public:
    // Constructors
    Technician();
    Technician(int id, string n, string spec);

    // Destructor
    virtual ~Technician();

    // Member functions
    virtual void display() const;
    virtual void handleTicket() const;

    // Getters
    int getTechnicianId() const;
    string getName() const;
    string getSpecialization() const;
};

#endif