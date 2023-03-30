#include <stdio.h>

void foo(int n){
    int data;
    if (n == 0)
        return;

    scanf("%d",&data);
    printf("%d\n",data);
    foo(n-1);
    
    
}

int main(){
    foo(5);
    return 0;
}