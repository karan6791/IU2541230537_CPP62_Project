#ifndef RESOLUTION_H
#define RESOLUTION_H

#include <string>
using namespace std;

class Resolution {
private:
    int resolutionId;
    int ticketId;
    int technicianId;
    string solution;
    string resolutionDate;

public:
    // Constructors
    Resolution();
    Resolution(int rId, int tId, int techId, string sol, string date);

    // Destructor
    ~Resolution();

    // Member functions
    void display() const;
    void addResolution();

    // Getters
    int getResolutionId() const;
    int getTicketId() const;
    int getTechnicianId() const;
    string getSolution() const;
    string getResolutionDate() const;
};

#endif