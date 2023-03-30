#include<iostream>
#include<cstring>
std::string reverse(std::string);
int main() 
{
    using namespace std;
    string str,newStr;
    cout << "Enter a string wonna reverse : "; getline(cin,str);
    newStr = reverse(str);
    cout << "Your Reversed string : " << newStr;
    return 0;
}

std::string reverse(std::string str)
{
    char temp;          //temporary character;
    for (int i = str.size()-1,j = 0;i>j;i--,j++)    //using single int two declare two i and j 
    {                                               // can't use two int together no need***
        temp = str[i];                              //better way if two variable declare outside loop and use;
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}