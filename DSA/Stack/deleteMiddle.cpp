#include <iostream>
#include <stack>
#include <vector>
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

//approach 1;
template <typename T>
stack<T> deleteMid1(stack<T> &s)
{
    int size = s.size();
    int midPos = size/2;
    vector<int> v;
    while (midPos--)
    {
        v.push_back(s.top());
        s.pop();
    }
    s.pop();
    for (int i = v.size()-1;i >= 0;i--)
        s.push(v[i]);
    return s;
}

//Approach 2 using recursion
template <typename T>
void deleteMid2(stack<T> &s,int count,int size)
{
    //base case;
    if (count == size/2){
        s.pop();
        return;
    }
    
    T temp = s.top();
    s.pop();
    deleteMid2(s,count+1,size);
    s.push(temp);
    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    printStack(s);
    deleteMid1(s);
    printStack(s);

    deleteMid2(s,0,s.size());
    printStack(s);
    return 0;
}