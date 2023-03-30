#include<iostream>
const int HinD = 24;   //HinD : hours in day
const int MinH = 60;   //MinH : minutes in hour
const int SinM = 60;   //SinM : seconds in minutes

int main()
{
    using namespace std;
    long long sec;
    cout << "Enter the numbers of seconds : "; cin >> sec;
    int day,hour,min,second;
    min = sec / SinM;
    second = sec %SinM;
    hour = min / MinH;
    min = min % MinH;
    day = hour / HinD;
    hour = hour % HinD;
    cout << sec << " seconds = " << day << " days, " << hour << " hours, " << min << " minutes, " << second << " seconds";
    return 0;
}