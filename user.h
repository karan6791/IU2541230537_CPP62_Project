#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    int userId;
    string name;
    string email;
    string phone;

public:
    // Constructors
    User();
    User(int id, string n, string e, string p);

    // Destructor
    ~User();

    // Member functions
    void display() const;
    void updateDetails();

    // Getters
    int getUserId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;
};

#endif