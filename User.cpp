#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

void User::registerUser()
{
    cout << "\n===== User Registration =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("data/users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}
