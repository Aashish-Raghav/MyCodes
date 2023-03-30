#include<iostream>
#include"golf.h"
#include<cstring>

Golf::Golf(const char * name,int hc)
{
    strcpy(name_,name);
    handicap_ = hc;
}

int Golf::setGolf()
{
    char name[LEN];
    int hand;

    std::cout << "Enter full name : ";
    std::cin.get(name,LEN);

    if (name[0] == '\0') return 0;
    
    while (std::cin.get() != '\n') continue;
    std::cout << "Enter Handicap : ";
    (std::cin >> hand).get();

    Golf temp{name,hand};
    *this = temp;
    return 1;
}

void Golf::handicap(int hc)
{
    if (hc <= 0) 
    {
        std::cout << "Handicap can't be negative.\n";
    }
    else handicap_ = hc;
}

void Golf::showGolf() const
{
    std::cout << "Name : " << name_ << "\n";
    std::cout << "Handicap : " << handicap_ << "\n";
}
