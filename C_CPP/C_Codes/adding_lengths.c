// data entered in strictly 3 27,4 45  such way

#include <stdio.h>
int main() {
    int feet1,inch1,feet2,inch2,nfeet,ninch;
    printf("Enter length1 in feets and inches : ");
    scanf("%d %d",&feet1,&inch1);
    
    printf("\nEnter length2 in feet and inches : ");
    scanf("%d %d",&feet2,&inch2);
    
    ninch=(inch1+inch2)%12;
    nfeet=feet1+feet2+(inch1+inch2)/12;
    
    printf("\nSum of given lengths is %d ft. %d in.",nfeet,ninch);
    
    return 0;
}