#include "HelpDesk.h"
#include "FileManager.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

// Constructor
HelpDesk::HelpDesk()
    : userCount(0),
      ticketCount(0),
      technicianCount(0),
      resolutionCount(0),
      userCapacity(10),
      ticketCapacity(10),
      technicianCapacity(10),
      resolutionCapacity(10) {

    users = new User[userCapacity];
    tickets = new Ticket[ticketCapacity];
    technicians = new Technician[technicianCapacity];
    resolutions = new Resolution[resolutionCapacity];

    // Load saved data when program starts
    loadData();
}

// Destructor
HelpDesk::~HelpDesk() {
    // Save current data before program closes
    saveData();

    delete[] users;
    delete[] tickets;
    delete[] technicians;
    delete[] resolutions;
}

// Add User
void HelpDesk::addUser() {
    if (userCount >= userCapacity) {
        cout << "User storage is full.\n";
        return;
    }

    int id;
    string name, email, phone;

    try {
        cout << "\nEnter User ID: ";

        if (!(cin >> id)) {
            throw invalid_argument("User ID must be a number.");
        }

        if (id <= 0) {
            throw invalid_argument("User ID must be greater than 0.");
        }

        cout << "Enter Name: ";
        getline(cin >> ws, name);

        if (name.empty()) {
            throw invalid_argument("Name cannot be empty.");
        }

        cout << "Enter Email: ";
        getline(cin, email);

        if (email.empty() || email.find('@') == string::npos) {
            throw invalid_argument("Please enter a valid email address.");
        }

        cout << "Enter Phone: ";
        getline(cin, phone);

        if (phone.empty()) {
            throw invalid_argument("Phone number cannot be empty.");
        }

        users[userCount] = User(id, name, email, phone);
        userCount++;

        cout << "User added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Add Ticket
void HelpDesk::addTicket() {
    if (ticketCount >= ticketCapacity) {
        cout << "Ticket storage is full.\n";
        return;
    }

    int ticketId, userId, technicianId;
    string issue, priority, status;

    try {
        cout << "\nEnter Ticket ID: ";

        if (!(cin >> ticketId)) {
            throw invalid_argument("Ticket ID must be a number.");
        }

        if (ticketId <= 0) {
            throw invalid_argument("Ticket ID must be greater than 0.");
        }

        cout << "Enter User ID: ";

        if (!(cin >> userId)) {
            throw invalid_argument("User ID must be a number.");
        }

        if (userId <= 0) {
            throw invalid_argument("User ID must be greater than 0.");
        }

        cout << "Enter Issue: ";
        getline(cin >> ws, issue);

        if (issue.empty()) {
            throw invalid_argument("Issue cannot be empty.");
        }

        cout << "Enter Priority: ";
        getline(cin, priority);

        if (priority.empty()) {
            throw invalid_argument("Priority cannot be empty.");
        }

        cout << "Enter Status: ";
        getline(cin, status);

        if (status.empty()) {
            throw invalid_argument("Status cannot be empty.");
        }

        cout << "Enter Technician ID: ";

        if (!(cin >> technicianId)) {
            throw invalid_argument("Technician ID must be a number.");
        }

        if (technicianId <= 0) {
            throw invalid_argument("Technician ID must be greater than 0.");
        }

        tickets[ticketCount] =
            Ticket(ticketId, userId, issue, priority, status, technicianId);

        ticketCount++;

        cout << "Ticket added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
// Add Technician
void HelpDesk::addTechnician() {
    if (technicianCount >= technicianCapacity) {
        cout << "Technician storage is full.\n";
        return;
    }

    int id;
    string name, specialization;

    try {
        cout << "\nEnter Technician ID: ";

        if (!(cin >> id)) {
            throw invalid_argument("Technician ID must be a number.");
        }

        if (id <= 0) {
            throw invalid_argument("Technician ID must be greater than 0.");
        }

        cout << "Enter Name: ";
        getline(cin >> ws, name);

        if (name.empty()) {
            throw invalid_argument("Name cannot be empty.");
        }

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        if (specialization.empty()) {
            throw invalid_argument("Specialization cannot be empty.");
        }

        technicians[technicianCount] =
            Technician(id, name, specialization);

        technicianCount++;

        cout << "Technician added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
// Add Resolution
void HelpDesk::addResolution() {
    if (resolutionCount >= resolutionCapacity) {
        cout << "Resolution storage is full.\n";
        return;
    }

    int resolutionId, ticketId, technicianId;
    string solution, date;

    try {
        cout << "\nEnter Resolution ID: ";

        if (!(cin >> resolutionId)) {
            throw invalid_argument("Resolution ID must be a number.");
        }

        if (resolutionId <= 0) {
            throw invalid_argument("Resolution ID must be greater than 0.");
        }

        cout << "Enter Ticket ID: ";

        if (!(cin >> ticketId)) {
            throw invalid_argument("Ticket ID must be a number.");
        }

        if (ticketId <= 0) {
            throw invalid_argument("Ticket ID must be greater than 0.");
        }

        cout << "Enter Technician ID: ";

        if (!(cin >> technicianId)) {
            throw invalid_argument("Technician ID must be a number.");
        }

        if (technicianId <= 0) {
            throw invalid_argument("Technician ID must be greater than 0.");
        }

        cout << "Enter Solution: ";
        getline(cin >> ws, solution);

        if (solution.empty()) {
            throw invalid_argument("Solution cannot be empty.");
        }

        cout << "Enter Resolution Date: ";
        getline(cin, date);

        if (date.empty()) {
            throw invalid_argument("Resolution date cannot be empty.");
        }

        resolutions[resolutionCount] =
            Resolution(resolutionId, ticketId, technicianId, solution, date);

        resolutionCount++;

        cout << "Resolution added successfully.\n";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
// Display Users
void HelpDesk::displayUsers() const {
    cout << "\n===== USER RECORDS =====\n";

    if (userCount == 0) {
        cout << "No users found.\n";
        return;
    }

    for (int i = 0; i < userCount; i++) {
        users[i].display();
    }
}

// Display Tickets
void HelpDesk::displayTickets() const {
    cout << "\n===== TICKET RECORDS =====\n";

    if (ticketCount == 0) {
        cout << "No tickets found.\n";
        return;
    }

    for (int i = 0; i < ticketCount; i++) {
        tickets[i].display();
    }
}

// Display Technicians
void HelpDesk::displayTechnicians() const {
    cout << "\n===== TECHNICIAN RECORDS =====\n";

    if (technicianCount == 0) {
        cout << "No technicians found.\n";
        return;
    }

    for (int i = 0; i < technicianCount; i++) {
        technicians[i].display();
    }
}

// Display Resolutions
void HelpDesk::displayResolutions() const {
    cout << "\n===== RESOLUTION RECORDS =====\n";

    if (resolutionCount == 0) {
        cout << "No resolutions found.\n";
        return;
    }

    for (int i = 0; i < resolutionCount; i++) {
        resolutions[i].display();
    }
}

// Search Ticket
void HelpDesk::searchTicket() const {
    int id;

    cout << "\nEnter Ticket ID to search: ";
    cin >> id;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketId() == id) {
            cout << "\nTicket found!\n";
            tickets[i].display();
            return;
        }
    }

    cout << "Ticket not found.\n";
}

// Update Ticket
void HelpDesk::updateTicket() {
    int id;

    cout << "\nEnter Ticket ID to update: ";
    cin >> id;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketId() == id) {
            tickets[i].updateTicket();
            cout << "Ticket updated successfully.\n";
            return;
        }
    }

    cout << "Ticket not found.\n";
}

// Delete Ticket
void HelpDesk::deleteTicket() {
    int id;

    cout << "\nEnter Ticket ID to delete: ";
    cin >> id;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketId() == id) {

            for (int j = i; j < ticketCount - 1; j++) {
                tickets[j] = tickets[j + 1];
            }

            ticketCount--;

            cout << "Ticket deleted successfully.\n";
            return;
        }
    }

    cout << "Ticket not found.\n";
}

// Main Ticket Processing
void HelpDesk::processTicket() {
    int ticketId;
    int technicianId;

    cout << "\n===== PROCESS TICKET =====\n";

    cout << "Enter Ticket ID: ";
    cin >> ticketId;

    int ticketIndex = -1;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketId() == ticketId) {
            ticketIndex = i;
            break;
        }
    }

    if (ticketIndex == -1) {
        cout << "Ticket not found.\n";
        return;
    }

    cout << "Enter Technician ID: ";
    cin >> technicianId;

    bool technicianFound = false;

    for (int i = 0; i < technicianCount; i++) {
        if (technicians[i].getTechnicianId() == technicianId) {
            technicianFound = true;

            tickets[ticketIndex].assignTechnician(technicianId);

            cout << "Ticket assigned to Technician ID "
                 << technicianId << ".\n";

            technicians[i].handleTicket();

            cout << "Ticket is now being processed.\n";
            break;
        }
    }

    if (!technicianFound) {
        cout << "Technician not found.\n";
    }
}

// Generate Report
void HelpDesk::generateReport() const {
    cout << "\n========== HELP DESK REPORT ==========\n";

    cout << "Total Users        : " << userCount << endl;
    cout << "Total Tickets      : " << ticketCount << endl;
    cout << "Total Technicians  : " << technicianCount << endl;
    cout << "Total Resolutions  : " << resolutionCount << endl;

    cout << "======================================\n";
}

// Save Data
void HelpDesk::saveData() const {
    FileManager::saveUsers(users, userCount);
    FileManager::saveTickets(tickets, ticketCount);
    FileManager::saveTechnicians(technicians, technicianCount);
    FileManager::saveResolutions(resolutions, resolutionCount);

    cout << "\nAll data saved successfully.\n";
}

// Load Data
void HelpDesk::loadData() {
    userCount = FileManager::loadUsers(users);
    ticketCount = FileManager::loadTickets(tickets);
    technicianCount = FileManager::loadTechnicians(technicians);
    resolutionCount = FileManager::loadResolutions(resolutions);

    if (userCount > 0 ||
        ticketCount > 0 ||
        technicianCount > 0 ||
        resolutionCount > 0) {

        cout << "\nSaved data loaded successfully.\n";
    }
}