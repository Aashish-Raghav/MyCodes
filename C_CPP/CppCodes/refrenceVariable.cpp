#include<iostream>
//NOTE;
// here we have created a reference variable but it is not the typical use of it
// it is typically used for structure and object argument to the function;

int main() 
{
    using namespace std;
    int num = 10;
    int & no = num;
    cout << "num = " << num << " and " << "no = " << no << endl;
    cout << "no++\n";
    no++;
    cout << "num = " << num << " and " << "no = " << no << endl;
    cout << "num address = " << &num << " and " << "no address = " << &no << endl;
    return 0;
}