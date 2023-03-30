#include<iostream>
#include "string.h"
#include<cstdlib>
#include<ctime>

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;    //object 1;
    cout << "hi, what's your name?\n>> ";
    cin >> name;
    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit> :\n";
    String sayings[ArSize];     // object 10        total 11 object;
    char temp[MaxLen];
    int i;
    for (i = 0;i < ArSize;i++)
    {
        cout << i+1 << ": ";
        cin.get(temp,MaxLen);
        while (cin && cin.get() != '\n')        // to end the sentence longer than MaxLen;
            continue;
        if (!cin || temp[0] == '\0')    //check empty line (!cin is self sufficient;)
            break;
        else 
            sayings[i] = temp;          //overloaded assignment
    }
    int total = i;      //total lines read;

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (int i = 0;i < total;i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;

        String * shortest = &sayings[0];
        String * first = & sayings[0];

        for (int i =0;i < total;i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first) 
                first = &sayings[i];
        }

        cout << "Shortest saying :\n" << *shortest << endl;
        cout << "First Alphabetically :\n" << *first << endl;

       // srand(time(0));
        int choice = rand() % total;
        cout <<endl << choice << endl;
        String *favorite = new String(sayings[total]);
        cout << "My favorite saying :\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "No Input! Bye.\n";

    return 0;
}