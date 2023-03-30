#include<iostream>
#include<cmath>

int main()
{
    std::cout << "Enter Two Numbers :  ";
    int a,b;
    std::cin >> a >> b;   // inputting two numbers together.
    std::cout << a << " raise to the power " << b << " = " << pow(a,b);
}