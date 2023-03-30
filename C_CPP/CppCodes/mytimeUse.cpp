#include"mytime.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total1;
    Time total2;
    
    cout << "Planning Time = ";
    planning.Show();
    cout << endl;

    cout << "Coding Time = ";
    coding.Show();
    cout << endl;

    cout << "Fixing Time = ";
    fixing.Show();
    cout << endl;

    total1 = coding.Sum(fixing);
    cout << "Coding.Sum(fixing) : ";
    total1.Show();
    cout << endl;

    total2 = coding + fixing;
    cout << "Coding + Fixing : ";
    total2.Show();
    cout << endl;
    cout << endl;

    Time weeding(4,35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "Weeding Time = ";
    weeding.Show();
    cout << endl;

    cout << "Waxing Time = ";
    waxing.Show();
    cout << endl;

    cout << "Total work time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;

    cout << "Weeding time - waxing time = ";
    diff = weeding - waxing;
    diff.Show();
    cout << endl;

    cout << "Adjusted work time = ";
    adjusted = total * 1.5;     //total.operator*(1.5);
    adjusted.Show();
    cout << endl;

    cout << "Adjusted work time again with friend = ";
    adjusted = 1.5 * total;     //operator*(1.7,total)    friend fxn;
    adjusted.Show();
    cout << endl;

    cout << "using cout instead of Show() to display\n";
    cout << "weeding + waxing = " << weeding + waxing;
    cout << endl;
    return 0;
}