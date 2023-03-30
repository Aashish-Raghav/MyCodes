// /b backspace escape sequence.   appears grand;


#include<iostream>

int main() 
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code : ________\b\b\b\b\b\b\b\b";  // 8 digit code accepted or big can be but perfect 8 ad per no of \b;
    long code;
    cin >> code;
    cout << "\aYou Entered " << code << "....\n";
    cout << "\acode verified! Proceed with the Plan Z3!\n";
    return 0;
}