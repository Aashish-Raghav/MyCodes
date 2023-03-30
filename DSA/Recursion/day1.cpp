#include <iostream>
#include <iomanip>
using namespace std;
#define ll long long int
#define bk break;


ll factorial(ll n) //O(n)
{
    //base case
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}

ll power2(ll n) //O(n)
{
    //base case;
    if (n == 0)
        return 1;
    
    return 2*power2(n-1);
}

void printDesc(ll n) //O(n)
{
    //base case;
    if (n == 0)
        return;

    cout << setw(2) << n << " ";
    printDesc(n-1);
}

void printAsec(ll n)    //O(n)
{
    //base case;
    if (n == 0)
        return;
    printAsec(n-1);
    cout << setw(2) << n << " ";
}

int fibonacci(int n)    //O(2^n)
{
    if (n == 1 || n == 2)
        return (n-1);
    // cout << n << " ";
    return fibonacci(n-2)+fibonacci(n-1);
}

int climbStairs(int n)  //O(2^n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return climbStairs(n-1)+ climbStairs(n-2);
}

void numToWord(int n)
{
    switch(n)
    {
        case 1 : cout << "one "; bk
        case 2 : cout << "two "; bk
        case 3 : cout << "three "; bk
        case 4 : cout << "four "; bk
        case 5 : cout << "five "; bk
        case 6 : cout << "six "; bk
        case 7 : cout << "seven "; bk
        case 8 : cout << "eight "; bk
        case 9 : cout << "nine "; bk
        case 0 : cout << "zero "; bk
    }
    
}

void printInWord(int n) //O(no of digits in n);
{
    //base case;
    if (n == 0)
        return;
    printInWord(n/10);
    numToWord(n%10);
} 

int main()
{
    int n;
    cin >> n;
    // cout << "Factorial of " << n << " : " << factorial(n) << endl;

    // cout << "2 raised to power " << n << " : " << power2(n) << endl;

    //print from n to 1;
    // cout.setf(ios_base::boolalpha);
    // printDesc(n);
    // cout << endl;
    
    //print from 1 to n;
    // printAsec(n);
    // cout << endl;

    //nth term of fibonaccci series is;
    // cout << fibonacci(n) << endl;

    //climbStairs
    // cout << climbStairs(n) << endl;

    //print in word the given number;
    cout << n << " in words : "; printInWord(n);

}