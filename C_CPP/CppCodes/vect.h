#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;     //stored in rad; //input in deg; // so output;
        Mode mode;
        void set_x();
        void set_y();
        void set_mag();
        void set_ang();
    public:
        Vector();
        Vector(double n1,double n2,Mode form = RECT);
        void reset(double n1,double n2,Mode form = RECT);
        ~Vector();

        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;}
        double angval() const {return ang;}

        void polar_mode();      //set mode to POL;
        void rect_mode();       //set mode to RECT;

        //operator overloading;
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        
        //friends;
        friend Vector operator*(double n,const Vector & b);
        friend std::ostream & operator<<(std::ostream & os,const Vector & v);

        //
        explicit operator double() const;
    };
}


#endif