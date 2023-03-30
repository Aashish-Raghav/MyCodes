#include<iostream>
#include<fstream>
#include<cstdlib>
struct donation
{
    std::string dname;
    double damt;
} ;

int main() 
{
    using namespace std;
    ifstream fin;
    fin.open("donation.txt");
    if (!fin.is_open()) {
        cout << "Could not open file\n";
        cout << "Program terminating\n";
        exit(EXIT_FAILURE);
    }
    int num;
    (fin >> num).get();
    donation * donar = new donation [num];
    int nGpatrons=0,nHpatrons=0;
    for (int i =0;i < num;i++) 
    {
        getline(fin,donar[i].dname);
        (fin >> donar[i].damt).get();
        if (donar[i].damt >= 10000) nGpatrons++;
        else nHpatrons++;
    }
    cout << "\n\nGRAND PATRONS\n";
    if (nGpatrons == 0 ) cout << "none\n";
    else {
        for (int i = 0;i < num;i++){
            if (donar[i].damt >= 10000) cout << donar[i].dname << endl;
        }
    }
    cout << "\n\nHEADED PATRONS\n";
    if (nHpatrons == 0 ) cout << "none\n";
    else {
        for (int i = 0;i < num;i++){
            if (donar[i].damt < 10000) cout << donar[i].dname << endl;
        }
    }
    return 0;
}
