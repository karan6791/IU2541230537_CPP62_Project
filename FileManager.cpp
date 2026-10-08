#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Save Users
void FileManager::saveUsers(const User* users, int count) {
    ofstream file("../Data/users.txt");

    if (!file) {
        cout << "Error opening Data/users.txt\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << users[i].getUserId() << "|"
             << users[i].getName() << "|"
             << users[i].getEmail() << "|"
             << users[i].getPhone() << "\n";
    }

    file.close();
}

// Save Tickets
void FileManager::saveTickets(const Ticket* tickets, int count) {
    ofstream file("../Data/tickets.txt");

    if (!file) {
        cout << "Error opening Data/tickets.txt\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << tickets[i].getTicketId() << "|"
             << tickets[i].getUserId() << "|"
             << tickets[i].getIssue() << "|"
             << tickets[i].getPriority() << "|"
             << tickets[i].getStatus() << "|"
             << tickets[i].getTechnicianId() << "\n";
    }

    file.close();
}

// Save Technicians
void FileManager::saveTechnicians(
    const Technician* technicians, int count) {

    ofstream file("../Data/technicians.txt");

    if (!file) {
        cout << "Error opening Data/technicians.txt\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << technicians[i].getTechnicianId() << "|"
             << technicians[i].getName() << "|"
             << technicians[i].getSpecialization() << "\n";
    }

    file.close();
}

// Save Resolutions
void FileManager::saveResolutions(
    const Resolution* resolutions, int count) {

    ofstream file("../Data/resolutions.txt");

    if (!file) {
        cout << "Error opening Data/resolutions.txt\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << resolutions[i].getResolutionId() << "|"
             << resolutions[i].getTicketId() << "|"
             << resolutions[i].getTechnicianId() << "|"
             << resolutions[i].getSolution() << "|"
             << resolutions[i].getResolutionDate() << "\n";
    }

    file.close();
}

// Load Users
int FileManager::loadUsers(User* users) {
   ifstream file("../Data/users.txt");

    if (!file) {
        return 0;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string id, name, email, phone;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, phone, '|');

        if (!id.empty()) {
            users[count] = User(
                stoi(id),
                name,
                email,
                phone
            );

            count++;
        }
    }

    file.close();

    return count;
}

// Load Tickets
int FileManager::loadTickets(Ticket* tickets) {

    ifstream file("../Data/tickets.txt");

    if (!file) {
        return 0;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string ticketId;
        string userId;
        string issue;
        string priority;
        string status;
        string technicianId;

        getline(ss, ticketId, '|');
        getline(ss, userId, '|');
        getline(ss, issue, '|');
        getline(ss, priority, '|');
        getline(ss, status, '|');
        getline(ss, technicianId, '|');

        if (!ticketId.empty()) {
            tickets[count] = Ticket(
                stoi(ticketId),
                stoi(userId),
                issue,
                priority,
                status,
                stoi(technicianId)
            );

            count++;
        }
    }

    file.close();

    return count;
}

// Load Technicians
int FileManager::loadTechnicians(Technician* technicians) {
    ifstream file("../Data/technicians.txt");

    if (!file) {
        return 0;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string id;
        string name;
        string specialization;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, specialization, '|');

        if (!id.empty()) {
            technicians[count] = Technician(
                stoi(id),
                name,
                specialization
            );

            count++;
        }
    }

    file.close();

    return count;
}

// Load Resolutions
int FileManager::loadResolutions(Resolution* resolutions) {
    ifstream file("../Data/resolutions.txt");

    if (!file) {
        return 0;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        stringstream ss(line);

        string resolutionId;
        string ticketId;
        string technicianId;
        string solution;
        string date;

        getline(ss, resolutionId, '|');
        getline(ss, ticketId, '|');
        getline(ss, technicianId, '|');
        getline(ss, solution, '|');
        getline(ss, date, '|');

        if (!resolutionId.empty()) {
            resolutions[count] = Resolution(
                stoi(resolutionId),
                stoi(ticketId),
                stoi(technicianId),
                solution,
                date
            );

            count++;
        }
    }

    file.close();

    return count;
}