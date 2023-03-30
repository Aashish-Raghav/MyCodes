#include"mytime.h"

Time::Time()
{
    hours_ = minutes_ = 0;
}

Time::Time(int hr,int m)
{
    hours_ = hr;
    minutes_ = m;
}

void Time::AddMin(int m)
{
    minutes_ += m;
    hours_ += minutes_/60;
    minutes_ %= 60;
}

void Time::AddHr(int h)
{
    hours_ += h;
}

void Time::Reset(int h,int m)
{
    minutes_ = m;
    hours_ = h;
    hours_ += minutes_/60;
    minutes_ %= 60;
}

Time Time::Sum(const Time & t) const
{
    Time sum;
    sum.minutes_ = t.minutes_ + this->minutes_;
    sum.hours_ = t.hours_ + this->hours_;
    sum.hours_ += sum.minutes_ / 60;
    sum.minutes_ %= 60;
    return sum;
}
Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes_ = t.minutes_ + this->minutes_;
    sum.hours_ = t.hours_ + this->hours_;
    sum.hours_ += sum.minutes_ / 60;
    sum.minutes_ %= 60;
    return sum;
}

Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1,tot2;
    tot1 = (this->hours_)* 60 + this->minutes_;
    tot2 =  t.hours_ * 60 + t.minutes_;
    diff.minutes_ = (tot1 - tot2) % 60;
    diff.hours_ = (tot1 - tot2) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long tmin = hours_* 60 * mult + minutes_ * mult;  //tmin = total minutes;
    result.hours_ = tmin / 60;
    result.minutes_ = tmin % 60;  
    return result;
}

Time operator*(double mult,const Time & t)
{
    return t * mult;
}

std::ostream & operator<<(std::ostream & os,const Time & t)
{
    os << t.hours_ << " hours, " << t.minutes_ << " minutes"; 
    return os;
}

void Time::Show() const
{
    std::cout << hours_ << " hours, " << minutes_ << " minutes";
}
