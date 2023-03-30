#include<iostream>
using namespace std;
string version1(string,string);
string & version2(string &,const string &);     // here used the reference variable;

int main() 
{
    using namespace std;
    cout << "Enter Your string : ";
    string str,result;
    getline(cin,str);
    cout << "\n VERSION 1\n";
    // cout << (unsigned int) &str << endl;
    result = version1(str,"!!!!");
    cout << "Original String : " << str << endl;
    cout << "Modified String : " << result << endl;
    result = version2(str,"@@@@");
    cout << "\n VERSION 2 \n";
    cout << "Original string : " << str << endl;
    cout << "Modified String : " << result << endl;

    return 0;
}

string version1(string s1,string s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}
string & version2(string & s1,const string & s2){
    s1 = s2 + s1 + s2;
    return s1;
}
