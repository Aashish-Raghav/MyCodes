#include<iostream>
struct tacos {
    std::string name;
    double vol;
    double price;
};
int main() 
{
    using namespace std;
    tacos *ptacos = new tacos;
    //input;
    cout << "Enter Name of item : "; getline(cin,ptacos->name);
    cout << "Enter volume in metre cube : "; cin >> (*ptacos).vol;
    cout << "Enter Price : $"; cin >> ptacos->price;

    //output;
    cout << "Name : " << ptacos->name << endl;
    cout << "Volume : " << ptacos->vol << endl;
    cout << "Price : $" << ptacos->price << endl;
    

    return 0;
}