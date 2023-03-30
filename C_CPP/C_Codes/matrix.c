// Matrix Operations...
#include <stdio.h>
#include <stdlib.h>


int row=3,column=3;

void swap(int* a,int * b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void input(int arr[3][3], int row, int column){ //take matrix input
    for(int i=0; i<row; i++){
        printf("Enter elements of row %d :",i+1);
        for(int j=0; j<column; j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void print(int arr[3][3], int row, int column){ // print matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++)     
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}

void sum(int arr[][3], int brr[][3]){
    int plus[3][3];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            plus[i][j]=arr[i][j]+brr[i][j];
        }
    }
    print(arr,row,column);
    printf("  +\n");
    print(brr,row,column);
    printf("  =\n");
    print(plus,row,column);
}

void multiply(int arr[][3], int brr[][3]){      //   *MOST IMPORTANT*
    int mul[3][3];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            int sum=0;
            for(int k=0; k<column; k++){  //k must be = (column of 1st matrix or row of 2nd matrix).
                sum+=arr[i][k]*brr[k][j];
            }
            mul[i][j]=sum;
        }
    }
    print(arr,row,column);
    printf("  *\n");
    print(brr,row,column);
    printf("  =\n");
    print(mul,row,column);
}

void transpose(int arr[][3],int row,int col){
    for (int i = 0;i < row;i++){
        for (int j = 0;j < i;j++){
            swap(&arr[i][j],&arr[j][i]);
        }
    }
    print(arr,3,3);
}

int main(){
    
    int arr[row][column];
    int brr[row][column];

    input(arr, row, column);
    // input(brr, row, column);
    transpose(arr,row,column);

    // sum(arr,brr);
    // multiply(arr,brr);

	return 0;
}