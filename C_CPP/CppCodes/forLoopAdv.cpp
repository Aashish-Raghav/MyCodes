// ?ate print all words till you reach a word starting with user choice

#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    string inputWord;
    string word = "?ate";
    cout << "Enter a word(?ate) : "; getline(cin,inputWord);
    for (char ch = 'a';inputWord != word;ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends,word is " << word << endl;
    return 0;
}