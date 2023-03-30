#include<iostream>
#include"BankAccount.h"
#include<string>

typedef BankAccount ba;

ba::BankAccount(const std::string & name,const std::string accNo,double cash)
{
    name_ = name;
    accNo_ = accNo;
    balance_ = cash;
}

void ba::display(void)
{
    std::cout << "Account Holder : " << name_ << std::endl
              << "Account number : " << accNo_ << std::endl
              << "Balance : " << balance_ << std::endl << std::endl;
}

void ba::deposit(double cash)
{
    if (cash <= 0 ) {
        std::cout << "Cash can't be negative;\n"
                  << "Transaction Aborted.\n";
    }
    else {
        balance_ += cash;
        std::cout << "Cash deposited successfully.\n\n";
    }
}

void ba::withdraw(double cash)
{
    if (cash <= 0)
    {
        std::cout << "Cash can't be negative;\n"
                  << "Transaction Aborted.\n";
    }
    else if (cash > balance_)
    {
        std::cout << "Can't withdraw more than balance;\n"
                  << "Transaction Aborted.\n";
    }
    else 
    {
        balance_ -= cash;
        std::cout << "Cash withdrawn successfully.\n\n";
    }
    
}