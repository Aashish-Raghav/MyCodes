#include<iostream>
int main() 
{
    using namespace std;
    short flag = 10;
    short* pflag = &flag;
    cout << "size of pflag : " << sizeof pflag << endl;     //sizeof pointer = 4;
    cout << "size of *pflag : " << sizeof *pflag; 
    return 0;
}