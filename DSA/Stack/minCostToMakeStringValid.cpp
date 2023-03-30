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

int solve(string s)
{
    stack<char> stack;
    if (s.size()%2 == 1)
        return -1;
    
    for (int i = 0;i < s.size();i++){
        char ch = s[i];
        if (ch == '{')
            stack.push(ch);
        else{
            if (!stack.empty() && stack.top() == '{')
                stack.pop();
            else
                stack.push(ch);
        }
    }

    int a = 0,b = 0;
    while (!stack.empty()){
        if (stack.top() == '{')
            a++;
        else
            b++;
        stack.pop();
    }
    return (a+1)/2 + (b+1)/2;
}
int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}