#include<stdio.h>
#include<stdlib.h>

int main() {
    char datafile[50];
    printf("Enter Name or address of file : ");
    scanf("%s",datafile);
    FILE * in;
    if ( (in = fopen(datafile,"r")) == NULL ) {
        printf("file cannot be found. ");
        exit(1);
    }
    return 0;
}