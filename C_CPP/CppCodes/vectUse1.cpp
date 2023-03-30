//random walk in file;
#include<iostream>
#include<cstdlib>       //rand();
#include "vect.h"
#include<fstream>

int main()
{
    using namespace std;
    using VECTOR::Vector;

    ofstream fout;
    const char * fn = "VectResult.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << "\nBye\n";
        exit(EXIT_FAILURE);
    }

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

        fout << "Target Distance: " << target << ", "
             << "Step Size " << dstep << endl;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            fout << steps <<": " << result << endl;
            steps++;
        }
        fout << "After " << steps << " steps, the subject "
                "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << "or\n" << result << endl;
        fout << "Average outward distance per step = "
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
