#include<iostream>
const double SecToMin = 60;
const double MinToDeg = 60;

int main() 
{
    using namespace std;
    //cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    int deg,min,sec;
    cout << "First, enter the degrees: "; cin >> deg;
    cout << "Next, enter the minutes of arc: "; cin >> min;
    cout << "Finally, enter the seconds of arc: "; cin >> sec;
    cout << deg << " degrees, " << min << " minutes, " << sec << "seconds = " << deg + (min + (double (sec)/SecToMin))/MinToDeg; 
    return 0;
}