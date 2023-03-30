#include<iostream>
struct travel_time{
    int hrs;
    int min;
};
const int Mins_Per_Hr = 60;

travel_time sum(travel_time,travel_time);
void show_trip(const travel_time);

int main() 
{
    using namespace std;
    travel_time day1 = {5,45};
    travel_time day2 = {6,50};
    travel_time trip = sum(day1,day2);
    cout << "Two Day Total : "; 
    show_trip(trip);
    travel_time day3 = {4,32};
    cout << "Three day total : ";
    show_trip(sum(trip,day3));

    return 0;
}

travel_time sum(travel_time t1,travel_time t2) {
    travel_time total;
    total.min = (t1.min + t2.min)%Mins_Per_Hr;
    total.hrs = (t1.hrs + t2.hrs) + (t1.min + t2.min)/Mins_Per_Hr;
    return total;
}
void show_trip(const travel_time t1) {
    std::cout << t1.hrs << " hours " << t1.min << " minutes \n";
}

