#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    string str;
    cout << "Enter a string : \n"; getline(cin,str);
    int flag = 0;
    for (int i = str.size()-1,j=0;i>j;i--,j++)
    {
        if (str[i] == str[j]);
        else {
            flag = 1;
            break;
        }
    }
    if (flag == 0) cout << "\nPallidrome :)";
    else cout << "\nNot Pallidrome :(";

    return 0;
}