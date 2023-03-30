//random walk;
#include<iostream>
#include<cstdlib>       //rand();
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;

    double direction;
    unsigned long steps = 0;
    double target;
    double dstep;
    Vector result;
    Vector step;
    cout << "Enter target distance (q to quit) : ";
    while (cin >> target)
    {
        cout << "Enter Step Length : ";
        if (!(cin >> dstep)) break;
        
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << "or\n" << result << endl;
        cout << "Average outward distance per step = "
             << result.magval()/steps << endl;
        steps = 0;
        result.reset(0,0);
        cout << "Enter target distance (q to quit) : ";
    }
    cout << "Bye\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}
