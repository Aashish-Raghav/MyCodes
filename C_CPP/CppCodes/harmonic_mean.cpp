#include<iostream>
double hm(double x,double y);   //hm : harmonic mean;
int main() 
{
    using namespace std;
    int num1,num2;
    cout << "Enter two numbers(0 to quit) : ";
    cin >> num1 >> num2;
    while (num1 != 0 && num2 != 0){
        cout << "Your Harmonic Mean = " << hm(num1,num2) << endl;
        cout << "Enter two numbers(0 to quit) : ";
        cin >> num1 >> num2;
    }
    
    return 0;
}

double hm(double x,double y){
    return 2*x*y/(x+y);
}