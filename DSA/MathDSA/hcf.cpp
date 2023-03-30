#include <iostream>
using namespace std;

//Euclid Algo
//gcd(a,b) = gcd(a%b,b) = gcd(a-b,b);
int hcf_1a(int a,int b);    //through loop;
int hcf_1b(int a,int b);

int hcf_2a(int a,int b);
int hcf_2b(int a,int b);

int main()
{
    cout << hcf_2b(12,13) << endl;
}

int hcf_1a(int a,int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int r;
    while (a != 0 && b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int hcf_1b(int a,int b)
{
    // cout << "Yes " << endl;
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a > b )
        return ( hcf_1b(a%b,b));
    else
        return ( hcf_1b(b%a,a));
    
}

int hcf_2a(int a,int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {
        if ( a > b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

int hcf_2b(int a,int b)
{
    cout << "yes " << endl;
    // base cases;
    if (a == b)
        return a;
    if (a == 0)
        return a;
    if (b == 0)
        return b;

    if (a > b)
        return hcf_2b(a-b,b);
    else    
        return hcf_2b(a,b-a);

}