#include <iostream>
using namespace std;

int main()
{
    int *p = 0;
    int first = 10;
    // *p = first; //segmentation error;
    p = &first;
    cout << *p << endl;
}