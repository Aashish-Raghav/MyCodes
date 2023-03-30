//class defination in file CLASSmethodDecl.cpp
//using class in file CLASSuse.cpp

#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = share_val * shares;}
public:
    Stock();        //default constructor OR Stock(const std::string & co = "no name",long n = 0,double pr = 0);
    Stock(const std::string & co,long n = 0,double pr = 0);     //non default constructor 
    ~Stock();       // destructor;
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s) const;
};

#endif