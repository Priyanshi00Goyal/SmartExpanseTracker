#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include<vector>

class FinanceManager
{
private:
    vector<Income> incomes;

public:
    void dashboard();
    void addIncome();
};

class Income
{
public:
    string source;
    double amount;
    string date;
};

#endif
