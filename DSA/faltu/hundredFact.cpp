#include<iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;

void print(vector<int> v)
{   
    cout << v.size() << endl;
    for (int i = 0;i < v.size();i++)
    {
        cout << v[i] << "";
    }
    cout << endl;
}
int main()
{
    int t = 1;
    while (t--){
        int n = 100;
        vector<int> v;
        v.push_back(1);
        int ans = 1;
        for (int j = 2;j <= n;j++)
        {
            int carry = 0;
            for (int i = 0;i < v.size();i++)
            {
                int ans = v[i]*j + carry;
                carry = ans/10;
                v[i] = ans%10;
            }
            while (carry)
            {
                v.push_back(carry%10); 
                carry = carry/10;
            }
        }
        reverse(v.begin(),v.end());
        print(v);
    }
}