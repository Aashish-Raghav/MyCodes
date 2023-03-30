// find the no which has maximum consecutive frequency;
#include<stdio.h>

int main() {
    int num,value,i,max_i = 0,max_num;      // i : frequency of number, num : a number, value : a number
    FILE * in = fopen("E:\\c programming\\C_Codes\\TextFiles\\unknown_numbers.txt","r");
    
    fscanf(in,"%d",&num);
    
    while (num != 0) {
        value = num;
        i = 0;
        while (num == value) {
            i++;
            //printf("%d \n",num);
            fscanf(in,"%d",&num);
        } 
        
        if (max_i <=  i) {
            max_i = i;
            max_num = value;
        }
        
    }
    printf("%d repeats maximum of %d times",max_num,max_i);
    return 0;
}