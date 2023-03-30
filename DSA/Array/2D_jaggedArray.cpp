#include <iostream>
using namespace std;

//using dynamic memory;
int main()
{
    int row;
    cout << "Enter no of row : ";
    cin >> row;
    //create jagged array;
    int** arr = new int*[row];
    int storeCount[row];
    for (int i = 0;i < row;i++)
    {
        cout << "Enter size of " << i+1 << " row : " << endl;
        cin >> storeCount[i];
    }
    cout << "size are\n";
    for (auto i : storeCount)
        cout << i << endl;

    //inputting in jagged array;
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < storeCount[i];j++)
            cin >> arr[i][j];
    }

    cout << "\nReached\n" << endl;
    //outputting jagged array;
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < storeCount[i];j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "output!" << endl;
    //deleting jaggerd array;
    // for (int i = 0;i < row;i++)
    //     delete[] arr[i];
    // delete[] arr;
    cout << "Deleted " << endl;
    return 0;
}