//input an integer or an string and tell the no of characters
// do you want to print from that string and integer;

#include<iostream>

unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str,int n = 1);

int main() 
{
    using namespace std;
    char * trip = "Hawaii!!";
    unsigned long n = 12345678;
    int i;
    char * temp;

    for (int i = 1;i < 10;i++){
        cout << left(n,i) << endl;
        //cout << "hello";
        temp = left(trip,i);
        cout << temp << endl;
        delete [] temp;
    }
    return 0;
}

unsigned long left(unsigned long num,unsigned ct){
    if (num == 0 || ct <= 0) return 0;
    //std::cout << num;
    unsigned digit = 1;
    unsigned long n = num;
    while (n /= 10) digit++;
    if (digit > ct) {
        ct = digit-ct;
        while (ct--) num /= 10;
        //std::cout <<num;
        return num;

    }
    else return num;
}

char * left(const char * str,int n){
    if (n < 0) n = 0;
    //std::cout << str;
    char * p = new char[n+1];
    int i ;
    for (i = 0;i < n && str[i];i++){        //str[i] checks if string ends before the asked length n;
        p[i] = str[i];
    }

    while (i <= n) p[i++] = '\0';
    return p;
}