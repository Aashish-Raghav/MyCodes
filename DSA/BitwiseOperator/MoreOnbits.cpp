#include <iostream>
using namespace std;

//clearing all bits from lsb to ith pos         //lsb == right Most Bit;
int lsbToi(int x,int i){
    int mask = ~((1 << i+1 ) - 1);
    x &= mask;
    return x;
}

//clearing all bits from msb to ith pos         //msb == leftMost bit;
int msbToBit(int x,int i){
    int mask = (1 << i) - 1;
    x &= mask;
    return x;
}

int divideBy2(int x){
    return x >> 1;
}

int multBy2(int x){
    return x << 1;
}


int main(){

    return 0;
}