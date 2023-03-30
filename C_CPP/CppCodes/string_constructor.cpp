//here are all eight type of string constructor
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string one("It is my 1 string!");       //string (const char * c);
    string two(12,'2');     //string (size,char);
    string three(one);    //string (const string & str); //copy constructor;
    three[9] = '3';
    
    string four;      //string();  
    four = "It is my 4 string";
    string five("It is my 5 string",12);    //string(const char * s,size);
    //string five copies character till length if size exceed length add junk characters;****
    string six(&one[0],&one[12]);   //string(begin,end);    
    //it includes the begin but don't include the end;
    //till 0-11;
    six[9] = '6';
    string seven("It is my 7 string",0,12);//string(const string & str,begin index(int),end index(int))
    //copies from begin to end or to length of str whichever comes first;
    // till 0-11
    seven[9] = '7';

    cout << "Stirng 1 : " << one << endl;
    cout << "String 2 : " << two << endl;
    cout << "String 3 : " << three << endl;
    cout << "String 4 : " << four << endl;
    cout << "String 5 : " << five << endl;
    cout << "String 6 : " << six << endl;
    cout << "String 7 : " << seven << endl;
    cout << seven.size();
    return 0;
}