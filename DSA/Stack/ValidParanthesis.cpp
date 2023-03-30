#include <iostream>
#include <stack>
using namespace std;

bool isMatch(char c1,char c2)
{
    if( (c1 == '(' && c2 == ')') ||
        (c1 == '[' && c2 == ']') || 
        (c1 == '{' && c2 == '}') )
        return true;
    else 
        return false;

}

bool checkValid(string s){
    if (s.empty())
        return true;
    else{
        stack<char> stack;
        for (int i = 0;i < s.size();i++)
        {
            //if opening bracket;
            if (s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{')
                stack.push(s[i]);
            //if closing bracket;
            else{
                if (!s.empty()){
                    if (isMatch(stack.top(),s[i]))
                        stack.pop();
                    else    
                        return false;
                }
                else 
                    return false;
            }
        }
        // cout << "Reached" << endl;
        if (stack.empty())
            return true;
        else    
            return false;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << s << endl; 
    cout.setf(ios_base::boolalpha);
    cout << checkValid(s) << endl;

}