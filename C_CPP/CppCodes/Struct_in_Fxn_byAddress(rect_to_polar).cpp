#include<iostream>
#include<cmath>

struct polar{
    double dist;
    double angle;
};
struct rect{
    double x;
    double y;
};

void rect_to_polar(const rect*,polar*);
void show_polar(polar*);

int main() 
{
    using namespace std;
    rect rplace;
    polar pplace; 
    cout << "Enter to numbers : ";
    while (cin >> rplace.x >> rplace.y){        //OR declare pointers and use them;
        rect_to_polar(&rplace,&pplace);
        show_polar(&pplace);
        cout << "Next to Numbers(q to quit) : ";
    }

    return 0;
}

void rect_to_polar(const rect* pxy,polar* pda){ //pointer xy values,pointer dist angle;
    pda->dist = sqrt(pow(pxy->x,2) + pow(pxy->y,2));
    pda->angle = atan2(pxy->y,pxy->x);
}

void show_polar(polar* pda){
    const double Rad_to_deg = 57.29577951;
    std::cout << "distance : " << pda->dist << std::endl;
    std::cout << "angle : " << pda->angle * Rad_to_deg << " degrees.\n";
}