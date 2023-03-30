#include<iostream>
#include"golf.h"
const int Size = 5;

int main()
{
    Golf g1 = Golf("Aashish Raghav",24);
    g1.showGolf();
    g1.handicap(500);
    g1.showGolf();

    Golf arr[Size];
    int player =0;
    while (player < Size && arr[player].setGolf()) player++;

    for (int i = 0 ;i < player;i++)
    {
        arr[i].showGolf();
    }
    return 0;
}