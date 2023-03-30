#include <stdio.h>
int main(){
    char name[30];
    gets(name);
    // getchar();
    // fgets(name,30,stdin);
    // printf("gets : %s",name);
    printf("fgets : %s",name);

}