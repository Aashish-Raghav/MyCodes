// input hours and minute and through fxn print time as say, 9:28
#include<iostream>
void time(int ,int);
int main() {
    int hour,minute;
    std::cout << "Enter hour : "; std::cin >> hour;
    std::cout << "Enter minute : "; std::cin >>minute;
    time(hour,minute);
    return 0;
}
void time(int hour,int minute) {
    std::cout << "Time: " << hour << ":" << minute;
}