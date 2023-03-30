#include<iostream>
#include<string>
#include"BankAccount.h"
typedef BankAccount ba;

int main()
{
    using namespace std;
    ba arAcc = BankAccount("Aashish Raghav","096500170004536",500);
    arAcc.display();
    arAcc.deposit(500);
    arAcc.display();
    arAcc.withdraw(300);
    arAcc.display();
    arAcc.withdraw(2000);
    arAcc.display();
    arAcc.deposit(-55);


    ba ctAcc = BankAccount("Chetan Teotia","096500170003456");
    ctAcc.display();
    ctAcc.withdraw(100);
}