#include"CD.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

Cd::Cd(const char * s1,const char * s2,int n,double x)
{
    performance = new char[strlen(s1) + 1];
    strcpy(performance,s1);
    label = new char[strlen(s2) + 1];
    strcpy(label,s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performance = new char[strlen(d.performance) + 1];
    strcpy(performance,d.performance);
    label = new char[strlen(d.label) + 1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::~Cd() 
{
    delete [] performance;
    delete [] label;
}

void Cd::Report() const
{
    cout << "Performance : " << performance << endl;
    cout << "Label : " << label << endl;
    cout << "Selections : " << selections << endl;
    cout << "Playtime : " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    performance = new char[strlen(d.performance) + 1];
    strcpy(performance,d.performance);
    label = new char[strlen(d.label) + 1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Classic Methods;
Classic::Classic(const char * s, char * s1,char * s2,
                    int n,double x) : Cd(s1,s2,n,x)
{
    identity = new char[strlen(s) + 1];
    strcpy(identity,s);
}

Classic::Classic(const char* s,const Cd & d) : Cd(d)
{
    identity = new char[strlen(s) + 1];
    strcpy(identity,s);
}

Classic::~Classic() {}

void Classic::Report () const
{
    cout << "Identity : " << identity << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c)
{
    Cd::operator=(c);
    identity = c.identity;
    return *this;
}