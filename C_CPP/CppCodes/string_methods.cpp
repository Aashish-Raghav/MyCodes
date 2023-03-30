//find(str,pos)
//find_first_of(str,pos),find_last_of(str,pos);
//find_first_not_of(str,pos),find_last_not_of(str,pos);
//c_str();

//here use;
//capacity(), reserve(size)
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string empty;
    string small = "bit";
    string large = "Elephants are a girl's best friend,Hello guys";
    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall : " << small.size() << endl;
    cout << "\tlarge : " << large.size() << endl;
    cout << "\nCapacities:\n";
    cout << "\tempty : " << empty.capacity() << endl;
    cout << "\tsmall : " << small.capacity() << endl;
    cout << "\tlarge : " << large.capacity() << endl;
    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "
         << empty.capacity() << endl; 

    string hello = "helllo" ;
    cout << "find str : " << hello.find("el");

    return 0;
}