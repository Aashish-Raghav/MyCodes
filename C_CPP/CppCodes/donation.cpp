#include<iostream>
struct donation
{
    std::string name;
    double damt;        // donation amount
};
int main() 
{
    using namespace std;
    int ndonar;     // no of donars
    cout << "Enter no of donors : "; (cin >> ndonar).get();
    donation * donar = new donation [ndonar];
    int nGpatrons=0,nHpatrons=0;        //number of grand patrons & number of headed patrons;
    for (int i = 0;i < ndonar;i++)
    {
        cout << "donar #" << i+1 << endl;
        cout << "Name : "; getline(cin,donar[i].name);
        cout << "Amount : "; (cin >> donar[i].damt).get();
        if (donar[i].damt >= 10000) nGpatrons++;
        else nHpatrons++;
       // cout << endl;
    }
    cout << "\n\nGRAND PATRONS\n";
    if (nGpatrons == 0) cout << "none";
    else {
        for (int i = 0;i < ndonar;i++)
        {
            if (donar[i].damt >= 10000) cout << donar[i].name << "\t" << donar[i].damt << endl;
        }
    }

    cout << "\n\nHEADED PATRONS\n";
    if (nHpatrons == 0) cout << "none";
    else {
        for (int i = 0;i < ndonar;i++)
        {
            if (donar[i].damt < 10000) cout << donar[i].name << "\t" << donar[i].damt << endl;
        }
    }


    return 0;
}
