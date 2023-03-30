#include<iostream>
#include "brass.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

Brass::Brass(const string & s,long an,double bal)
{
    fullName = s;
    accNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative Deposit Not Allowed; "
             <<  "deposit is cancelled.\n";
    else balance += amt;
}

void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal must be positive; "
             << "Withdrawal cancelled.\n";
    else if (amt > balance)
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal cancelled.\n";
    else balance -= amt;
} 

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcc() const
{
    cout << "Client : " << fullName << endl;
    cout << "Account Number : " << accNum << endl;
    cout << "Balance : $" << balance << endl;
}

Brass::~Brass() {}

//BrassPlus Methods;
BrassPlus::BrassPlus(const string & s,long an,double bal,
                            double ml,double r) : Brass(s,an,bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}

BrassPlus::BrassPlus(const Brass & ba,double ml,
                            double r) : Brass(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}    

void BrassPlus::ViewAcc() const
{
    Brass::ViewAcc();
    cout << "Maximum Loan : $" << maxLoan << endl;
    cout << "Owed to bank : $" << owesBank << endl;
    cout << "Loan Rate : " << 100*rate << "%\n";
}

void BrassPlus::Withdraw(double amt)
{
    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= (bal + maxLoan - owesBank))
    {
        double advance = amt - bal;
        owesBank += advance* (1 + rate);  // = Bank Advance + Finance charge
        cout << "Bank advane : $" << advance << endl;
        cout << "Finance charge : $" << advance * rate;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else 
        cout << "Credit limit exceeded. Transaction cancelled.\n";
}

