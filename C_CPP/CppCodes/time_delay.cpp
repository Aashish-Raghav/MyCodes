#include<iostream>
#include<ctime>

int main() 
{
    using namespace std;
    cout << "Enter a delay time, in seconds : ";
    float secs = 2;
    cin >> secs;
    //cout << CLOCKS_PER_SEC << endl << clock() << endl;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t start = clock();
    while (clock() - start < delay ) ;
    cout << "done \a\n";
    //cout << CLOCKS_PER_SEC << endl << clock() << endl;
    return 0;
}