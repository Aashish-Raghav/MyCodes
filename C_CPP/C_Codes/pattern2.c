/* if n is even : /2  if n is odd : *3 + 1
if input 13 then: 13   40  20  10  5   16  8   4   2   1
write a fxn that return length of pattern inclusive ( for 13 return 10)
input range() [m,n] and print the no with maximum pattern length like [1,10] 9 generate the longest sequence of length 20 */
#include<stdio.h>
int seqLength(int);     // sequence length;
int max_seqLength(int,int);
int main() {
    int num,n,m;
    printf("Enter a number. : ");
    scanf("%d",&num);
    printf("%d generates the sequence of length %d\n\n",num,seqLength(num));
    printf("Enter a range : ");
    scanf("%d %d",&n,&m);       //n < m (given)
    max_seqLength(n,m);
    return 0;
}
int seqLength(int num) {
    int i = 1;
    while (num != 1) {
        if (num %2 == 0) num = num/2;
        else num = num * 3 + 1;
        i++;
    }
    return i;
}

int max_seqLength(int n,int m) {
    int max = 0,num;
    for (int i = n;i<=m;i++) {
        if (seqLength(i) > max) {
            max = seqLength(i);
            num = i;
        }
    }
    printf("%d generates the longest sequence of length %d",num,max);
    return 0;
}