//permutation and combination;
#include<iostream>
long double comb(int,int);
long double perm(int,int);
long double factorial(int);
int main()
{
    using namespace std;
    int a,b;
    cout << "Enter two integers (a C b) (first a & then b) : ";cin >> a >> b;
    cout << "Combination is : " << comb(a,b) << endl;
    cout << "Permutation is : " << perm(a,b);
    return 0;
}

long double comb(int a,int b) {         //bCa;
    long double result = 1;
    for (int i = a,j = b;j>=0;i--,j--){
        result = result * a/b;              //this form is impt since it saves extra processing;
    }                                       // can be factorial(a)/factorial(b) but not efficient;
    return result;
}

long double factorial(int num){
    long double result = 1;
    for (int i = 1;i <= num;i++)
    {
        result *= i;
    }
    if (num == 0) return 1;
    return result;
}

long double perm(int a,int b){
    return (comb(a,b) * factorial(b));
}
