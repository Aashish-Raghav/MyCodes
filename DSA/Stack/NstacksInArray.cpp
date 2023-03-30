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

class Nstack{
private:
    int s;
    int n;
    int *arr;
    int *top;
    int *next;
    int freespot;
public:
    Nstack(int n,int s) : n(n), s(s){
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //initialising top array;
        for (int i = 0;i < n;i++){
            top[i] = -1;
        }

        //initialising next array;
        for (int i = 0;i < s;i++){
            next[i] = i+1;
        }

        //updating last value of next
        next[s-1] = -1;

        freespot = 0;
    }

    bool push(int x,int m){ //here x is element && m is stack in which we have to insert;
        //check for overflow;
        if (freespot == -1){
            return false;
        }

        //storing the index at which all operation will be performed;
        int index = freespot;

        //updating freespot;
        freespot = next[index];

        //storing element in array;
        arr[index] = x;

        //updating the next;
        next[index] = top[m-1];

        //updating top;
        top[m-1] = index;

        return true;        
    }

    bool pop(int m){
        //check for underflow;
        if (top[m-1] == -1){
            return false;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return true;
    }
};

int main()
{
    
    return 0;
}