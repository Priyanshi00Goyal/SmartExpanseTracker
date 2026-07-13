#include <iostream>
#include <fstream>
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
                addIncome();
                break;

            case 2:
                addExpense();
                break;

            case 3:
                viewIncome();
                break;

            case 4:
                viewExpense();
                break;

            case 5:
                setBudget();
                break;

            case 6:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while(choice != 7);
}

void FinanceManager::addIncome()
{
    Income income;

    cout << "\n===== Add Income =====\n";

    cout << "Enter Source: ";
    cin >> income.source;

    cout << "Enter Amount: ";
    cin >> income.amount;

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> income.date;

    // Store in vector
    incomes.push_back(income);

    // Save to file
    ofstream file("data/income.txt", ios::app);

    file << income.source << " "
         << income.amount << " "
         << income.date << endl;

    file.close();

    cout << "\n✅ Income added successfully!\n";
}

void FinanceManager::viewIncome()
{
    ifstream file("data/income.txt");

    Income income;

    cout << "\n===== All Income =====\n\n";

    while(file >> income.source >> income.amount >> income.date)
    {
        cout << income.source << "    "
             << income.amount << "    "
             << income.date << endl;
    }

    file.close();
}

void FinanceManager::addExpense()
{
    Expense expense;

    cout << "\n===== Add Expense =====\n";

    cout << "Enter Title: ";
    cin >> expense.title;

    cout << "Enter Amount: ";
    cin >> expense.amount;

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> expense.date;

    cout << "Enter Category: ";
    cin >> expense.category;

    // Store in vector
    expenses.push_back(expense);

    // Save to file
    ofstream file("data/expense.txt", ios::app);

    file << expense.title << " "
         << expense.amount << " "
         << expense.date << " "
         << expense.category << endl;

    file.close();

    cout << "\n✅ Expense added successfully!\n";
}

void FinanceManager::viewExpense()
{
    ifstream file("data/expense.txt");

    Expense expense;

    cout << "\n===== All Expenses =====\n\n";

    while(file >> expense.title >> expense.amount >> expense.date >> expense.category)
    {
        cout << expense.title << " "
             << expense.amount << " "
             << expense.date << " "
             << expense.category << endl;
    }

    file.close();
}

void FinanceManager::monthlyReport()
{
    ifstream incomeFile("data/income.txt");
    ifstream expenseFile("data/expense.txt");

    Income income;
    Expense expense;

    double totalIncome = 0;
    double totalExpense = 0;

    while (incomeFile >> income.source >> income.amount >> income.date)
    {
        totalIncome += income.amount;
    }

    while (expenseFile >> expense.title >> expense.amount >> expense.date >> expense.category)
    {
        totalExpense += expense.amount;
    }

    incomeFile.close();
    expenseFile.close();

    cout << "\n=====================================\n";
    cout << "         MONTHLY REPORT\n";
    cout << "=====================================\n";

    cout << "Total Income  : ₹" << totalIncome << endl;
    cout << "Total Expense : ₹" << totalExpense << endl;

    cout << "-------------------------------------\n";

    cout << "Remaining     : ₹" << totalIncome - totalExpense << endl;

    if(totalIncome >= totalExpense)
    {
        cout << "\n🎉 Great! You saved money this month.\n";
    }
    else
    {
        cout << "\n⚠️ You spent more than you earned!\n";
    }
}

void FinanceManager::setBudget()
{
    cout << "\nEnter Monthly Budget: ₹";
    cin >> monthlyBudget;

    cout << "Budget set successfully!\n";
}

void FinanceManager::checkBudget()
{
    // We'll implement this later.
}
