#ifndef CD_H_
#define CD_H_
class Cd
{
private:
    char* performance;
    char* label;
    int selections;
    double playtime;
public:
    Cd(const char * s1 = "null",const char * s2 = "null",int n  = 0,double x = 0);
    Cd(const Cd & d);
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char* identity;
public:
    Classic(const char* s = "null",char * s1 = "null",char * s2 = "null",int n = 0,double x = 0);
    Classic(const char* s,const Cd & d);
    virtual ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};
#endif