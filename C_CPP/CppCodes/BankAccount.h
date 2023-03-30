#ifndef BANK_H_
#define BANK_H_
#include<string>
class BankAccount
{
private:
    std::string name_;
    std::string accNo_;
    double balance_;
public:
    BankAccount(const std::string & s,std::string accNo,double cash = 0.0);
    void display(void);
    void deposit(double cash);
    void withdraw(double cash);
};

#endif