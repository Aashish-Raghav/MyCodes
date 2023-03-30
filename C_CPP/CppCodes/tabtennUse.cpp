#include<iostream>
#include "tabtenn.h"

int main()
{
    using std::cout;
    using std::endl;
    ttp player1("Tara","Boomdea",false);
    rp rplayer1(1140,"Mallory","Duck",true);
    rplayer1.Name();
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else 
        cout << ": hasn't a table.\n";
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;
    rp rplayer2(1212,player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}