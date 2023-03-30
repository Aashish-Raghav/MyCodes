#include<stdio.h>

typedef struct address {
    int house;
    int block;
    char city[50];
    char state[50];
} add;

int main() {
    add stu[2];
    for (int i = 0;i<2;i++){
        printf("Enter Address %d\n",i+1);
        printf("Enter House no.");
        scanf("%d",&stu[i].house);
        printf("Enter Block no. :");
        scanf("%d",&stu[i].block);
        printf("Enter City : ");
        fflush(stdin);                      //using fflush is very crucial*
        gets(stu[i].city);//,50,stdin);
        // fgets(stu[i].city,50,stdin);
        printf("Enter State : ");
        fflush(stdin);
        gets(stu[i].state);//,50,stdin);

    }
    printf("\n");
    for (int i=0;i<2;i++) {
        printf("Address %d : %d,%d,%s,%s\n",i+1,stu[i].house,stu[i].block,stu[i].city,stu[i].state);
    }
}