#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;    
    A() {}
    A(int a,int b) : a(a),b(b) {}
    void operator+(A & temp1)
    {
        cout << "current this : "<< this-> a << endl;
        cout << "Sum a : " << temp1.a + this->a << endl;
        cout << "Sum b : " << temp1.b + this->b << endl;
    }
    void operator() (A & temp1) {
        cout << "current this : "<< this->a << endl;
        cout << "Sum a : " << temp1.a + this->a << endl;
        cout << "Sum b : " << temp1.b + this->b << endl;
    }
    void speak()
    {
        cout << "HELLO" << endl;
    }
};

class B : public A{
public:
    void speak(int r)
    {
        cout << "NO" << endl;
    }
};

int main()
{
    // A obj1(4,5);
    // A obj2(6,7);
    // obj1 + obj2;
    // obj1(obj2);
    A obj1;
    B obj2;
    obj1.speak();
    obj2.speak(4);
    obj2.A::speak();
}