//peek() peek at next character but do not read it;
//putback(char) puts char in input stream,the next character ready to read;


#include <iostream>
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    char ch;

    while (cin.get(ch))     //checks for EOF;
    {
        if (ch != '#')
            cout << ch;
        else
        {
            cin.putback(ch);        //reinsert # charachter if read before EOF;
            break;
        }
    }

    if (!cin.eof()) //eof() returns true if eofbit is set;
    {
        cin.get(ch); //read reinserted character;
        cout << endl << ch  << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while (cin.peek() != '#')   //looks ahead before reding any character;
    {
        cin.get(ch);
        cout << ch;
    }

    if (!cin.eof()) //eof() returns true if eofbit is set;
    {
        cin.get(ch); //read reinserted character;
        cout << endl << ch  << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
        std::exit(0);
    }
    return 0;
}