#include<iostream>
#include"stone.h"

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = lbs - (int (lbs)) + (int (lbs) % Lbs_per_stn);
    pounds = lbs;
}

Stonewt::Stonewt(int stn,double lbs)
{
    stone = stn;
    pounds = lbs + stn*Lbs_per_stn;
    pds_left = lbs;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_lbs() const
{
    std::cout << pounds << " pounds\n";
}

void Stonewt::show_stn() const
{
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt Stonewt::operator*(double n)
{
    Stonewt(pounds * n);
}

Stonewt operator*(double n,const Stonewt & st)
{
    return Stonewt(st.pounds * n);
}

Stonewt::operator int() const
{
    return (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}