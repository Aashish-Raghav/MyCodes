// limits of signed int,short,long, long long.

#include<iostream>
#include<climits>

int main() 
{
    std::cout << "int is " << sizeof(int) << " bytes." << std::endl;
    std::cout << "short is " << sizeof(short) << " bytes." << std::endl;
    std::cout << "long is " << sizeof(long) << " bytes." << std::endl;
    std::cout << "long long is " << sizeof(long long) << " bytes." << std::endl;
    
    std::cout << std::endl;

    std::cout << "Maximum values:"<< std::endl;
    std::cout << "int : " << INT_MAX << std::endl;
    std::cout << "short : " << SHRT_MAX << std::endl;
    std::cout << "long : " << LONG_MAX << std::endl;
    std::cout << "long long : " << LLONG_MAX << std::endl;

    std::cout << std::endl;

    std::cout << "Minimum int value : " << INT_MIN << std::endl;
    std::cout << "Bits per byte = " << CHAR_BIT << std::endl;

}