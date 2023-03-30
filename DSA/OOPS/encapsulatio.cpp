#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string rollNo;
    int age;
public:
    void setName(const string & name){ this->name = name;}
    string getName() const {return name;}

    void setRoll(const string & rollNo) { this->rollNo = rollNo;}
    string getRoll()const { return rollNo;}

    void setAge(const int age) { this->age = age;}
    int getAge() const { return age;}
};

int main()
{
    //capsuled all values inside class student;
    Student s1;
    //setting all values;
    s1.setName("Aashish");
    s1.setRoll("IIT2022010");
    s1.setAge(16);

    //getting all values;
    cout << "Name : " << s1.getName() << endl;
    cout << "Roll : " << s1.getRoll() << endl;
    cout << "Age  : " << s1.getAge() << endl;
}