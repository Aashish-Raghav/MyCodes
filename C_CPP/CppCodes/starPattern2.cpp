/*
   *
  **
 ***
****
*/

#include<iostream>
int main() 
{
    using namespace std;
    int n;
    cout << "Enter number of rows : "; (cin >> n).get();
    for (int i = 1;i <= n;i++ )
    {
        for (int j= n;j >= i+1;j--) cout << " ";
        for (int s=1;s<=i;s++) cout << "*";
        cout << endl;
    }
    return 0;
}