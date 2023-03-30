#include <bits/stdc++.h> 
using namespace std;
bool isSafe(int row,int col,int value,vector<vector<int>> &sudoku){
    
    for (int i = 0;i < 9;i++){
        //col check;
        if (sudoku[i][col] == value)
            return false;
        //row check;
        if (sudoku[row][i] == value)
            return false;

        //box check;
        if (sudoku[3*(row/3) +i/3][3*(col/3) + i%3] == value)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku,int i,int j,int n){
   if(i==n){
       return true;
   }
   if(j==n){
       return solve(sudoku,i+1,0,n);
   }
   if(sudoku[i][j]!=0){
       return solve(sudoku,i,j+1,n);
   }
   for(int k=1;k<=n;k++){
       if(isSafe(i,j,k,sudoku)){
           sudoku[i][j]=k;
           if(solve(sudoku,i,j+1,n)){
               return true;
           }
       }
   }
   sudoku[i][j]=0;
   return false;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
// Write your code here
   // No need to print the final sudoku
   // Just fill the values in the given matrix
   int n=9;
   solve(sudoku,0,0,n);
}