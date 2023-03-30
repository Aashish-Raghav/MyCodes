#include<iostream>
#include<cctype>
int main() 
{
    using namespace std;
    cout << "Enter Words (q alone to quit) : \n";
    string word;
    (cin >> word).get();
    int vstart=0,cstart=0,other=0;  //vowel start,consonant start,others;
    while (word != "q" && word != "Q")
    {
        char ch = word[0];
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vstart++;
            else cstart++;
        } else other++;
        (cin >> word).get();
        //cout << word;
    }
    cout << vstart << " words beginning with vowels\n";
    cout << cstart << " words beginning with constants\n";
    cout << other << " others";
    return 0;
}
