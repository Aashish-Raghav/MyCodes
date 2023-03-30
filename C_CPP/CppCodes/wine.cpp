#include <string>
#include <valarray>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T1,class T2,class T3>
class Pair
{
private:
    T1 arr1;
    T2 arr2;
public:
    // T1 first() { return a; }
    // T2 second() { return b; }
    Pair(const T1 & aval,const T2 & bval,T3 n) {}
    Pair() {}
};

// template <class T1,class T2>
// T1 & Pair<T1,T2>::first()
// {
//     return a;
// }

// template <class T1,class T2>
// T2 & Pair<T1,T2>::second()
// {
//     return b;
// }

template <class T1,class T2,class T3>
Pair<T1,T2,T3>::Pair(const T1 & aval,const T2 & bval,T3 n)
{
    for (int i = 0;i < n;i++)
    {
        arr1[i] = aval[i];
        arr2[i] = bval[i];
    }
}

class Wine
{
private:
    std::string name;
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt,int> PairArray;
    int num;
    PairArray Parr;
public:
    Wine(const char * l,int y,const int yr[],const int bot[]);
    Wine(const char * l,int y);
    void GetBottles();
    void Show();
    string & Label();
    int Sum();
};
Wine::Wine(const char * l,int y,const int yr[],const int bot[])
{
    name = l;
    num = y;
    Parr.arr1 = yr;
    Parr.arr2 = yr;
}

Wine::Wine(const char * l,int y)
{
    name = l;
    num = y;

}

void Wine::GetBottles()
{
    std::cout << "Enter " << name << " data for " << num << " year(s):\n";
    int yr,bts;
    for (int i = 0; i < num;i++)
    {
        std::cout << "Enter Year : ";
        std::cin >> Parr.arr1[i];
        std::cout << "Enter Bottles for that year: ";
        std::cin >> Parr.arr2[i];
    }
}

void Wine::Show()
{
    std::cout << "Wine: " << name << std::endl;
    cout << setw(10) << "Year"
         << setw(4) << ""
         << setw(7) << left << "Bottles\n";
    for (int i = 0;i < num;i++)
    {
        cout << setw(10) << Parr.arr1[i]
             << setw(4) << ""
             << setw(7) << left << Parr.arr2[i] << endl;
    }
}

string & Wine::Label()
{
    return name;
}

int Wine::Sum()
{
    int sum = 0;
    for (int i = 0;i < num; i++)
    {
        sum += Parr.arr2[i];
    }
    return sum;
}

int main()
{
    using std::endl;
    using std::cout;
    using std::cin;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine Holding(lab,yrs);
    Holding.GetBottles();
    Holding.Show();
}