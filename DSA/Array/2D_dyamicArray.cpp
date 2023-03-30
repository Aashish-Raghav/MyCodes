#include <iostream>
using namespace std;
int main()
{
    //creating 2D array
    int row,col;
    cin >> row >> col;
    int** arr = new int*[row];
    
    for (int i = 0;i < row;i++)
    {
        arr[i] = new int[col];
    }

    //taking input;
    for (int i = 0;i < row;i++)
        for (int j = 0;j < col;j++)
            cin >> arr[i][j];

    //displaying output;
    for (int i = 0;i < row;i++){
        for (int j = 0;j < col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //deleting 2D array;
    for (int i = 0;i < row;i++)
        delete [] arr[i];
    delete [] arr;
    return 0;
}