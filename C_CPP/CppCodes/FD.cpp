#include <iostream>
#include <cmath>
#include <iomanip>
static int principal;
long long Fd(double p,double r,double n);
int main()
{
    using namespace std;
    std::cout << "Enter principal amount : ";
    double p;
    cin >> p;
    cout << "Enter interest rate : ";
    principal = p;
    double r;
    cin >> r;
    cout << "Enter years : ";
    double n;
    cin >> n;
    double Amount = Fd(p,r,n);
    cout << "Your Amount after " << n << " years"
            " at rate of " << r << char(37) << "  is :\n";
    cout << fixed << setprecision(2) << Amount;
    return 0;
}
long long Fd(double p,double r,double n)
{
    long long Amount = p;
    while (n)
    {
        Amount = Amount *(1+ r/100);
        Amount += principal;
        n--;
    }
    return Amount - principal;
}