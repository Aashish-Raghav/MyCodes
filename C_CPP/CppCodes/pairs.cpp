//using template to hold two types of values
#include <iostream>
#include <string>
template <class T1,class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a;}
    T2 second() const { return b;}
    Pair(const T1 & a_val,const T2 & b_val) : a(a_val),b(b_val) {}
    Pair() {}
};

template <class T1,class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}

template <class T1,class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    Pair<string,int> ratings[4] =
    {
        Pair<string,int>("The Purpled Duck",5),
        Pair<string,int>("Jaquie's Frisco Al Fresco",4),
        Pair<string,int>("Cafe Souffle",5),
        Pair<string,int>("Bertie's Rate",3)
    };
    int joints = sizeof ratings / sizeof(Pair<string,int>);
    cout << "Rating:\tEatery\n";
    for (int i = 0;i < joints;i++)
    {
        cout << ratings[i].second() << ":\t ";
        cout << ratings[i].first() << endl;
    } 
    cout << "Ooops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t ";
    cout << ratings[3].first() << endl;
    return 0;

}