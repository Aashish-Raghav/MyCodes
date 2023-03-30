#include<iostream>
using std::cout;
#include "stone.h"

void display(const Stonewt & st,int n);

int main()
{
    Stonewt incognito = 275;        //OR Stonewt incognito(275) (implicit) OR Stonewt incognito = Stonewt(275) (explicit constructor)
    Stonewt wolfe(287.5);
    Stonewt taft(21,8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    
    incognito = 276.8;
    taft = 375;
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_lbs();
    display(taft,2);
    cout << "The wrestler weighed even more.\n";
    display(422,2);
    cout << "No stone left unearned\n";

    Stonewt poppins(9,2.8);
    double p_wt = (double) poppins;      //implicit conversion;
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds";  //explicit conversion;
    return 0;
}

void display(const Stonewt & st,int n)
{
    for (int i = 0;i < n ;i ++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}