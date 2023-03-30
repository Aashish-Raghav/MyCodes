#include<iostream>
long double factorial(long double);
int main() 
{
    using namespace std;
    int num;
    cout << "Enter an number to calculate factorial(else to exit): ";
    while ((cin >> num) && num >= 0){
        cout << num << "! = " << factorial(num) << endl;
        cout << "Enter next number : "; 
    }

    return 0;
}
long double factorial(long double n){
    if (n == 0 || n == 1) return 1;
    long double fact = n * factorial(n-1);
    return fact;
}