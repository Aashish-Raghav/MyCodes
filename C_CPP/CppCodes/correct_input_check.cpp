#include<iostream>
int main() 
{
    using namespace std;
    int num;
    cin >> num;
    if (!cin) cout << "Wrong Input.\n";     // check if your input is correct as per datatype
    else cout << "You Entered : " << num; 

    return 0;
}
