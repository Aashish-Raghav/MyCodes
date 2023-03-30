#include<iostream>
char* buildstr(char c,int n);
int main() 
{
    using namespace std;
    char ch;
    cout << "Enter an character : "; cin >> ch;
    int times;
    cout << "Enter an integer : "; cin >> times;
    char *ps = buildstr(ch,times);
    cout << ps << endl;
    delete [] ps;
    ps = buildstr('+',20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;

    return 0;
}
char* buildstr(char c,int n) {
    char* pstr = new char[n+1];     //created a pointer to array of characters;
    pstr[n] = '\0';             //created a pointer to C type string; (since added \0);
    while (n-- >0){
        pstr[n] = c;
    }
    return pstr;
}