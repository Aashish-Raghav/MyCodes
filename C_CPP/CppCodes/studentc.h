#ifndef STUDENTC_H_
#define STUDENTC_H_

#include<iostream>
#include <string>
#include <valarray>
class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores; 
    std::ostream & arr_out(std::ostream & os) const;
public:
    Student() : name("Null Student"),scores() {}    //default constructor   
    explicit Student(const std::string & s) : name(s),scores() {}   // consversion constructor from string to student object
    explicit Student(int n) : name("Nully"),scores(n) {} //conversion constructor from int to Student object
    Student(const std::string & s,int n) : name(s), scores(n) {} // explicit constructor
    Student(const char * str,const double * pd,int n) : name(str), scores(pd,n) {} // explicit constructor
    ~Student() {}   ///destructor;

    double Average() const;
    const std::string & Name() const;
    double & operator[] (int i);    // allow accessing and changing individual element of array
    double operator[](int i) const; //allow only accessing no altering

    //friends
    friend std::istream & operator>>(std::istream & is,Student & stu);  //read only 1 word
    friend std::istream & getline(std::istream & is,Student & stu);     // read 1 line

    friend std::ostream & operator<<(std::ostream & os,Student & stu);
};
#endif