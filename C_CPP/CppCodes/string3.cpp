#include<iostream>
#include<cstring>

int main() 
{
    using namespace std;
    //inputting multiple line in string.
    string str1;
    cout << "String size before input : " << str1.size() << endl;
    cout << "Enter a string : " << endl;
    getline(cin,str1);
    cout << " Your input : " << str1 << endl;
    cout << "String size after input is : " << str1.size() << endl;

    //RAW string;
    cout << R"(Jim "king" Tutt uses "\n" instead of endl.)";   //"( both end delimeter with prefix R )"
    cout << R"+( Hii "(guys )" whats happening )+";     //some basic character are allowed in b/w " and (;

    return 0;
}