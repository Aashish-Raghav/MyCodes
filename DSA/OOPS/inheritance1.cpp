#include <iostream>
using namespace std;

class Human
{
public:
    int height;
public:
    int weight;
    int age;
public:
    void setWeight(const int & weight) {this->weight = weight;}
    int getWeight() const { return this->weight;}
};

class Male : private Human
{
public: 
    int power;
    int sleep;
public:
    void setHeight(const int & height) {this->height = height;}
    int getHeight() const { this->height;}    
};


int main()
{
    Male m1;
    // cout << m1.height << endl;
    cout << m1.getHeight() << endl;;
    return 0;
}   