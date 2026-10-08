#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include "Ticket.h"
#include "Technician.h"
#include "Resolution.h"

class FileManager {
public:
    // Save data
    static void saveUsers(const User* users, int count);
    static void saveTickets(const Ticket* tickets, int count);
    static void saveTechnicians(const Technician* technicians, int count);
    static void saveResolutions(const Resolution* resolutions, int count);

    // Load data
    static int loadUsers(User* users);
    static int loadTickets(Ticket* tickets);
    static int loadTechnicians(Technician* technicians);
    static int loadResolutions(Resolution* resolutions);
};

#endif