#include<iostream>
#include<cctype>        //toupper();
#include<cstring>       //size()

void uppercase(std::string &);
int main() 
{
    using namespace std;
    string str;
    cout << "Enter a string(q to quit) : ";
    getline(cin,str);
    while(str != "q"){
        uppercase(str);
        cout << "Enter a string(q to quit) : ";
        getline(cin,str);
    }
    return 0;
}
void uppercase(std::string & str){
    int n = str.size();
    for (int i = 0;i < n;i++){
        std::cout << (char) toupper(str[i]);
    }
    std::cout << std::endl;
}