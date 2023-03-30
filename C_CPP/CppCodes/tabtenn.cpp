#include "tabtenn.h"
#include<iostream>

ttp::ttp(const string & fn,const string & ln,
         bool ht) : firstname(fn) , lastname(ln),
         hasTable(ht) {}
void ttp::Name() const
{
    std::cout << lastname << ", " << firstname;
}

rp::rp(unsigned int r,const string & fn,
       const string & ln,bool ht) : ttp(fn,ln,ht)
{
    rating = r;
}

rp::rp(unsigned int r,const ttp & tp) : ttp(tp)
{
    rating = r;
}