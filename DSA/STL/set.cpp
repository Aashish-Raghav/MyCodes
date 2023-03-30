#include <iostream>
#include <iomanip>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(12);

    auto itr = s.begin();
    for (;itr != s.end();itr++)
    {
        cout << "*itr = " << *itr << endl;
    }

    auto itr2 = s.find(5);
    cout << "*itr2 = " << *itr2 << endl;
    cout << "*s.find(0) = " << *s.find(23) << endl;

    // cout << boolalpha;
    cout << "s.count(4) = " << boolalpha << s.count(4) << endl;
}