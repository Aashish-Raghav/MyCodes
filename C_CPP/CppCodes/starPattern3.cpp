/*
****
***
**
*
*/
#include<iostream>
int main() 
{
    using namespace std;
    int n;
    cout << "Enter number of rows : "; (cin >> n).get();
    for (int i = 1;i<=n;i++)
    {
        for (int j = n;j>=i;j--) cout << "*";
        cout <<endl;
    }
    return 0;
}