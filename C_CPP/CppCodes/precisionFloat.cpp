// float precision is upto 6 - 7 digits (6);
// double precision is upto 15 digits;

#include<iostream>
const int Months = 12;
int main() 
{
    using namespace std;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    float tub;
    double mint;
    tub = 10.0/3.0;
    mint = 10.0/3.0;
    const float Million = 1e6;

    cout << "tubs : " << tub << endl;
    cout << "a million tubs : " << tub * Million << endl;
    cout << " a ten million tubs : " << tub * 10 * Million << endl << endl;

    cout << "mint : " << mint << endl;
    cout << "a million mint : " << mint * Million << endl;
    cout << " a ten million mint : " << mint * Million * 10 << endl;
    return 0;
}
