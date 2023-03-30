//converesion inches into feet and inches;
#include<iostream>
const int Factor = 12;

int main() 
{
    using namespace std;
    cout << "Enter height in Inches : _____\b\b\b\b\b";
    int height;
    cin >> height;
    cout << "Your Height : " << height / Factor << " feet " << height % Factor << " inches" << endl;
    return 0;
}