#include <iostream>
#include "TV.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else 
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else 
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume settings = " << volume << endl;
        cout << "Channel settings = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna? "Antenna" : "Cable") << endl;
        cout << "Input = "
             << (input == TV ? "TV" : "DVD") << endl;
    }
}