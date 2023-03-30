#include<iostream>
#include<cmath>

struct rect{
    double x;
    double y;
};
struct polar{
    double dist;
    double angle;
};

polar rect_to_polar(rect);
void show_polar(polar);
int main() 
{
    using namespace std;
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values : " ;
    while (cin >> rplace.x >> rplace.y){        //two values input at a time;
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit ) : ";
    }
    return 0;
}

polar rect_to_polar(rect xypos){
    polar answer;
    answer.dist = sqrt(pow(xypos.x,2) + pow(xypos.y,2));
    answer.angle = atan2(xypos.y,xypos.x);
    return answer;
}

void show_polar(polar dapos){
    const double Rad_to_Deg = 57.29577951;
    std::cout << "Distance = " << dapos.dist;
    std::cout << ", angle = " << dapos.angle * Rad_to_Deg;
    std::cout << " degress\n";
}