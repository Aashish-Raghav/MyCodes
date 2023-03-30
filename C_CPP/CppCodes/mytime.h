#ifndef MYTIME_H_
#define MYTIME_H_
#include<iostream>

class Time
{
private:
    int hours_;
    int minutes_;
public:
    Time();
    Time(int h,int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0,int m = 0);
    Time Sum(const Time & t) const;
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const; // mult : multiply
    friend Time operator*(double mult,const Time & t);  //friend is useful when we have to switch the value which comes first;
    friend std::ostream & operator<<(std::ostream & os,const Time & t);
    void Show() const;
};

#endif