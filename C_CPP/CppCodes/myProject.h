#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person  // an Abstract Base Class
{
private:
    std::string name;
    int age;
public:
    Person() : name("NULL"),age(0) {}
    Person(const std::string & s,int a) : name(s),age(a) {}
    virtual ~Person() = 0;  // a pure virtual fxn;
    virtual void add();
    virtual void remove();
    virtual void display();
    virtual void search() const;
    virtual void update();
};

class Student : public Person       //is a relationship
{
private:
    std::string school;
    double percentile;
    int cur_id;
public:
    Student() : Person(),school("NULL"),percentile(0) {}
    Student(const std::string & s,int a,std::string & sch,
                double p) : Person(s,a),school(sch),percentile(p) {}
    virtual ~Student() {}
    virtual void add();
    virtual void remove();
    virtual void display();
    virtual void search() const;
    virtual void update();
};

class Teacher : public Person       //is a relationship
{
private:
    std::string school;
    int experience;
    int cur_id;
public:
    Teacher() : Person(),school("NULL"),experience(0) {}
    Teacher(const std::string & s,int a,std::string & sch,
                int e) : Person(s,a),school(sch),experience(e) {}
    virtual ~Teacher() {}
    virtual void add();
    virtual void remove();
    virtual void display();
    virtual void search() const;
    virtual void update();
};

#endif