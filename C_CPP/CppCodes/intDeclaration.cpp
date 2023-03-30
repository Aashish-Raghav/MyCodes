#include<iostream>

int main()
{
    int a(12);          //way 1
    int b = 12;         //way 2
    int c = {12};       //way 3
    int d{12};          //way 4

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    return 0;
}