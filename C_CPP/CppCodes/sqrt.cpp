#include<iostream>
#include<cmath> // or math.h

int main() 
{
    std::cout << "Enter the Floor area,in sq feet,of your home : ";
    double area;
    std::cin >>area;
    std::cout << "Sides are equivalent to "<< sqrt(area)<<" ." << std::endl;
}