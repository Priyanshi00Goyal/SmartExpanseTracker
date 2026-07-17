#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include <map>
#include <algorithm>

#include "Income.h"
#include "Expense.h"

#include <fstream>
#include <sstream>

using namespace std;

class FinanceManager
{
private:
    vector<Income> incomes;
    vector<Expense> expenses; 
    double monthlyBudget = 0;
    int nextExpenseId = 1;

public:
    void showDashboardMenu();
    int getDashboardChoice();
    void handleDashboardChoice(int choice);
    void dashboard();

    void addIncome();
    void viewIncome();

    void addExpense();
    void viewExpense();

    void monthlyReport();

    void setBudget();
    void checkBudget();

    void searchExpense();
    void editExpense();
    void deleteExpense();
    void expenseStatistics();

    void searchByTitle();
    void searchByCategory();
    void searchByDate();
    void searchByAmount();
    void displayExpense(const Expense &expense);
    void displayExpenseHeader();

    void saveExpenses();
    void loadExpenses();
    void saveIncome();
    void loadIncome();
    void categoryReport();
    void exportCSV();
    void sortExpenses();

    void backupData();
    void restoreData();
    void copyFile(const string &source, const string &destination);

    void addHistory(string action, string title, double amount);
    void viewHistory();
};

#endif
