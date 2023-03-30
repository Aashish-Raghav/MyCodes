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

    for (int i = 1;i <= n;i++)
    {
        for (int s = 1;s <= i-1;s++) cout << " ";
        for (int j = n;j>=i;j--) cout << "*";
        cout << endl;

    }
    return 0;
}