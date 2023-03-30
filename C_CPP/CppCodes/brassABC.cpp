#include<iostream>
#include "brassABC.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

BrassABC::BrassABC(const string & s,long an,double bal)
{
    fullname = s;
    accNum = an;
    balance = bal;
}

void BrassABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative Deposit Not Allowed; "
             <<  "deposit is cancelled.\n";
    else balance += amt;
}

void BrassABC::Withdraw(double amt)
{
    balance -= amt;
}

//protected methods for formatting
BrassABC::Formatting BrassABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void BrassABC::Restore(Formatting & f) const
{
    cout.setf(f.flag,std::ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt) 
{
    if (amt < 0)
        cout << "Withdrawal must be positive; "
             << "Withdrawal cancelled.\n";
    else if (amt > Balance())
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal cancelled.\n";
    else BrassABC::Withdraw(amt);
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client : " << FullName() << endl;
    cout << "Account Number : " << AccNum() << endl;
    cout << "Balance : $" << Balance() << endl;
    Restore(f);
}


//BrassPlus Methods;
BrassPlus::BrassPlus(const string & s,long an,double bal,
                            double ml,double r) : BrassABC(s,an,bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}

BrassPlus::BrassPlus(const Brass & ba,double ml,
                            double r) : BrassABC(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}    

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number : " << AccNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum Loan : $" << maxLoan << endl;
    cout << "Owed to bank : $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate : " << 100*rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{   
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        BrassABC::Withdraw(amt);
    else if (amt <= (bal + maxLoan - owesBank))
    {
        double advance = amt - bal;
        owesBank += advance* (1 + rate);  // = Bank Advance + Finance charge
        cout << "Bank advane : $" << advance << endl;
        cout << "Finance charge : $" << advance * rate;
        Deposit(advance);
        BrassABC::Withdraw(amt);
    }
    else 
        cout << "Credit limit exceeded. Transaction cancelled.\n";
}

