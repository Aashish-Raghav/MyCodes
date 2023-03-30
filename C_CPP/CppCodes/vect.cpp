#include<cmath>
#include"vect.h"

using std::sin;
using std::cos; 
using std::atan2;   //atan2(y,x);
using std::atan;    //atan(mag);
using std::sqrt;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45/atan(1.0);
    // roughly = 57.3  (1 deg to rad);

    //private methods
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    void Vector::set_ang()
    {
        if (x == 0 && y == 0) ang = 0;
        else ang = atan2(y,x);
    }

    void Vector::set_mag()
    {
        mag = sqrt(x*x + y*y);
    }


    //public methods
    Vector::Vector()        //default constructor;
    {
        x = y = mag = ang = 0;
        mode = RECT;
    }

    Vector::Vector(double n1,double n2,Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1; 
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL)
        {
            mag = n1; 
            ang = n2/Rad_to_deg;  
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1,double n2,Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1; 
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == POL)
        {
            mag = n1; 
            ang = n2/Rad_to_deg;  
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    Vector::~Vector()       //destructor;
    {
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }


    //operator overloading;
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(this->x + b.x,this->y + b.y);      //using constructor in return; WOW******
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(this->x - b.x,this->y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n*x,y*n);
    }

    
    //friends method;
    Vector operator*(double n,const Vector & b)
    {
        return b*n;
    }

    //display rect coordinate if mode is RECT;
    // and polar coordinate if mode is POL;

    std::ostream & operator<<(std::ostream & os,const Vector & b)
    {
        if (b.mode == Vector::RECT)
        {
            os << "(x,y) = (" << b.x << "," << b.y << ")";
        }
        else if (b.mode == Vector::POL)
        {
            os << "(m,a) = (" << b.mag << "," << b.ang * Rad_to_deg << ")";
        }
        else 
            os << "Vector object mode is invalid";
        return os;
    }

    Vector::operator double() const
    {
        return mag;
    }

}   // end namespace VECTOR