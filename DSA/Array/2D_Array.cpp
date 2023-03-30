#include <iostream>
using namespace std;

void printArr(int arr[][4],int);

bool isPresent(int arr[][4],int,int);
void row_WiseSum(int arr[][4],int );
void col_WiseSum(int arr[][4],int );
void largestSum(int arr[][4],int );
void leastSum(int arr[][4],int );
void wavePrint(int arr[][4],int );
void spiralPrint(int arr[][4],int);
void rotate90_(int arr[][4],int);
void rotate90_1(int arr[][4],int);
void rotate90_2(int arr[][4],int);
void rotate90_3(int arr[][4],int);
bool binarySearch(int arr[][4],int,int);
bool binarySearchAdvance(int arr[][4],int,int);

/*
bool isArmstrongNo(int no)
{
    int no = 153;
    int temp = no;
    int sum = 0;
    while (temp != 0)
    {
        int digit = temp % 10;
        sum = sum + (digit*digit*digit);
        temp /= 10;
    }
    
    if (sum == no)
        return true;
    return false;
}
*/

int main()
{
    /*
    cout << "Armstrong no from 0 to 1000 are : ";
    cout.setf(ios_base::boolalpha);
    for (int i = 0;i < 1000;i++)
    {
        if (isArmstrongNo(i))
        {
            cout << i << " ";
        }
    }
    */
    
    int arr[4][4] = {1,5,9,13,2,6,10,12,3,7,11,15,4,8,12,16};
    cin >>arr[0][0] ;
    printArr(arr,4);
    cout.setf(ios_base::boolalpha);
    cout << binarySearchAdvance(arr,4,-1);
} 

void printArr(int arr[][4],int row)
{
   for (int i = 0;i < row;i++)
   {    
        for (int j = 0;j < 4;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
   } 
}

bool isPresent(int arr[][4],int row,int target)
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (arr[i][j] == target)
                return true;
        }
    }
    return false;
}

void row_WiseSum(int arr[][4],int row)
{
    for (int i = 0;i < row;i++)
    {
        int sum = 0;
        for (int j = 0;j < 4;j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum row " << i+1 << " = " << sum << endl;
    }
}


void col_WiseSum(int arr[][4],int row)
{
    for (int i = 0;i < 4;i++)
    {
        int sum = 0;
        for (int j = 0;j < row;j++)
        {
            sum += arr[j][i];
        }
        cout << "Sum Col " << i+1 << " = " << sum << endl;
    }
}

void largestSum(int arr[][4],int size)
{
    int max = INT16_MIN;
    int col = 0,row = 0;
    //row Wise Traversal;
    for (int i = 0;i < size;i++)
    {
        int sum = 0;
        for (int j = 0;j < 4;j++)
        {
            sum += arr[i][j];
        }
        if (sum > max)
        {
            max = sum;
            row = i;
            col = -1;
        }
    }

    //column wise traversal;
    for (int i = 0;i < 4;i++)
    {
        int sum = 0;
        for (int j = 0;j < size;j++)
        {
            sum += arr[j][i];
            
        }
        if (sum > max)
        {
            max = sum;
            col = i;
            row = -1;
        }
    }

    cout << "maximum sum = " << max;
    if (col != -1)
    {
        cout << " of column " << col + 1 << endl;
    }
    else
        cout << " of row " << row + 1 << endl;

}

void leastSum(int arr[][4],int size)
{
    int min = INT16_MAX;
    int col = 0,row = 0;
    //row Wise Traversal;
    for (int i = 0;i < size;i++)
    {
        int sum = 0;
        for (int j = 0;j < 4;j++)
        {
            sum += arr[i][j];
        }
        if (sum < min)
        {
            min = sum;
            row = i;
            col = -1;
        }
    }

    //column wise traversal;
    for (int i = 0;i < 4;i++)
    {
        int sum = 0;
        for (int j = 0;j < size;j++)
        {
            sum += arr[j][i];
            
        }
        if (sum < min)
        {
            min = sum;
            col = i;
            row = -1;
        }
    }

    cout << "minimum sum = " << min;
    if (col != -1)
    {
        cout << " of column " << col + 1 << endl;
    }
    else
        cout << " of row " << row + 1 << endl;

}

void wavePrint(int arr[][4],int row)
{
    int i = 0;
    while (i < 4)
    {
        //going down when i is even
        if ( i % 2 == 0)
        {
            for (int j = 0;j < row;j++)
            {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
        //going up when i is odd
        else
        {
            for (int j = row - 1;j >= 0;j--)
            {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
        i++;
    }
    return;
}

void spiralPrint(int arr[][4],int row)
{
    int count = 0;
    int Total = row * 4;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = 2;
    int endingCol = 3;

    while (count < Total)
    {
        for (int i = startingCol;i <= endingCol && count < Total;i++)
        {
            cout << arr[startingRow][i] << " ";
            count++;
        }    
        startingRow++;

        for (int i = startingRow;i <= endingRow && count < Total;i++)
        {
            cout << arr[i][endingCol] << " ";
            count++;
        }
        endingCol--;

        for (int i = endingCol;i >= startingCol && count < Total;i--)
        {
            cout << arr[endingRow][i] << " ";
            count++;
        }    
        endingRow--;

        for (int i = endingRow;i >= startingRow && count < Total;i--)
        {
            cout << arr[i][startingCol] << " ";
            count++;
        }    
        startingCol++;        
    }
}

void rotate90_(int arr[][4],int row)
{
    int count = 0;
    int Total = row * 4;
    int startingCol = 0;
    int startingRow = 0;
    int endingRow = row - 1;
    int endingCol = 3;

    while (count < Total)
    {
        int i;
        int temp;


        if (count < Total)
            temp = arr[startingCol][startingRow];
        for (i = startingCol;i < endingCol && count < Total;i++)
        {
            arr[startingRow][i] = arr[startingRow][i+1];
            count++;
        }
        if (count < Total)
        {
            arr[startingRow][i] = arr[startingRow+1][i];
            startingRow++;
            count++;
        }



            
        // startingRow++;
        cout << count << endl;

        cout << "After 1\n";
        printArr(arr,4);

        for (i = startingRow;i < endingRow && count < Total;i++)
        {
            arr[i][endingCol] = arr[i+1][endingCol];
            count++;
        }
        if (count < Total)
        {
           arr[i][endingCol] = arr[i][endingCol-1];
            endingCol--;
            count++;
        }    
        cout << count << endl;

        cout << "After 2\n";
        printArr(arr,4);

        
        for (i = endingCol;i > startingCol && count < Total;i--)
        {
            arr[endingRow][i] = arr[endingRow][i-1];
            count++;
        }
        if (count < Total)
        {
            arr[endingRow][i] = arr[endingRow-1][i];
            endingRow--;
        }
            
        cout << count << endl;
        cout << "After 3\n";
        printArr(arr,4);
        
        for (i = endingRow;i > startingRow && count < Total;i--)
        {
            arr[i][startingCol] = arr[i-1][startingCol];
            count++;
        }
        if (count < Total)
        {
            arr[i][startingCol] = temp;
            startingCol++;
            count++;
        }
            
        
        cout << count << endl;

        cout << "After 4\n";
        printArr(arr,4);
        // break;
    }

}

void rotate90_1(int arr[][4],int row)
{
    int temp[row][4];
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            temp[row - j -1][i] = arr[i][j];
        }
    }
    cout << "After Rotation : \n";
    printArr(temp,4);
}

void rotate90_2(int arr[][4],int row)
{
    //transpose of matrix;
    for (int i = 0;i < row;i++)
        for (int j = i;j < 4;j++)
            swap(arr[i][j],arr[j][i]);
    
    //reversing column;
    int column = 0,i = 0,j = 0;
    while (column < 4)
    {
        i = 0,j = row - 1;
        while (i < j)
        {
            swap(arr[i][column],arr[j][column]);
            i++;
            j--;
        }
        column++;
    }
      
}

void rotate90_3(int arr[][4],int row)
{
    for (int i = 0;i < row/2;i++)       //no of squarre
        for (int j = i;j < 3;j++)   
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][row-i-1];
            arr[j][row-i-1] = arr[row-i-1][row-j-1];
            arr[row-i-1][row-j-1] = arr[row-j-1][i];
            arr[row-j-1][i] = temp;
        }
}


bool binarySearch(int arr[][4],int row,int target)
{
    int start = 0;
    int end = row*4 - 1;
    int mid = start + (end - start)/2;
    while (start < end)
    {
        int i = mid/4;  //mid/col    // row index;
        int j = mid%4;  //mid%col    // col index;

        if (arr[i][j] == target)
        {
            return true;
        }
        else if (arr[i][j] < target)
            start = mid + 1;
        else    
            end = mid - 1;
        
        mid = start + (end - start)/2;
    }

    return false;
}

bool binarySearchAdvance(int arr[][4],int row,int target)
{
    int i = row - 1;
    int j = 4 - 1;  //column - 1;
    while (i >= 0 && j >= 0 && i < row && j < 4)
    {
        if (arr[i][j] == target)
            return true;
        else if (arr[i][j] < target)
            i++;
        else    //arr[i][j] > target
            j--;
    }
    return false;
}