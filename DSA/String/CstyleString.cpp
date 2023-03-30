#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

void printArr(int arr[],int size);
void printArr(char arr[]);  //no more needed;
int getlength(char arr[]);

void reverse(char arr[]);             

bool isPallidromeBasic(char arr[]);   
bool isPallidromeAdvance(char arr[]);


void reverseWords(char*);           
void reverseOne(char* arr,int start,int end);

int max_(int arr[],int size = 26);
char maxOccuChar(char* arr);        


using namespace std;
int main()
{
    char name[20] = "5@3# 63?5";
    // cout << name << endl;

    char arr[100] = "Kajuu Katlu";
    cout.setf(ios_base::boolalpha);
    // cout << "is Pallidrome Basic ? " << isPallidromeBasic(name) << endl;
    // cout << "is Pallidrome Advance? " << isPallidromeAdvance(name) << endl;
    // cout << arr << endl;
    // reverseWords(arr);
    cout << arr << endl;
    char maxi = maxOccuChar(arr);
    cout << "Maximum char is '" << maxi << "'" << endl;
    return 0;
}

void printArr(char arr[])
{
    for (int i = 0;arr[i] != '\0';i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArr(int arr[],int size)
{
    for (int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getlength(char arr[])
{
    int count = 0;
    for (int i = 0;arr[i] != '\0';i++)
    {
        count++;
    }
    return count;
}

void reverse(char arr[])
{
    for (int i = 0,n = getlength(arr) - 1;i < n;i++,n--)
        swap(arr[i],arr[n]);
    return;
}

bool isPallidromeBasic(char arr[])
{
    for (int i = 0,j = getlength(arr) -1; i < j;i++,j--)
    {
        if (arr[i] != arr[j])
            return false;
    }
    return true;
}

bool isPallidromeAdvance(char arr[])
{
    for (int i = 0,j = getlength(arr) -1;i < j;i++,j--)
    {
        if (isalnum(arr[i]) && isalnum(arr[j]))
        {
            if (tolower(arr[i]) != tolower(arr[j]))
                return false;
        }
        else
        {
            if (!isalnum(arr[i]))
                i++;
            else
                j++;
        }
    }
}

void reverseOne(char arr[],int start,int end)
{
    for (int i = start,j = end;i < j;i++,j--)
        swap(arr[i],arr[j]);    
}

void reverseWords(char arr[])
{
    int i = 0;
    int j = 0;
    while (i <= getlength(arr))
    {
        if (arr[i] == ' ' or arr[i] == '\t' or arr[i] == '\n' or arr[i] == '\0')
        {
            reverseOne(arr,j,i-1);
            if (arr[i] == '\0')
                return;
            i++;
            j = i;   
        }
        else
            i++;
    }
}

int max_(int arr[],int size)
{
    int max = 0;
    for (int i = 1;i < size;i++)
        if (arr[i] > arr[max])
            max = i;
    return max;
}

char maxOccuChar(char* arr)
{
    int count[26] = {0};
    for (int i = 0;i < strlen(arr);i++)
    {
        count[tolower(arr[i]) - 'a']++;
    }
    return max_(count,26) + 'a';
    // return  max_(arr,26) + 'a';
}