#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct vector{
    int x;
    int y;
} vec;

void sum(vec v);
int main() {
    vec v[2];
    for (int i=0;i<2;i++) {
        printf("Enter Vector %d",i+1);
        printf("x = ");
        scanf("%d",&v[i].x);
        printf("y = ");
        scanf("%d",&v[i].y);
    }
    sum(v);
}
void sum(vec v) {
    int sumx,sumy;
    sumx = v[0].x + v[1].x;
    sumy = v[0].y + v[1].y;
}