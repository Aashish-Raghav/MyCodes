#include <iostream>
#include "TV.h"

int main()
{
    using std::cout;
    Tv sony;
    cout << "Intial settings of sony TV : \n";
    sony.settings();
    sony.onoff();
    sony.chanup();
    cout << "\nAdjusted settings for sony TV: \n";
    sony.settings();

    Remote grey;
    grey.set_chan(sony,10);
    grey.volup(sony);
    grey.volup(sony);
    cout << "sony TV settings after using remote:\n";
    sony.settings();

    Tv apple(Tv::On);
    apple.set_mode();
    grey.set_chan(apple,28);
    cout << "Apple TV settings:\n";
    apple.settings();

    return 0;
}