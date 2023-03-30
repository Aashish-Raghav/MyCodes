#include <iostream>
using namespace std;


//NOTE: because of operator precedence we have to use, () for bit operation;
int main()
{
    int a,b;
    cin >> a >> b;
    // AND &     OR |      XOR ^      complement ~;
    cout << a << " & " << b << " = " << (a&b) << endl;
    cout << a << " | " << b << " = " << (a|b) << endl;
    cout << a << " ^ " << b << " = " << (a^b) << endl;
    cout << "~" << a << " = " << (~a) << endl;
    

    //left shift << (*2)      right shift >> (/2)
    cout << (17 << 1) << endl;
    cout << (17 << 2) << endl;
    cout << (17 >> 1) << endl;
    cout << (17 >> 2) << endl;

    cout << "\nWe are Done!\n";




}