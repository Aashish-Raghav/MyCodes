//celsius to fahrenheit conversion;
#include<iostream>
int main() 
{
    std::cout << "Please enter a Celsius value : ";
    double cvalue;
    std::cin >> cvalue;
    std::cout << cvalue << " degrees Celsius is " << (9*cvalue)/5.0 + 32.0 << " degrees Fahrenheit.";
    return 0;
}