#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<vector<int>> &mat,int i,int j,int &maxi){
    //base case;
    if (i >= n || j >= m)
        return 0;
    
    
    int right = solve(n,m,mat,i,j+1,maxi);
    int diagonal = solve(n,m,mat,i+1,j+1,maxi);
    int down = solve(n,m,mat,i+1,j,maxi);
    
    if (mat[i][j] == 1){
        int ans = 0;
        ans = 1 + min(right,min(diagonal,down));
        maxi = max(maxi,ans);
        return ans;
    }
    else
        return 0;
}

//memoization
int solve1(int n,int m,vector<vector<int>> &mat,int i,int j,int &maxi,vector<vector<int>> &dp){
    //base case;
    if (i >= n || j >= m)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int right = solve1(n,m,mat,i,j+1,maxi,dp);
    int diagonal = solve1(n,m,mat,i+1,j+1,maxi,dp);
    int down = solve1(n,m,mat,i+1,j,maxi,dp);
    
    if (mat[i][j] == 1){
        dp[i][j] = 1 + min(right,min(diagonal,down));
        maxi = max(maxi,dp[i][j]);
        return dp[i][j];
    }
    else{
        dp[i][j] = 0;
        return 0;
    }
}

//tabulation
int solve2(int n,int m,vector<vector<int>> &mat,int i,int j,int &maxi){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    //base case;
    for (int i = n-1;i >= 0;i--){
        for (int j = m-1;j >= 0;j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];
            
            if (mat[i][j] == 1){
                dp[i][j] = 1 + min(right,min(diagonal,down));
                maxi = max(maxi,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
        
    }
    return dp[0][0];
}

//space optimisation
int solve3(int n,int m,vector<vector<int>> &mat,int i,int j,int &maxi){
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);
    //base case;
    for (int i = n-1;i >= 0;i--){
        for (int j = m-1;j >= 0;j--){
            int right = curr[j+1];
            int diagonal = next[j+1];
            int down = next[j];
            
            if (mat[i][j] == 1){
                curr[j] = 1 + min(right,min(diagonal,down));
                maxi = max(maxi,curr[j]);
            }
            else{
                curr[j] = 0;
            }
        }
        next = curr;
        
    }
    return next[0];
}

int maxSquare(int n, int m, vector<vector<int>> mat){
    int maxi = 0;
    solve(n,m,mat,0,0,maxi);
    return maxi;
}