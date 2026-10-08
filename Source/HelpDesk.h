#ifndef HELPDESK_H
#define HELPDESK_H

#include "User.h"
#include "Ticket.h"
#include "Technician.h"
#include "Resolution.h"

class HelpDesk {
private:
    User* users;
    Ticket* tickets;
    Technician* technicians;
    Resolution* resolutions;

    int userCount;
    int ticketCount;
    int technicianCount;
    int resolutionCount;

    int userCapacity;
    int ticketCapacity;
    int technicianCapacity;
    int resolutionCapacity;

public:
    // Constructor and destructor
    HelpDesk();
    ~HelpDesk();

    // Add records
    void addUser();
    void addTicket();
    void addTechnician();
    void addResolution();

    // Display records
    void displayUsers() const;
    void displayTickets() const;
    void displayTechnicians() const;
    void displayResolutions() const;

    // Search
    void searchTicket() const;

    // Update
    void updateTicket();

    // Delete
    void deleteTicket();

    // Main transaction
    void processTicket();

    // Report
    void generateReport() const;

    // Save and load
    void saveData() const;
    void loadData();
};

#endif