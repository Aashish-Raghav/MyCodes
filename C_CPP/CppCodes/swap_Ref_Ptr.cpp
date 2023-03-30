#include<iostream>
void swapr(int & a,int & b);    //swap by reference;
void swapp(int* a,int* b);  //swap by pointer;
int main() 
{
    using namespace std;
    int a = 5,b = 10;
    cout << "a = " << a << " and " << "b = " << b << endl;
    // swapping using refrence variable;
    cout << "After swapping\n";
    swapr(a,b);
    cout << "a = " << a << " and " << "b = " << b << endl;
    //swapping using pointer variable;
    cout << "Swapping Again\n";
    swapp(&a,&b);
    cout << "a = " << a << " and " << "b = " << b << endl;
    return 0;
}
void swapr(int & a,int & b){
    int temp = a;
    a = b;
    b = temp;
}
void swapp(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}