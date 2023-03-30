#include<iostream>
int main() 
{
    using namespace std;
    int x = 20;
    cout << "x = " << x << endl;
    {
        cout << "x = " << x << endl;
        int x = 30;                 //new x is created for block;
        cout << "x= " << x << endl;
    }
    cout << "x = " << x << endl;

    {
        cout << "x = " << x << endl;
        x = 30;                     //global x is used and changes reflected after block;
        cout << "x= " << x << endl;
    }
    cout << "x = " << x << endl;

    return 0;
}