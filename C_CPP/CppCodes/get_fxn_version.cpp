#include<iostream>
int main() 
{
    using namespace std;
    //cin.get(arr,ArSize);
    char arr[20];
    cout << "Enter an Array : ";cin.get(arr,20);
    cout << "Your array : " << arr << endl;
    cin.get();

    //cin.get(char);
    char ch;
    cout << "Enter an character : ";cin.get(ch);
    cout << "You entered : " << ch << endl;
    cin.get();

    //ch = cin.get();
    char ch1;
    cout << "Enter an character : "; ch1 = cin.get();
    cout << "you entered : " << ch1 << endl;
    cin.get();

    //cin.get()'
    cout << "press enter key : ";cin.get();

    return 0;
}