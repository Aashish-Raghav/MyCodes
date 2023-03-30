#include<iostream>
int main() 
{
    using namespace std;
    // STRING POINTER
    string str = "Hii ";            
    string *pstr = &str;
    cout << "Value at *pstr : " << *pstr << " at address " << (unsigned) pstr << endl;

    //CHARACTER POINTER
    char ch = 'a';
    char *pch = &ch;
    cout << "Value at *pch : " << *pch << " at address " << (unsigned) pch;

    //character value in int pointer;
    //char ch = 'p';
    //int* pch = &ch;     //a value of type char* cannot be used to initialize an entity of type int*


    return 0;
}