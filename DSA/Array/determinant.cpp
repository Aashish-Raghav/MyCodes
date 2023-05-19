#include <bits/stdc++.h>
using namespace std;
//Determinant of Matrix...............................
// O(n^4);
//space O(n^3);

int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        if (n == 1){
            return matrix[0][0];
        }
        
        int ans = 0;
        for (int i = 0;i < n;i++){
            vector<vector<int>> sMatrix;
            for (int k = 1;k < n;k++){
                vector<int> temp;
                for (int j = 0;j < n;j++){
                    if (j == i)
                        continue;
                    temp.push_back(matrix[k][j]);
                }
                sMatrix.push_back(temp);
            }
            
            if (i&1)
                ans -= matrix[0][i]*determinantOfMatrix(sMatrix,n-1);
            else
                ans += matrix[0][i]*determinantOfMatrix(sMatrix,n-1);
        }
        
        return ans;
    }