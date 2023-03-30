#include<stdio.h>
#include<string.h>

void slice(char string[50],int m,int n);

int main() {
    char string[50];
    int m,n;
    printf("Enter a sting : ");
    fgets(string,50,stdin);
    printf("Enter range for slice (separated by space) : ");
    scanf("%d %d",&m,&n);
    slice(string,m,n);
    //printf("Sliced String : %s",);
    return 0;
}

void slice(char string[50],int m,int n) {   // assuming m<n;
    char slice[50];
    int h = 0;
    for (int i = m;i <= n;i++){
        slice[h++] = string[i];
    }
    printf("%s",slice);
}