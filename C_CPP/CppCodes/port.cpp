#include<iostream>
using namespace std;

class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br = "none",const char * st = "none",int b = 0);
};
