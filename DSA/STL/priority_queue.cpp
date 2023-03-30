#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //max heap;
    priority_queue<int> p1;  
    p1.push(1);
    p1.push(10);
    p1.push(2);
    p1.push(6);

    int i = p1.size();
    while (i > 0)
    {
        cout << "p1.top() = " << p1.top() << endl;
        p1.pop();
        i--;
    }

    //min heap
    priority_queue<int,vector<int>,greater<int> > p2;
    p2.push(1);
    p2.push(10);
    p2.push(2);
    p2.push(6);

    i = p2.size();
    while (i > 0)
    {
        cout << "p.top() = " << p2.top() << endl;
        p2.pop();
        i--;
    }
}