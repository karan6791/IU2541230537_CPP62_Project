#include "User.h"
#include <iostream>

using namespace std;

// Default constructor
User::User()
    : userId(0), name(""), email(""), phone("") {
}

// Parameterized constructor
User::User(int id, string n, string e, string p)
    : userId(id), name(n), email(e), phone(p) {
}

// Destructor
User::~User() {
}

// Display user information
void User::display() const {
    cout << "\n--- User Details ---\n";
    cout << "User ID : " << userId << endl;
    cout << "Name    : " << name << endl;
    cout << "Email   : " << email << endl;
    cout << "Phone   : " << phone << endl;
}

// Update user information
void User::updateDetails() {
    cout << "Enter new name: ";
    getline(cin >> ws, name);

    cout << "Enter new email: ";
    getline(cin, email);

    cout << "Enter new phone: ";
    getline(cin, phone);
}

// Getters
int User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

string User::getPhone() const {
    return phone;
}