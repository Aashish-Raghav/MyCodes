#include <iostream>
void showMenu();
void put();
void read();
void search();
void update();
void remove();
int main() {
    using namespace std;
    showMenu();
    int choice; cin >> choice;
    while (choice != 6)
    {
        switch (choice)
        {
            case 1 : put();
                     break;
            case 2 : read();
                     break;       
            case 3 : search();
                     break;
            case 4 : update();
                     break;
            case 5 : remove();
                     break;
            default : cout << "That's Not a Valid choice.\n";
        }
        showMenu();
        cin >> choice;
    }
    return 0;
}
void showMenu() {
    std::cout << "Please enter 1, 2, 3, 4, 5, or 6\n"
            "1) Put         2)Read\n"
            "3)Search       4)Update\n"
            "5)Remove       6)Quit\n";
}

void put() {
    std::cout << "Data written.\n";
}
void read() {
    std::cout << "Data read.\n";
}
void search() {
    std::cout << "Your Data.\n";
}
void update() {
    std::cout << "Data updated.\n";
}
void remove() {
    std::cout << "Data removed.\n";
}