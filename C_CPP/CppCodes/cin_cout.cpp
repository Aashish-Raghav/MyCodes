#include<iostream>
int main()
{
    std::cout << "How many carrots do you have ?" << std::endl;
    int carrots;
    std::cin >> carrots;
    //std::cout << carrots;
    std::cout << "Here are two more. " << "Now you have " << carrots+2 << " carrots.";
    return 0;
}