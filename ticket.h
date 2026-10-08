#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

class Ticket {
private:
    int ticketId;
    int userId;
    string issue;
    string priority;
    string status;
    int technicianId;

public:
    // Constructors
    Ticket();
    Ticket(int tId, int uId, string i, string p, string s, int techId);

    // Destructor
    ~Ticket();

    // Member functions
    void display() const;
    void updateTicket();
    void assignTechnician(int techId);

    // Getters
    int getTicketId() const;
    int getUserId() const;
    string getIssue() const;
    string getPriority() const;
    string getStatus() const;
    int getTechnicianId() const;
};

#endif