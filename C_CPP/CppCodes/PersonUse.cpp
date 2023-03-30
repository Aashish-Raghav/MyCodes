#include<iostream>
#include"Person.h"
#include<string>

int main()
{
    using std::cout;
    using std::endl;
    Person one;
    Person two("Raghav");
    Person three("Raghav","Aashish");

    cout << "Formal show :\n";
    cout << "one : ";one.FormalShow();
    cout << "two : ";two.FormalShow();
    cout << "three : ";three.FormalShow();
    
    cout << "Normal Show :\n";
    cout << "one : ";one.Show();
    cout << "two : ";two.Show();
    cout << "three : ";three.Show();
    
}