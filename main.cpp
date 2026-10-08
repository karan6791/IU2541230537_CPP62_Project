#include <iostream>
#include "HelpDesk.h"

using namespace std;

int main() {

    HelpDesk helpDesk;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "        IT HELP DESK TICKETING SYSTEM\n";
        cout << "========================================\n";
        cout << "1.  Add User\n";
        cout << "2.  Add Ticket\n";
        cout << "3.  Add Technician\n";
        cout << "4.  Add Resolution\n";
        cout << "5.  Display Users\n";
        cout << "6.  Display Tickets\n";
        cout << "7.  Display Technicians\n";
        cout << "8.  Display Resolutions\n";
        cout << "9.  Search Ticket\n";
        cout << "10. Update Ticket\n";
        cout << "11. Delete Ticket\n";
        cout << "12. Process Ticket\n";
        cout << "13. Generate Report\n";
        cout << "14. Save Data\n";
        cout << "0.  Exit\n";
        cout << "========================================\n";
     cout << "Enter your choice: ";

        if (!(cin >> choice)) {
    cout << "\nInvalid input! Please enter a number from 0 to 14.\n";
    
    cin.clear();
    cin.ignore(10000, '\n');

    continue;
}

        switch (choice) {

        case 1:
            helpDesk.addUser();
            break;

        case 2:
            helpDesk.addTicket();
            break;

        case 3:
            helpDesk.addTechnician();
            break;

        case 4:
            helpDesk.addResolution();
            break;

        case 5:
            helpDesk.displayUsers();
            break;

        case 6:
            helpDesk.displayTickets();
            break;

        case 7:
            helpDesk.displayTechnicians();
            break;

        case 8:
            helpDesk.displayResolutions();
            break;

        case 9:
            helpDesk.searchTicket();
            break;

        case 10:
            helpDesk.updateTicket();
            break;

        case 11:
            helpDesk.deleteTicket();
            break;

        case 12:
            helpDesk.processTicket();
            break;

        case 13:
            helpDesk.generateReport();
            break;

        case 14:
            helpDesk.saveData();
            break;

        case 0:
            cout << "\nExiting program...\n";
            cout << "Thank you for using IT Help Desk Ticketing System.\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}