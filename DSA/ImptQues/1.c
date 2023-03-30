#include <stdio.h>
int main()
{
    int a;
    int* p = &a;
    printf("%d ",p);
    printf("%d %d",*p++,*++p);
    return 0;
}