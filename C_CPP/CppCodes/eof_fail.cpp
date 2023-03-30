#include<iostream>
int main() 
{
    using namespace std;
    cout << "Enter character, enter EOF to exit : ";
    char ch;
    int count = 0;
    cin.get(ch);
    while (cin.fail() == false) // or (!cin.fail()) or (!cin.eof())  or cin.get(ch) simply
    {                           //EOF checking i.e., <CTRL>+<Z> and enter if inputting from keyboard;
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cin.get(ch);            // we can't input once cin.fail is set to false
    cin.get(ch);            // to input have to set sin.clear() which will reset all the values;
    cout << endl << count << " character read.";
    cin.clear();
    cin.get(ch);            // these take input from stdin or say keyboard;
    cin.get(ch);
    cout << endl << count << " character read.";

    return 0;
}