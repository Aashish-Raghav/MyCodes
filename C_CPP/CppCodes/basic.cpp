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




    /*{
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

        Stock max = stock1.topval(stock2);
        cout << "Maximum value stock is :\n";
        max.show();
        
    }*/
    return 0;
}

/* g++ -c *.cpp -o myprogram */

/*
cout << fixed;
cout.precision(2);
cout.setf(ios_base::showpoint);         //****
*/

/*
#include<iostream>
//various notation, same signature;
const double* f1(const double arr[],int n);
const double* f2(const double [],int);
const double* f3(const double *,int);

int main() 
{
    using namespace std;
    double av[3] = {1112.3,1542.6,2227.9};
    
    //pointer to function;
    const double* (*p1)(const double [],int) = f1;   // equivalent to &f1;
    auto p2 = f2;               //done the same job as up;
    cout << "Using Pointers to functions :\n";
    cout << "Address\tValue\n";
    cout << (*p1)(av,3) << " : " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << " : " << *p2(av,3) << endl <<endl;         // we can use (*ptr) == ptr remember braces in initial form;


    //pa an array of pointers;
    cout << "Using an array of pointers-to-functions :\n";

    return 0;
}

const double * f1(const double arr[],int n){
    return arr;         //returning pointer-to-element arr[0];
}
const double * f2(const double arr[],int n){
    return arr+1;       //returning pointer-to-element arr[1];
}
const double * f3(const double * arr,int n){
    return arr+2;       //returning pointer-to-element arr[2];
}
*/