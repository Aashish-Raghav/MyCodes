//new operator for pointer;
// new allows us to allocate data to memory in run time

//delete operator;
// delete free the memory from stored data , don't delete the pointer or address to which it points
// only data at that address is deleted so that this freed memory cna be reused by other parts of program.
#include<iostream>
int main() 
{
    using namespace std;
    int *p_age = new int;
    cout << "Enter value for age : "; cin >> *p_age;
    cout << "you entered : " << *p_age << " stored at address : " << (unsigned) p_age << endl;
    delete p_age;
    cout << "you entered : " << *p_age << " stored at address : " << (unsigned) p_age;
    return 0;
}