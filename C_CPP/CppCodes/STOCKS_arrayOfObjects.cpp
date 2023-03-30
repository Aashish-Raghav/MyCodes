// class declaration file is in CLASSmethodDecl.cpp


#include<iostream>
#include "stock00.h"
const int STKS = 4;
int main() 
{
    Stock stocks[STKS] = 
    {
        Stock("NanoSmart",12,20.0),
        Stock("Boffo Objects",200,2.0),
        Stock("Monolithic Obelisks",130,3.25),
        Stock("Fleep Enterprise",60,6.5)
    };
    std::cout << "Stock Holdings:\n";
    int st;
    for (st = 0;st < STKS;st++)
        stocks[st].show();

// set the pointer to first element;
    const Stock *top = &stocks[0];
    for (st = 1;st < STKS;st++)
        top = &(top->topval(stocks[st]));

    //pointer is set to topval;
    std::cout << "\nMost Valuable Holdings :\n";
    top->show();
    return 0;
}
