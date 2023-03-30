//OMG , if capitalized swap to Swap no error; :(

#include<iostream>
template <typename T>   // Or class T
void Swap(T &a,T &b);

template <typename T>
void Swap(T * a, T * b,int n);

void show(int* a);

const int Lim = 8;
int main() 
{
    using namespace std;
    cout << "\nINTEGERS\n";
    int i = 10;
    int j = 12;
    cout << "Before Swapping:\n";
    cout << "i = " << i << " j = " << j << endl;
    Swap(i,j);          //generates Swap(int &,int &);
    cout << "After Swapping:\n";
    cout << "i = " << i << " j = " << j << endl;

    cout << "\nDOUBLES\n";
    double x = 10.5;
    double y = 12.2;
    cout << "Before Swapping:\n";
    cout << "x = " << x << " y= " << y << endl;
    Swap(x,y);          //generates Swap(int &,int &);
    cout << "After Swapping:\n";
    cout << "x = " << x << " y = " << y << endl;

    cout << "\n\nARRAY\n";
    int d1[Lim] = {2,0,0,4,2,0,0,4};
    int d2[Lim] = {0,7,0,9,2,0,0,2};
    cout << "Before Swapping:\n";
    show(d1);show(d2);
    Swap(d1,d2,Lim);
    cout << "After Swapping:\n";
    show(d1);show(d2);

    return 0;
}
template <typename T>       // or can use class T;
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T * a,T * b,int n) {
    T temp;
    for (int i = 0 ;i < n;i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void show(int * a){
    using std::cout;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i =  4;i < Lim;i++){
        cout << a[i];
    }
    cout << std::endl;
}