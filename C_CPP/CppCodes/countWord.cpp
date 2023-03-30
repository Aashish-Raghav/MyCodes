// cout words until user input "done";

// importance of cin >> ch;
// how differ from cin.get(ch,20);


#include<iostream>
#include<cstring>
int main() 
{
    using namespace std;
    //using array of character;
    /*
    char word[5] = "done";
    char ch[20];
    cout << "Enter words (to stop,type the word done) : ";
    (cin >> ch).get();          //*********
    int count = 0;
    while (strcmp(ch,word))
    {
        count++;
        (cin >> ch).get();      //*****8
    }
    cout << "You entered a total of " << count << " words.";
    */

    //using string;
    /*
    string ch,word = "done";
    cout << "Enter words (to stop,type the word done)";
    (cin >> ch).get();
    int count = 0;
    while(ch != word) 
    {
        count++;
        (cin >> ch).get();
    }
    */
    return 0;
}