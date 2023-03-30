/*
The & operator can be used to quickly check if a number is odd or even.
 The value of expression (x & 1) would be non-zero(ie 1) only if x is odd,
 otherwise the value would be zero. 
*/
#include <iostream>
using namespace std;

int main(){
    cout << (18 & 1) << endl;   //output 0;
    cout << (19 & 1) << endl;   //output 1;

    cout << (12>>2) << endl;
}