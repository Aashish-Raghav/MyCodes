#include<iostream>
#include  "Brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg",381299,4000.0);
    BrassPlus Hoggy("Horatio Hogg",38228,3000.0);
    Piggy.ViewAcc();
    cout << endl;
    Hoggy.ViewAcc();
    cout << endl;
    cout << "Deposting $1000 into the Hogg Accoutn:\n";
    Hoggy.Deposit(1000.0);
    cout << "New Balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200);
    cout << "Pigg account balance: $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcc();

    return 0;
}