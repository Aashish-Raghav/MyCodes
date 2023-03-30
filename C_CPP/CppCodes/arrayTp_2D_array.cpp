// making a 2D array using array template
#include <iostream>
#include "arraytp.h"
int main()
{
    using std::cout;
    // using std::cin;
    ArrayTp<int,10> sums;   //array of 10 int;
    ArrayTp<double,10> aves;    //array of 10 double; (average)
    ArrayTp< ArrayTp<int,5>,10> Two_D; // == Two_D[10,5];

    int i ,j;
    for (i = 0;i < 10;i++)
    {
        sums[i] = 0;
        for (j = 0;j < 5;j++)
        {
            Two_D[i][j] = (i+1) * (j+1);
            sums[i] += Two_D[i][j];
        }
        aves[i] = (double) sums[i] / 10;
    }

    for (i = 0;i < 10;i++)
    {
        for (j = 0;j < 5;j++)
        {
            cout.width(2);      //represent each(one char and two char) numbers occuping two char space; 
            cout << Two_D[i][j] << ' ';
        }
        cout << " : sum = ";
        cout.width(3);      //represent each(one char, two char, three char) numbers occuping three char space;
        cout << sums[i] << ", average = " << aves[i] << std::endl;
    }
}