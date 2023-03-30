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

void solve(int* arr,int size){
    if (size == 1){
        arr[0] = -1;
        return;
    }
    stack<int> s;
    s.push(-1);
    for (int i = size-1;i >= 0;i--){
        // cout << "s.top() : " << s.top() << endl;
        // cout << "arr[i] : " << arr[i] << endl;
        while (s.top() >= arr[i])
            s.pop();
        // printStack(s);
        int top = s.top();
        s.push(arr[i]);
        arr[i] = top;
    } 
    
}

int main()
{
    int arr[3] = {2,3,1};
    solve(arr,3);
    for (int i = 0;i < 3;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}