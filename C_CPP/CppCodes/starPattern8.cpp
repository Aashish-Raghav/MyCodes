/*inverse diamond
*******
 *****
  ***
   *
   *
  ***
 *****
*******
*/
#include <iostream>
int main()
{
    using namespace std;
    int n;
    cout << "Enter the number of rows : "; cin >> n;
    for (int i = 1 ; i <= n;i++)
    {
        for (int s = 1; s<=i-1;s++) cout << " ";
        for (int j = (n-i+1)*2 -1 ;j>=1;j--) cout << "*";
        cout << endl;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int s = n-i;s >=1;s--) cout << " ";
        for (int j = i*2 -1 ;j>=1 ;j--) cout << "*";
        cout << endl;
    }
    return 0;
}