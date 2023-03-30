#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int size = 3;
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

int  findCelebrity(int v[size][size]){
    stack<int> s;
    for (int i = 0;i < size;i++){
        s.push(i);
    }
    
    while (s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        //a knows b;
        if (v[a][b] == 1)
            s.push(b);
        else    //b knows a;
            s.push(a);
    }
    cout << s.top() << endl;
    //verifying the potential celebrity;
    
    //checking row;
    int celebrity = s.top();
    for (int i = 0;i < size;i++){
        if (v[celebrity][i] != 0)
            return -1;
    }
    //checking column;
    for (int i = 0;i < size;i++){
        if (i == celebrity)
            continue;
        if (v[i][celebrity] != 1)
            return -1;
    }
    //col bhi sahi hai and row bhi sahi hai;
    return celebrity;

}

int main()
{
    int v[size][size] = {{0,1,0},{0,0,0},{0,1,0}};

    // cout << endl;
    // for (int i = 0;i < size;i++){
    //     for (int j = 0;j < size;j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << findCelebrity(v) << endl;

    return 0;
}