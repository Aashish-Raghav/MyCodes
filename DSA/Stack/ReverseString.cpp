#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string str;
    cout << "Enter string to be reversed : ";
    getline(cin,str);
    for (int i = 0;i < str.size();i++)
        s.push(str[i]);
    
    for (int i = 0;i < str.size();i++)
    {
        str[i] = s.top();
        s.pop();
    }
    cout << "After reverse : " << str << endl;

}