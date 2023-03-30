#include<iostream>
struct car 
{
    std::string name;
    int year;
};

int main() 
{
    using namespace std;
    cout << "How many cars do you want to catalog? ";
    int num;
    (cin >> num).get();
    car* data = new car [num];
    for (int i = 0; i < num ;i++)
    {
    cout << "Car #" << i+1 << ":" << endl;
    cout << "Please enter the make : "; getline(cin,data[i].name);
    cout << "Please enter the year made : "; (cin >> data[i].year).get();
    cout << endl;
    }
    cout << "Here is your collection : " << endl;
    for (int i = 0;i < num; i++) cout << data[i].year << " " << data[i].name << endl;

    return 0;
}