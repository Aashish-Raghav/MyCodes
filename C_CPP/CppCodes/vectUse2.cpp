//random walk with highest av low;
#include<iostream>
#include<cstdlib>       //rand();
#include "vect.h"
#include<climits>

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
    unsigned long lsteps=LONG_MAX,hsteps=0,asteps=0; //lowest,highest and average;
    int num;
    cout << "Enter target distance (q to quit) : ";
    while (cin >> target)
    {
        cout << "Enter Step Length : ";
        if (!(cin >> dstep)) break;

        cout << "Enter number of trial : ";
        cin >> num;
        for (int i = 0; i < num; i++)        
        {   
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep,direction,Vector::POL);
                result = result + step;
                steps++;
            }
            if (steps < lsteps) lsteps = steps;
            if (steps > hsteps) hsteps = steps;
            asteps += steps;
            steps = 0;
            result.reset(0,0);
        }
        cout << "The following are the results";
        cout << "Highest step : " << hsteps << endl;
        cout << "Lowest step : " << lsteps << endl;
        cout << "Average step : " << asteps / num << endl;
        cout << "Enter target distance (q to quit) : ";
    }
    cout << "Bye\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
    
}
