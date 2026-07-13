#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>

#include "Income.h"
#include "Expense.h"

using namespace std;

class FinanceManager
{
private:
    vector<Income> incomes;
    vector<Expense> expenses; 
    double monthlyBudget = 0;

public:
    void dashboard();

    void addIncome();
    void viewIncome();

    void addExpense();
    void viewExpense();

    void monthlyReport();

    void setBudget();
    void checkBudget();
};

#endif
