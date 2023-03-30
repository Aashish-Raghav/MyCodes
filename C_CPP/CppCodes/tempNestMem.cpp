//nested tmeplate and member template
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class beta
{
private:
    template <class V>
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V value() const { return val; }
    };
    hold<T> q;      //implicit instantiations
    hold<int> n;        //explicit specialization
public:
    beta(T t,int i) : q(t),n(i) {}
    template<class U>
    U blab(U u,T t) { return(n.value() + q.value()) * u/t;}
    void show() const { q.show();n.show();}
};

int main()
{
    beta<double> guy(3.5,3);
    cout << "T was set to double\n";
    guy.show();
    cout << "V was set to  T, which is double,then V was set to int\n";
    cout << guy.blab(10,2.7) << endl;   //return type is int;
    cout << "U was set to int\n";
    cout << guy.blab(10.0,2.3) << endl; // return type is double; 
    cout << "U was set to double\n";
    cout << "Done\n";
    return 0; 
}