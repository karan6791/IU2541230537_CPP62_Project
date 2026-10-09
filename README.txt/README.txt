============================================================
 IT HELP DESK / TICKETING SYSTEM
============================================================
Student Name    : Rajput Karansinh Anopsinh
Enrollment No.  : IU2541230537
Division        : 3CSE-E2
Project Code    : CPP62
Institute       : Indus Institute of Technology and Engineering
Program         : B.Tech Computer Science & Engineering


1. PROJECT DESCRIPTION
----------------------
A console-based IT Help Desk / Ticketing System written in C++.
It manages users, support tickets, technicians and ticket
resolutions. All records are stored in text files, so the data
is still available after the program is closed and reopened.


2. FEATURES
-----------
- Add users, tickets, technicians and resolutions
- Display all users, tickets, technicians and resolutions
- Search a ticket by Ticket ID
- Update a ticket (issue, priority, status)
- Delete a ticket by Ticket ID
- Process a ticket (assign a technician to a ticket)
- Generate a report (total users, tickets, technicians, resolutions)
- Save data to text files (also saved automatically on exit)
- Load saved data automatically when the program starts
- Input validation and exception handling


3. TECHNOLOGIES USED
--------------------
- Language      : C++
- IDE           : Visual Studio Code
- Compiler      : MinGW / g++
- Data storage  : Text files (.txt)
- Diagrams      : diagrams.net (draw.io)


4. PROJECT STRUCTURE
--------------------
Source/        C++ source and header files
Data/          Text files used for data storage
Diagrams/      Use Case, Class and Sequence diagrams
Executable/    Compiled program
Screenshots/   Program screenshots
README.txt     This file
ProjectReport.pdf   Final project report


5. REQUIREMENTS
---------------
- Windows operating system
- MinGW (g++) installed and added to PATH
- Visual Studio Code or any text editor / terminal


6. HOW TO COMPILE AND RUN
-------------------------
Open a terminal (Command Prompt or VS Code terminal) in the
project folder, then run:

    cd Source
    g++ *.cpp -o ../Executable/CPP62_Project.exe
    cd ../Executable
    CPP62_Project.exe

IMPORTANT: run the program from the Executable folder (or the
Source folder). The program reads and writes the files using
the path ../Data/, so the Data folder must be next to the
Executable and Source folders.


7. MENU OPTIONS
---------------
 1  Add User
 2  Add Ticket
 3  Add Technician
 4  Add Resolution
 5  Display Users
 6  Display Tickets
 7  Display Technicians
 8  Display Resolutions
 9  Search Ticket
10  Update Ticket
11  Delete Ticket
12  Process Ticket
13  Generate Report
14  Save Data
 0  Exit


8. DATA FILES (Data folder)
---------------------------
One record per line, fields separated by the | character.

users.txt         userId|name|email|phone
tickets.txt       ticketId|userId|issue|priority|status|technicianId
technicians.txt   technicianId|name|specialization
resolutions.txt   resolutionId|ticketId|technicianId|solution|date

Data is loaded when the program starts. It is saved when you
choose option 14 (Save Data) and also automatically when you
exit with option 0.


9. HOW TO CHECK DATA PERSISTENCE
--------------------------------
1. Run the program and add a user (option 1) and a ticket (option 2).
2. Choose option 14 (Save Data), then option 0 (Exit).
3. Run the program again.
4. Choose option 5 and option 6: the records you added are still there.


10. OOP CONCEPTS USED
---------------------
- Classes and objects : User, Ticket, Technician, Resolution,
                        HelpDesk, FileManager
- Encapsulation       : private/protected data members with getters
- Constructors        : default and parameterized constructors
- Destructors         : destructor in every class
- Dynamic memory      : arrays created with new[] and released
                        with delete[] in the HelpDesk class
- File handling       : FileManager saves and loads all records
- Exception handling  : input validation using try/catch
- Modular design      : separate .h and .cpp files for each class


11. KNOWN LIMITATIONS
---------------------
- Each record type can hold up to 10 records at a time.
- Search, update and delete are available for tickets only.



12. AUTHOR
----------
Rajput Karansinh Anopsinh
Enrollment No.: IU2541230537
Project Code  : CPP62
