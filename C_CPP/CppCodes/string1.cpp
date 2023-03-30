#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;                // simple declaration as other variable unlike array
    string str2 = "panther";    // no need to define the size of string.

    cout << "Enter other kind of feline : "; cin >> charr1;
    cout << "Enter another kind of feline : "; cin >> str1;         //use cin to input string. resizing of string.

    cout << "Here are some felines: \n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << "\n";     // use cout to output string.

    cout << "Third character in " << charr2 << " is " << charr2[2] << endl;     
    cout << "Third character in " << str2 << " is " << str2[2] << endl;     //access(indexing) string elements as array
    return 0;
}