//HangMan game;
//string methods;
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using std::string;
const int BADNUM = 6;
const int NUM = 26;
const string WordList[NUM]= {"apiary","beetle","cereal",
    "danger","ensign","florid","garage","health","insult",
    "jackal","keeper","loaner","manage","nonce","onset",
    "plaid","quilt","remote","stolid","train","useful"
    "valid","whence","xenon","yearn","zippy"};

int main()
{
    using std::cin;using std::cout;using std::endl;
    std::srand(std::time(0));
    cout << "Will You play a word game? <y/n> ";
    char choice;
    cin >> choice;
    while (tolower(choice) == 'y')
    {
        string target = WordList[rand() % NUM];
        int length = target.size();
        string attempt(length,'-');
        string badchars;
        int numGuess = 6;
        cout << "Guess my secret word. It has " << length << " letters"
                ", and you guess\none letter at a time."
                "You get " << BADNUM << " wrong guesses.\n";
        while((attempt != target) && numGuess > 0)
        {
            cout <<  "Your Word : " << attempt << endl;
            cout << "Guess a letter : ";
            char guess;
            (cin >> guess).get();   // read the \n character;
            if ((badchars.find(guess) != string::npos) 
                    || (attempt.find(guess) != string::npos))
            {
                cout << "You already guessed that. Try Again";
                    continue;
            }
            if (target.find(guess) == string::npos)
            {
                cout << "Oh,bad guess:\n";
                --numGuess;
                badchars += guess;
            }
            else
            {
                cout << "Good guess!";
                unsigned int loc = target.find(guess);
                while (loc != string::npos)
                {
                    attempt[loc] = guess;
                    loc = target.find(guess,loc+1);
                }
            }
            cout << "Your word : " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad Choices: " << badchars << endl;
                cout << numGuess << " bad guesses left\n";
            }
        }
        if (numGuess > 0) 
            cout << "That's right" << endl;
        else 
            cout << "Sorry, the word is " << target << endl;

        cout << "Will you play another? <y/n> ";
        cin >> choice;
    }

    cout << "\nBye!\n";
    return 0;
    
}