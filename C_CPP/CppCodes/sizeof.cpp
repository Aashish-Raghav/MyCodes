#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    string str2 = "a";
    string str1;
    cout << sizeof str1 << endl;        // Note sizeof fxn returns the size of datatype not the data;
    cout << sizeof str2 << endl;
    cout << sizeof(string);
    return 0;
}