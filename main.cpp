#include <iostream>
#include "User.h"
#include "FinanceManager.h"

using namespace std;

int main()
{
    User user;
    FinanceManager financeManager;
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "    SMART EXPENSE TRACKER\n";
        cout << "=================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                user.registerUser();
                break;

            case 2:
                if(user.login())
                {
                    cout << "\nWelcome to Smart Expense Tracker!\n";
                }
                break;

            case 3:
                cout << "\nThank you for using Smart Expense Tracker!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 3);

    return 0;
}
