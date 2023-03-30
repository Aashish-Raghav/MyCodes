#include<iostream>
#include<cstring>

int main() 
{
    using namespace std;
    //some ways of declaring string are:
    string strr1;                 //way 1
    string strr2 = "Hello";       //way 2
    string strr3 = {"guys"};      //way 3
    string strr4 {"biro"};        //way 4

    //string operation;
    strr1 = strr2;       //assingment of string to string is allowed unlike strcpy in character array;
    strr4 = strr1 + " " + strr2 + " " + strr3;   // concatinaton is directly unlike strcat in char array;
    //here no danger of size as in array while copying or concatatinating one to another must enough big to hold;
    cout << strr4 << endl;
    strr4 += " byee";       //appending directly 
    cout << strr4 << endl;
    cout << strr4.size() << " size of string.\n";      //length of string using size() METHOD* unlike strlen FUNCTION* in char array
    return 0;

}