#include<iostream>
#include<array>

const int Seasons = 4;
const std::array <std::string,Seasons> Snames =
    {"Spring","Summer","Fall","Winter"};

void fill(std::array <double,Seasons> *pa);     //pointer to array object : pa;
void show(const std::array <double,Seasons> da);    // double type array object : da;

int main() 
{
    using namespace std;
    array <double,Seasons> expenses;
    fill(&expenses);
    show(expenses);

    return 0;
}

void fill(std::array <double,Seasons> *pa){
    for (int i = 0;i < Seasons;i++) {
        std::cout << "Enter " << Snames[i] << " expense : ";
        std::cin >> (*pa)[i];
    }
}

void show(const std::array <double,Seasons> da) {
    int total = 0;
    std::cout << std::endl << "EXPENSES\n";
    for (int i = 0;i < Seasons;i++) {
        std::cout << "Expense in " << Snames[i] << " = $" << da[i] << std::endl;
        total += da[i];
    }
    std::cout << "Total = $" << total;
}