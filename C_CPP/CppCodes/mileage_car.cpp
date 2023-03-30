#include<iostream>
int main() 
{
    using namespace std;
    double dis,petrol;
    cout << "Enter distance in kilometers : "; cin >> dis;
    cout << "Enter petrol consumed : "; cin >> petrol;
    cout << petrol/dis * 100 << " litres per 100 kilometres.\n"; 
    return 0;
}