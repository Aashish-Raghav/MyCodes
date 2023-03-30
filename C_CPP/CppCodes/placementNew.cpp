#include<iostream>
#include<new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];   //external linkage;

int main() {
    using namespace std;
    double *pd1,*pd2;
    int i;
    cout << "Calling new  and placement new:\n";
    pd1 = new double[N];
    pd2 = new(buffer) double[N];       //placement new() dynamic memeory allocation;

    for (i = 0;i < N;i++) pd2[i] = pd1[i] = 1000 + 20*i;        // value assigned
    cout << "Memory address:\n" << "heap : " << pd1;
    cout << " static : " << (void *) buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0;i < N;i++)
    {
        cout << pd1[i] << " at " << (unsigned) &pd1[i] << "; ";
        cout << pd2[i] << " at " << (unsigned) &pd2[i] << endl;     //value accessed;
    }

    cout << "Calling new and placement new second time:\n";
    double *pd3,*pd4;
    pd3 = new double[N];    
    pd4 = new (buffer) double [N];          // new declaration and no need to delete old one;//automatic happens;
    for (i = 0;i < N;i++) pd4[i] = pd3[i] = 1000 + 40*i;
    cout << " Memory contents:\n";
    for (i = 0;i < N;i++)
    {
        cout << pd3[i] << " at " << (unsigned) &pd3[i] << "; ";
        cout << pd4[i] << " at " << (unsigned) &pd4[i] << endl;
    }
    
    cout << "Calling new and placement new third time:\n";
    delete [] pd1;
    pd1 = new double[N];
    pd2 = new (buffer + N*sizeof(double)) double [N];       //since given new dpace so store in that space;
    for (i = 0;i < N;i++) pd2[i] = pd1[i] = 1000 + 60*i;
    cout << " Memory contents:\n";
    for (i = 0;i < N;i++)
    {
        cout << pd1[i] << " at " << (unsigned) &pd1[i] << "; ";
        cout << pd2[i] << " at " << (unsigned) &pd2[i] << endl;
    }

    cout << " Memory contents:\n";
    for (i = 0;i < N;i++)
    {
        cout << pd3[i] << " at " << (unsigned) &pd3[i] << "; ";
        cout << pd4[i] << " at " << (unsigned) &pd4[i] << endl;
    }

    delete [] pd1;
    delete [] pd2;

    return 0;
}