#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker        // an abstract base class
{
private:
    std::string name;
    long id;
public:
    Worker() : name("no one"), id(0L) {};   //0L means long 0;
    Worker(const std::string & s,long n) : name(s),id(n) {}
    virtual ~Worker() = 0;  //pure virtual fxn;
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker
{
private:
    int panache;
public:
    Waiter() : Worker(),panache(0) {};
    Waiter(const std::string & s,long n,int p = 0) : Worker(s,n),panache(0) {}
    Waiter (const Worker & wk,int p = 0) : Worker(wk),panache(p) {};
    virtual void Set();
    virtual void Show() const;
};

class Singer : public Worker
{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes = 7};       //OR const int Vtypes = 7;
private:        
    static char *pv[Vtypes];    //string equivs of voice types;
    int voice;
public:
    Singer() : Worker(),voice(other) {}
    Singer(const std::string & s,long n,int v = other) : Worker(s,n),voice(v) {}
    virtual void Set();
    virtual void Show();
};
#endif