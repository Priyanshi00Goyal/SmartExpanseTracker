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

bool User::login()
{
    string inputUsername, inputPassword;
    string storedUsername, storedPassword;

    cout << "\n===== Login =====\n";

    cout << "Username: ";
    cin >> inputUsername;

    cout << "Password: ";
    cin >> inputPassword;

    ifstream file("data/users.txt");

    while (file >> storedUsername >> storedPassword)
    {
        if (inputUsername == storedUsername &&
            inputPassword == storedPassword)
        {
            file.close();

            cout << "\nLogin Successful!\n";

            return true;
        }
    }

    file.close();

    cout << "\nInvalid Username or Password!\n";

    return false;
}
