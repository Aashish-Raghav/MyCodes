//includ

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

class SpecialStack{
private:
    //data members;
    stack<int> s;
    int mini = INT32_MAX;
public: 
    void push(int data){
        if (s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if (data > mini){
                s.push(2*mini - data);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop(){
        if (s.empty())
            return -1;
        int curr = s.top();
        s.pop();
        if (curr > mini){
            return mini;
        }

    }

};

int main()
{
    
    return 0;
}