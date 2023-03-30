// time in years in which cint maximise sint;

#include <iostream>
const int Amount = 100;
int main() 
{
    using namespace std;
    int sint=0,cint=0;              //sint = simple interest ; cint = compound interest;
    int i = 1;
    double orgBal = Amount;
    do {
        sint = Amount * 0.1 *i;
        cint = orgBal * 0.05;
        orgBal += cint;
        i++;
    } while (orgBal < Amount + sint );
    cout << "Compound investment : " << orgBal << endl;
    cout << "Simple investment : " << Amount + sint << endl;
    cout << "in years : " << i << endl;
    return 0;
}