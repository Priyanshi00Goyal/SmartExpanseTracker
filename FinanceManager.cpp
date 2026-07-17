#include <iostream>
#include <fstream>
#include <iomanip>
#include "FinanceManager.h"


using namespace std;

void FinanceManager::showDashboardMenu()
{
    cout << "\n=====================================\n";
    cout << "         USER DASHBOARD\n";
    cout << "=====================================\n";
    cout << "1. Add Income\n";
    cout << "2. Add Expense\n";
    cout << "3. View Income\n";
    cout << "4. View Expenses\n";
    cout << "5. Monthly Report\n";
    cout << "6. Set Budget\n";
    cout << "7. Search Expense\n";
    cout << "8. Edit Expense\n";
    cout << "9. Delete Expense\n";
    cout << "10. Expense Statistics\n";
    cout << "11. Category Report\n";
    cout << "12. Sort Expenses\n";
    cout << "13. Export Expenses (CSV)\n";
    cout << "14. Logout\n";
}

int FinanceManager::getDashboardChoice()
{
    int choice;

    cout << "\nEnter your choice: ";

    while(!(cin >> choice))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter a number: ";
    }

    return choice;
}

void FinanceManager::handleDashboardChoice(int choice)
{
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
            monthlyReport();
            break;

        case 6:
            setBudget();
            break;

        case 7:
            searchExpense();
            break;

        case 8:
            editExpense();
            break;

        case 9:
            deleteExpense();
            break;

        case 10:
            expenseStatistics();
            break;

        case 11:
            categoryReport();
            break;

        case 12:
            sortExpenses();
            break;

        case 13:
            exportCSV();
            break;

        case 14:
            cout << "\nLogging out...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
    }
}

void FinanceManager::dashboard()
{
    int choice;

    do
    {
        showDashboardMenu();

        choice = getDashboardChoice();

        handleDashboardChoice(choice);

    } while(choice != 14);
}

void FinanceManager::addIncome()
{
    Income income;

    cin.ignore();

    do
    {
        cout << "Enter Source: ";
        getline(cin, income.source);

        if(income.source.empty())
            cout << "Source cannot be empty!\n";

    } while(income.source.empty());

    cout << "Enter Amount: ";

    while(true)
    {
        if(!(cin >> income.amount))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid amount! Enter again: ";
        }
        else if(income.amount <= 0)
        {
            cout << "Amount must be greater than 0: ";
        }
        else
        {
            break;
        }
    }

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> income.date;

    incomes.push_back(income);

    saveIncome();

    cout << "\nIncome Added Successfully!\n";
}

void FinanceManager::viewIncome()
{
    if(incomes.empty())
    {
        cout << "\nNo Income Found!\n";
        return;
    }

    cout << "\n==========================================================\n";

    cout << left
         << setw(20) << "SOURCE"
         << setw(15) << "AMOUNT"
         << setw(15) << "DATE"
         << endl;

    cout << "==========================================================\n";

    for(const Income &income : incomes)
    {
        cout << left
             << setw(20) << income.source
             << setw(15) << income.amount
             << setw(15) << income.date
             << endl;
    }

    cout << "==========================================================\n";
}

void FinanceManager::addExpense()
{
    Expense expense;

    expense.id = nextExpenseId++;

    cin.ignore();

    do
    {
        cout << "Enter Title: ";
        getline(cin, expense.title);

        if(expense.title.empty())
            cout << "Title cannot be empty!\n";

    } while(expense.title.empty());

    cout << "Enter Amount: ";

    while(true)
    {
        if(!(cin >> expense.amount))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid amount! Enter again: ";
        }
        else if(expense.amount <= 0)
        {
            cout << "Amount must be greater than 0: ";
        }
        else
        {
            break;
        }
    }

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> expense.date;

    cin.ignore();

    do
    {
        cout << "Enter Category: ";
        getline(cin, expense.category);

        if(expense.category.empty())
            cout << "Category cannot be empty!\n";

    } while(expense.category.empty());

    expenses.push_back(expense);

    saveExpenses();

    checkBudget();

    cout << "\nExpense Added Successfully!\n";
}

void FinanceManager::viewExpense()
{
    if(expenses.empty())
    {
        cout << "\nNo Expenses Found!\n";
        return;
    }

    cout << "\n==========================================================================\n";

    cout << left
         << setw(6)  << "ID"
         << setw(20) << "TITLE"
         << setw(12) << "AMOUNT"
         << setw(20) << "CATEGORY"
         << setw(15) << "DATE"
         << endl;

    cout << "==========================================================================\n";

    for(const Expense &expense : expenses)
    {
        cout << left
             << setw(6)  << expense.id
             << setw(20) << expense.title
             << setw(12) << expense.amount
             << setw(20) << expense.category
             << setw(15) << expense.date
             << endl;
    }

    cout << "==========================================================================\n";
}

void FinanceManager::monthlyReport()
{
    double totalIncome = 0;
    double totalExpense = 0;

    // Total Income
    for (const Income &income : incomes)
    {
        totalIncome += income.amount;
    }

    // Total Expense
    for (const Expense &expense : expenses)
    {
        totalExpense += expense.amount;
    }

    double savings = totalIncome - totalExpense;
    double remainingBudget = monthlyBudget - totalExpense;
    map<string,double> categoryTotal;

    for(const Expense &expense : expenses)
    {
        categoryTotal[expense.category] += expense.amount;
    }

    string highestCategory = "";
    double highestAmount = 0;

    for(const auto &item : categoryTotal)
    {
        if(item.second > highestAmount)
        {
            highestAmount = item.second;
            highestCategory = item.first;
        }
    }
    Expense highestExpense;

    if(!expenses.empty())
    {
        highestExpense = expenses[0];

        for(const Expense &expense : expenses)
        {
            if(expense.amount > highestExpense.amount)
            {
                highestExpense = expense;
            }
        }
    }

    cout << "\n=========================================================\n";
    cout << "             MONTHLY FINANCIAL REPORT\n";
    cout << "=========================================================\n\n";

    cout << "Total Income      : ₹" << totalIncome << endl;
    cout << "Total Expense     : ₹" << totalExpense << endl;
    cout << "Savings           : ₹" << savings << endl;

    cout << "\nMonthly Budget    : ₹" << monthlyBudget << endl;
    cout << "Budget Used       : ₹" << totalExpense << endl;
    cout << "Remaining Budget  : ₹" << remainingBudget << endl;

    cout << "\nBudget Status     : ";

    if(totalExpense <= monthlyBudget)
        cout << "Within Budget ✅\n";
    else
        cout << "Budget Exceeded ❌\n";
    if(!expenses.empty())
    {
        cout << "\nHighest Expense   : "
             << highestExpense.title
             << " (₹" << highestExpense.amount << ")\n";
        cout << "Highest Category  : "
         << highestCategory
         << " (₹" << highestAmount << ")\n";
    }
}

void FinanceManager::setBudget()
{
    cout << "\nEnter Monthly Budget: ₹";
    while (true)
    {
        if (!(cin >> monthlyBudget))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter again: ";
        }
        else if (monthlyBudget <= 0)
        {
            cout << "Budget must be greater than zero: ";
        }
        else
        {
            break;
        }
    }

    cout << "Budget set successfully!\n";
}

void FinanceManager::checkBudget()
{
    double totalExpense = 0;

    for (Expense expense : expenses)
    {
        totalExpense += expense.amount;
    }

    cout << "\nCurrent Budget : ₹" << monthlyBudget << endl;
    cout << "Total Expense  : ₹" << totalExpense << endl;

    if (totalExpense > monthlyBudget)
    {
        cout << "\n⚠️ WARNING! Budget Exceeded by ₹"
             << totalExpense - monthlyBudget << endl;
    }
    else
    {
        cout << "\nBudget Remaining : ₹"
             << monthlyBudget - totalExpense << endl;
    }
}

void FinanceManager::searchExpense()
{
    int id;

    cout << "\nEnter Expense ID: ";
    cin >> id;

    bool found = false;

    for (Expense expense : expenses)
    {
        if (expense.id == id)
        {
            cout << "\nExpense Found!\n";
            cout << "ID       : " << expense.id <<endl;
            cout << "Title    : " << expense.title << endl;
            cout << "Amount   : ₹" << expense.amount << endl;
            cout << "Category : " << expense.category << endl;
            cout << "Date     : " << expense.date << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nExpense not found!\n";
    }
}

void FinanceManager::editExpense()
{
    int id;

    cout << "\nEnter Expense ID to Edit: ";
    cin >> id;

    bool found = false;

    for (Expense &expense : expenses)
    {
        if (expense.id == id)
        {
            cout << "\nExpense Found!\n";

            cout << "Current Amount: ₹" << expense.amount << endl;

            cout << "Enter New Amount: ";
            cin >> expense.amount;
            saveExpenses();
            cout << "\nExpense Updated Successfully!\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nExpense not found!\n";
    }
}

void FinanceManager::saveIncome()
{
    ofstream file("data/income.txt");

    if(!file)
    {
        cout << "Unable to save income!\n";
        return;
    }

    for(const Income &income : incomes)
    {
        file << income.source << ","
             << income.amount << ","
             << income.date << endl;
    }

    file.close();
}

void FinanceManager::loadIncome()
{
    ifstream file("data/income.txt");

    if(!file)
        return;

    incomes.clear();

    Income income;
    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        getline(ss, income.source, ',');

        string amount;
        getline(ss, amount, ',');
        income.amount = stod(amount);

        getline(ss, income.date);

        incomes.push_back(income);
    }

    file.close();
}

void FinanceManager::deleteExpense()
{
    int id;

    cout << "\nEnter Expense ID: ";
    cin >> id;

    bool found = false;

    for (auto it = expenses.begin(); it != expenses.end(); it++)
    {
        if (it->id == id)
        {
            expenses.erase(it);
            checkBudget();
            saveExpenses();

            cout << "\nExpense Deleted Successfully!\n";

            found = true;

            break;
        }
    }

    if (!found)
    {
        cout << "\nExpense Not Found!\n";
    }
}

void FinanceManager::expenseStatistics()
{
    if(expenses.empty())
    {
        cout << "\nNo Expenses Found!\n";
        return;
    }

    double total = 0;

    Expense highest = expenses[0];
    Expense lowest = expenses[0];

    for(const Expense &expense : expenses)
    {
        total += expense.amount;

        if(expense.amount > highest.amount)
            highest = expense;

        if(expense.amount < lowest.amount)
            lowest = expense;
    }

    double average = total / expenses.size();

    cout << "\n====================================\n";
    cout << "      EXPENSE STATISTICS\n";
    cout << "====================================\n";

    cout << "Total Expense : ₹" << total << endl;

    cout << "Highest       : "
         << highest.title
         << " (₹" << highest.amount << ")\n";

    cout << "Lowest        : "
         << lowest.title
         << " (₹" << lowest.amount << ")\n";

    cout << "Average       : ₹"
         << average << endl;

    cout << "====================================\n";
}

void FinanceManager::saveExpenses()
{
    ofstream file("data/expenses.txt");

    for (const Expense &expense : expenses)
    {
        file
            << expense.id << ","
            << expense.title << ","
            << expense.amount << ","
            << expense.category << ","
            << expense.date << endl;
    }

    file.close();
}

void FinanceManager::loadExpenses()
{
    ifstream file("data/expenses.txt");

    if (!file)
        return;

    expenses.clear();

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        Expense expense;

        string idStr;
        string amountStr;

        getline(ss, idStr, ',');
        expense.id = stoi(idStr);

        getline(ss, expense.title, ',');

        getline(ss, amountStr, ',');
        expense.amount = stod(amountStr);

        getline(ss, expense.category, ',');

        getline(ss, expense.date);

        expenses.push_back(expense);

        if(expense.id >= nextExpenseId)
            nextExpenseId = expense.id + 1;
    }

    file.close();
}

void FinanceManager::categoryReport()
{
    if(expenses.empty())
    {
        cout << "\nNo Expenses Found!\n";
        return;
    }

    map<string, double> report;

    for(const Expense &expense : expenses)
    {
        report[expense.category] += expense.amount;
    }

    cout << "\n====================================\n";
    cout << "       CATEGORY REPORT\n";
    cout << "====================================\n";

    for(const auto &item : report)
    {
        cout << item.first << " : ₹" << item.second << endl;
    }

    cout << "====================================\n";
}

void FinanceManager::sortExpenses()
{
    if(expenses.empty())
    {
        cout << "\nNo Expenses Found!\n";
        return;
    }

    int choice;

    cout << "\n========== SORT EXPENSES ==========\n";
    cout << "1. Sort by Amount (Low → High)\n";
    cout << "2. Sort by Amount (High → Low)\n";
    cout << "3. Sort by Title (A → Z)\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:

            sort(expenses.begin(), expenses.end(),
            [](Expense a, Expense b)
            {
                return a.amount < b.amount;
            });

            break;

        case 2:

            sort(expenses.begin(), expenses.end(),
            [](Expense a, Expense b)
            {
                return a.amount > b.amount;
            });

            break;

        case 3:

            sort(expenses.begin(), expenses.end(),
            [](Expense a, Expense b)
            {
                return a.title < b.title;
            });

            break;

        default:

            cout << "\nInvalid Choice!\n";
            return;
    }

    cout << "\nExpenses Sorted Successfully!\n";

    viewExpense();
}

void FinanceManager::exportCSV()
{
    if(expenses.empty())
    {
        cout << "\nNo Expenses Found!\n";
        return;
    }

    ofstream file("data/expenses_report.csv");

    if(!file)
    {
        cout << "\nUnable to create report!\n";
        return;
    }

    file << "ID,Title,Amount,Category,Date\n";

    for(const Expense &expense : expenses)
    {
        file << expense.id << ","
             << expense.title << ","
             << expense.amount << ","
             << expense.category << ","
             << expense.date << "\n";
    }

    file.close();

    cout << "\n✅ Report exported successfully!\n";
    cout << "Location: data/expenses_report.csv\n";
}
