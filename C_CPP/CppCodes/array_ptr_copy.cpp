#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    char arr1[] = "buddy";
    char *parr1;
    //simple copy;
    parr1 = arr1;
    cout << "value : " << arr1 << " address : " << (int *) arr1 << endl;        //int* means pointer and asking for 
    cout << "value : " << parr1 << " address : " << (int *) parr1 << endl;      //address of first value stored at variable animal

    //cin >> arr1;
    //cout << "value : " << arr1 << " address : " << (int *) arr1 << endl;    //changes in array are reflected in pointer not vice versa;
    //cout << "value : " << parr1 << " address : " << (int *) parr1 << endl; 

    //True copy;
    parr1 = new char[strlen(arr1) + 1];
    strncpy(parr1,arr1,strlen(arr1) + 1);
    parr1[strlen(arr1) + 1] = '\0';
    cout << "value : " << arr1 << " address : " << (int *) arr1 << endl;
    cout << "value : " << parr1 << " address : " << (int *) parr1 << endl;    
    return 0;
}