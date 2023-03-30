#include<iostream>
#include<cctype>
int main() 
{
    using namespace std;
    char ch;
    cout << "Type character,(@ to end) : \n";
    while (cin.get(ch) && ch != '@')
    {
        if (!isdigit(ch)) {
            if (islower(ch)) cout << (char) toupper(ch);
            else if (isupper(ch)) cout <<(char) tolower(ch);
            else cout << ch;
        }
    }

    return 0;
}
