#include <iostream>
#include <sstream>
using namespace std;

void simple(string s)
{
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        // cout << word << endl;   
    }
    cout << s << endl;
    // cout << word << endl;
    
}
int main()
{
    const int x = 5;
    int* ptr = &x;
    *ptr = 7;
    cout << x << endl;
    // char ch[20] = "hello world is my";
    // std::string s;
    // s = ch;
    // cout << &s << endl;
    // cout << &ch << endl;
    // cout << ch << endl;
    // cout << s << endl;
    // // s[0] = '1';
    // ch[0] = '1';
    // simple(s);
    // std::cout << s << std::endl;   
    // std::cout << ch << std::endl; 
    return 0;
}