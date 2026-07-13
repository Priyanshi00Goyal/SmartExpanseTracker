#include <iostream>
#include "FinanceManager.h"

using namespace std;

void FinanceManager::dashboard()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "         USER DASHBOARD\n";
        cout << "=====================================\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View Income\n";
        cout << "4. View Expenses\n";
        cout << "5. Monthly Report\n";
        cout << "6. Logout\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\n[Add Income - Coming Soon]\n";
                break;

            case 2:
                cout << "\n[Add Expense - Coming Soon]\n";
                break;

            case 3:
                cout << "\n[View Income - Coming Soon]\n";
                break;

            case 4:
                cout << "\n[View Expenses - Coming Soon]\n";
                break;

            case 5:
                cout << "\n[Monthly Report - Coming Soon]\n";
                break;

            case 6:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while(choice != 6);
}
