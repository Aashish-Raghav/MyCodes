//two stack in one array;
#include <iostream>
using namespace std;

class TwoStack{
private:
    int* arr;
    int top1;
    int top2;
    int max_size;
public:
    TwoStack(int size) : max_size(size), top1(-1),top2(size) { arr = new int[size];}
    bool full(){
        return (top2 - top1 == 1) ? true : false;
    }
    void push1(int element){
        if (this->full())
            cout << "Stack overflow" << endl;
        else
            arr[++top1] = element;
    }

    void push2(int element){
        if (this->full())
            cout << "Stack overflow" << endl;
        else    
            arr[--top2] = element;
    }

    void pop1(){
        if (top1 == -1)
            cout << "Stack underflow 1" << endl;
        else    
            top1--;
    }
    void pop2(){
        if (top2 == max_size)
            cout << "Stack underflow 2" << endl;
        else    
            top2++;
    }   
};

int main()
{
    TwoStack s(5);
    s.push1(1);
    s.push2(2);
    s.push1(3);
    s.push2(4);
    s.push1(5);
    s.push1(7);
    s.pop1();
    s.pop2();
    s.pop1();
    s.pop2();
    s.pop1();
    s.pop2();
}