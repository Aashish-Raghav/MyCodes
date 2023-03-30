#include<iostream>
int main() 
{
    using namespace std;
    long double wpop,ipop;      //using long double here so as to get fractional part in divison
    cout << "Enter the world's population: "; cin >> wpop;
    cout << "Enter the population of the India : "; cin >> ipop;
    cout << "The population of the India is " << ipop/wpop *100 << '%' << " of the world population.\n";
    // % sign using character;
    cout << "The population of the India is " << ipop/wpop *100 << " \u0025 of the world population.";
    // % sign using unicode ;
    return 0;
}