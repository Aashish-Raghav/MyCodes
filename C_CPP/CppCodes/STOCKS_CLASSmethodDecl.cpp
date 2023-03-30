#include<iostream>
#include "stock00.h"

Stock::Stock() 
{
    std::cout << "Default constructor called\n";
    company = "NO NAME";
    shares = 0;
    share_val = 0;
    total_val = 0;
    std::cout << std::endl;
}

Stock::Stock(const std::string & co,long n,double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}



void Stock::buy(long num,double pr)
{
    if (num < 0) 
    {
        std::cout << "Number of shares purchased can't be negative. "
                    <<"Transaction is aborted.\n";
    }
    else 
    {
        shares += num;
        share_val = pr;
        set_tot();
    }
}

void Stock::sell(long num,double pr)
{
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative; "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "Can't sell shares more than you have! "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = pr;
        set_tot();
    }
}

void Stock::update(double pr)
{
    share_val = pr;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;

    //store format;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    //number like #.###
    std::streamsize prec = cout.precision(3);

    std::cout << "Company : " << company
              << " Shares : " << shares << "\n"
              << "Share Prices : $" << share_val << "\n";
              //number like #.##
              cout.precision(2);
         cout << "Total Worth : $" << total_val << "\n\n";

    //restore original format;
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}