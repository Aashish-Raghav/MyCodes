#include<iostream>
const int ArSize = 16;
int main() 
{
    using namespace std;
    //for predefined range;
    long long factorial[ArSize];
    factorial[0] = factorial[1]= 1;
    ;
    for (int i=2;i<ArSize;i++) factorial[i] = i * factorial[i-1];
    for (int i=0;i<ArSize;i++) cout << i <<"! = " << factorial[i] << endl;

    //for a number
    int n;
    long long fact = 1;
    cout << "\nEnter the number : "; cin >> n;
    for (int i = 1; i <=n ;i++) fact *= i;
    cout << n << "! = " << fact;

    //for a user input range;
    int start,end; 
    cout << "\n\nEnter your start : "; cin >> start;
    cout << "Enter your end :: "; cin >> end;
    long long *pfact = new long long [end+1];
    pfact[0] = pfact[1] = 1;
    for (int i=2;i <= end;i++) pfact[i] = i * pfact[i-1];
    for (int i=start;i <= end;i++) cout << i << "! = " << pfact[i] << endl;
    return 0;
}