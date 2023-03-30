//using structures, arrays , pointers together;

#include<iostream>
struct tacos
{
    int year;
};

int main() 
{
    using namespace std;
    tacos s1,s2,s3;                         //three structures s1,s2,s3;
    tacos *ptr = &s2;                       //a pointer pointing to address of structure 2; 
    tacos trio[3];                          //array of 3 structures;
    const tacos *aptr[3] = {&s1,&s2,&s3};   //array of 3 pointer pointing to address of three structures;
    //confusing;
    const tacos *(*paptr) = aptr;           //pointer pointing to the array of 3 pointer pointing to address of three structure;
    //or auto paptr = aptr;

    //input
    s1.year = 1998;                         //assigned structure s1;
    ptr->year = 1999;                       //set the value of structure 2 using ptr indirect membership operator;
    trio[0].year = 2000;                    //trio is array , trio[0] is structure;

    //output;
    cout << "s1.year : " << s1.year << endl;                    //from structure
    cout << "ptr->year : " << ptr->year << endl;                //from pointer
    cout << "trio[0].year : " << trio[0].year << endl;          //from array of structure
    cout << "aptr[0]->year : " << aptr[0]->year << endl;        //from array of pointers
    //confusing;
    //cout << "(*paptr)[0]->year : " << (*paptr)[0]->year <<endl; //from pointer of array of pointer;


    return 0;
}