// using placement new with class;
#include<iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing",int num = 0)
    {
        words = s;
        number = num;
        cout << words << " constructed\n";
    }
    ~JustTesting()
    {
        cout << words << " destroyed\n";
    }
    void Show() const
    {
        cout << words << ", " << number << endl;
    }
};

int main()
{
    char * buffer = new char[BUF];

    JustTesting *p1,*p2;

    p1 = new (buffer) JustTesting;
    p2 = new JustTesting("heap1", 20);

    cout << "Memory Address :\n" << "Buffer(p1) : "
         << (unsigned) (void *) buffer << " heap(p2) : " << (unsigned) p2 << endl;
    cout << "Memory Contents : ";
    cout << (unsigned) p1 << ": ";
    p1->Show();
    cout << (unsigned) p2 << ": ";
    p2->Show();

    JustTesting *p3,*p4;
    p3 = new (buffer + sizeof(*p1)) JustTesting("Better Idea",20);
    p4 = new JustTesting("Heap2",33);

    cout <<"Memory Contents : ";
    cout << (unsigned) p3 << ": " ;
    p3->Show();
    cout << (unsigned) p4 << ": ";
    p4->Show();

    p1->~JustTesting(); //explicit destructor of object created using placement new;
    delete p2;  // delete auto matically calls destructor for object created using new;
    p3->~JustTesting(); // same;
    delete p4;
    delete [] buffer;
    cout << "Done\n";
    return 0;
}