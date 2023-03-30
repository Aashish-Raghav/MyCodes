#include<stdio.h>
#include<string.h>

void salting(char pass[],char newpass[]);
int main() {
    char pass[50],newpass[50];
    printf("Enter password : ");
    scanf("%s",pass);
    salting(pass,newpass);
    printf("Your new password (salted) : %s",newpass);
    return 0;
}

void salting(char pass[],char newpass[]) {
    strcpy(newpass,pass);
    strcat(newpass,"123");
}