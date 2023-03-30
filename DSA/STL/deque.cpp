#include <iostream>
#include <iomanip>
#include <deque>    //doubly ended queue;
//under std;
//both front and back access is allowed here for insertion and deletion;
using namespace std;

template<class T>
void print(deque<T> d)
{
    for (int i = 0;i < d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main()
{
    //initialisation
    deque<int> d1;  //with size = 0;
    deque<int> d2(2);   // with size = 2; 0 0   
    deque<int> d3(2,1); // 1 1;
    deque<int> d4 = {1,2,3,4};

    //traversing;
    print(d1);
    print(d2);
    print(d3);
    print(d4);

    cout << endl;
    //methods;
    cout << "d.size() << " << d4.size() << endl;
    cout << "d.at() " << d4.at(2) << endl;
    cout << "d[i] = " << d4[2] << endl;
    cout << "d.front() = " << d4.front() << endl;
    cout << "d.back() = " << d4.back() << endl;
    cout << boolalpha;
    cout << "d.empty() = " << d4.empty() << endl;

    cout << endl;
    //insertion and deletion mehtods
    d4.push_back(12);
    d4.pop_front();
    print(d4);
    d4.push_front(1);
    d4.pop_back();
    print(d4);
    d4.erase(d4.begin());
    print(d4);
    d4.erase(d4.end() - 2,d4.end());
    print(d4);


    return 0;
}