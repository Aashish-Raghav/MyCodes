#include<iostream>
#include "stock00.h"
int main() 
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart",12,20.00);     // may create temporary object but here not;
        stock1.show();
        Stock stock2 = Stock("Boffo Objects",2,2.0);
        stock2.show();

        cout << "Assigning stock1 and stock2 : \n";
        stock2 = stock1;        // may create temporary object but here not;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods",10,50.0);      //temp object definately created;
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}
