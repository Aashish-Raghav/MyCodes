#include<iostream>
#include<cmath>
const int FootToInch = 12;
const double PoundToKg = 2.2;

int main()
{
    using namespace std;
    cout << "Enter Your Height " << endl;
    int feet,inch;
    cout << "Feets : "; cin >> feet;
    cout << "Inches : "; cin >> inch;
    double weight;
    cout << "\nEnter Your weight in pounds : "; cin >> weight;
    double mHeight = (feet*FootToInch + inch) * 0.0254;
    double kgWeight = weight/PoundToKg;
    double bmi = kgWeight/pow(mHeight,2);
    cout << "Your BMI : " << bmi << endl;
    return 0;

}