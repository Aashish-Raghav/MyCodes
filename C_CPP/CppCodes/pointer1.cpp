#include<iostream>
int main() 
{
    using namespace std;
    int updates = 6;
    int* p_updates = &updates;

    // values;
    cout << "updates value : " << updates << endl;
    cout << "*p_updates value : " << *p_updates << endl <<endl;

    // address;
    cout << "Address (&updates) : " << &updates << endl;
    cout << "Address p_updates : " << p_updates << endl;

    // change value using pointer;
    (*p_updates)++;             // remeber to put *ptr in PARANTHESIS*
    cout << "New value : " << *p_updates << " at address : " << p_updates << endl;

    return 0;
}