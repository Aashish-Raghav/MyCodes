#include <iostream>
#include <stack>
using namespace std;
template <typename T>
void printStack(stack<T> s)
{
    cout << "Your Stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

bool isReducdant(string s){
    stack<char> stack;
    // cout << "in" << endl;
    for (int i = 0;i < s.size();i++){
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            stack.push(s[i]);
        }
        else if ( s[i] == ')' ){
            bool faltuBracket = true;
            while (stack.top() != '('){
                char top = stack.top();
                // cout << top << endl;
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    faltuBracket = false;
                stack.pop();
            }

            if (faltuBracket == true)
                return false;
            stack.pop();
        }
        // printStack(stack);
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter string : ";
    cin >> s;
    
    cout.setf(ios_base::boolalpha);
    cout << isReducdant(s) << endl;
    
    return 0;
}