#include <bits\stdc++.h>
using namespace std;

// 1. XOR of same number is 0;
// 2. XOR with zero is same number;




int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << (((a&b)|c)^d) << endl;
    // cout << () << endl;
    // cout << (6^5) << endl;
    // float a = 1.1;
    // float b = 1.1;
    // if (abs(a-b) < 1e-9) 
    //     cout << "int" << endl;
    // cout << islower('a') << endl;
    return 0;
}