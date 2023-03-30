#include <iostream>
#include <iomanip>
#include <vector>
//under std;
using namespace std;

template <class T>
void printArr(vector<T> v)
{
    for (int i = 0;i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    //intialisation;
    vector<int> v1; //size = 0, capacity = 0;
    vector<int> v2(1);  //size = 1;
    vector<int> v3(4,1);    //v3 = 1 1 1 1;
    vector<int> v4 = {1,2,3,4};

    //traversing;
    printArr(v1);   // print blank;
    printArr(v2);   //print 0;
    printArr(v3);
    printArr(v4);

    cout << endl;
    //methods;
    cout << "v.size() = " << v4.size() << endl;
    cout << "v.capacity = " << v4.capacity() << endl;
    cout << "v.front() = " << v4.front() << endl;
    cout << "v.back() = " << v4.back() << endl;
    cout << "v.at(2) " << v4.at(2) << endl;
    cout << "v[2] = " << v4[2] << endl;
    cout << boolalpha;
    cout << "v.empty() = " << v4.empty() << endl;
    
    cout << endl;
    //insertion and deletion method;
    v4.push_back(5);
    v4.push_back(6);
    printArr(v4);
    v4.pop_back();
    printArr(v4);
    v3.clear();
    printArr(v3);
    cout << "v3.empty() = " << v3.empty() << endl;

    cout << endl;
    //iterator;
    auto itr1 = v4.begin();
    cout << "*itr = " << *itr1 << endl;
    vector<int>::iterator itr2 = v4.end();
    cout << "*itr = " << *itr2 << endl;
    v4.erase(v4.begin(),v4.begin() + 2);
    printArr(v4);
    return 0;
}