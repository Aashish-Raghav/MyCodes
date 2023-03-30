// given rank(1-13)(ace ,2,..,king) and suit(1-4) (spade,heart,diamonds,clubs);
//return code of cards(1-52) [spade(1-13),heart(14-26),diamonds(27-39),clubs(40-52)]
#include<stdio.h>
int cardNo(int,int);
int main() {
    int rank,suit;
    printf("Enter rank and suit of card : ");
    scanf("%d %d",&rank,&suit);
    printf("Code for card is : %d",cardNo(rank,suit));
    return 0;
}
int cardNo(int rank,int suit){
    return rank + ((suit-1)*13);
}