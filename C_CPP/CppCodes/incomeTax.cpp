#include<iostream>
const double tax1 = 10000 * 0.1;        // tax on first 15k
const double tax2 = tax1 + 20000 * 0.15;    // tax on first 35k
int main() 
{
    using namespace std;
    int income;
    cout << "Enter your income : _____\b\b\b\b\b";
    int tax;
    while (cin >> income && income >=0) {
        if (income > 35000) tax = (income - 35000) * 0.2 +  tax2;
        else if (income > 15000) tax = (income - 15000) * 0.15 + tax1;
        else if (income > 5000) tax = (income - 5000)*0.1 ;
        else  tax = 0;
        cout << "Your CTC is : " << income << " travp." << endl;
        cout << "Your Tax : " << tax << " travp." << endl;
        cout << "Your In-hand salary : " << income - tax << " tvarp." <<  endl << endl;
        cout << "Enter your income : ______\b\b\b\b\b";
    }
    return 0;
}
