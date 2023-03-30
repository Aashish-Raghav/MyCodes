#include <iostream>
using namespace std;


//case Conversion
/*
A -> 01000001                a -> 01100001
B -> 01000010                b -> 01100010
C -> 01000011                c -> 01100011
.                               .
.                               .
Z -> 01011010                z -> 01111010
*/
char UpperToLower(char ch){
    int mask = 1 << 5;
    return mask | ch;
}

char lowerToUpper(char ch){
    int mask = 1 << 5;
    mask = ~mask;
    return mask & ch;
}

int main(){
    cout << lowerToUpper('a') << endl;
    cout << UpperToLower('A') << endl;
    return 0;
}