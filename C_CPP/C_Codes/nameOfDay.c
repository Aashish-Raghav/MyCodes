#include<stdio.h>
#include<string.h>

void nameOfDay(int, char[]);

int main() {
    int n;
    char dayName[10];
    printf("Enter day number : ");
    scanf("%d",&n);
    nameOfDay(n,dayName);
    printf("%s\n",dayName);
    return 0;
}

void nameOfDay(int n,char name[]){
    char day[8][10] = {"","Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday"};
    if (n >= 1 && n <= 7) strcpy(name,day[n]);
    else strcpy(name,"Invalid Input");


}