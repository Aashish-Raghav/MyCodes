#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    map<int,string> m;
    m[1] = "hello";
    m[2] = "bye";
    m[3] = "world";
    m.insert({3,"World"});

    cout << m[2] << endl;
    cout << m.count(2) << endl;
}