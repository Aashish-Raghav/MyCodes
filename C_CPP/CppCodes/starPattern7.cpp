/*diamond;
   *
  ***
 *****
*******
*******
 *****
  ***
   *
*/

#include<iostream>
int main() 
{
    using namespace std;
    int n;
    cout << "Enter number of rows : "; (cin >> n).get();
    for (int i = 1; i <= n;i++)
    {
        for (int j=1;j<=n-i;j++) cout << " ";
        for (int s=1;s<=i*2 - 1;s++) cout << "*";
        cout << endl;
    }
    for (int i = 1;i <= n;i++) 
    {
        for (int j=1;j<=i-1;j++) cout <<" ";
        for (int s=1;s<=(n-i+1)*2 -1;s++) cout << "*";
        cout << endl;
    }
    return 0;
}