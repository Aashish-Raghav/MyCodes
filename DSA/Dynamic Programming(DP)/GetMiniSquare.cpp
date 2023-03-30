#include <bits/stdc++.h>
using namespace std;
//Memoization Mine;
int solve(int n,vector<int> &dp){
    // cout << n << endl;
    int value = (int) sqrt(n);
    if (value*value == n)
        return 1;
    
    if (dp[n] != -1)
        return dp[n];
        
    int temp = (int) sqrt(n);
    int mini = INT_MAX;
    for (int i = 1;i <= temp;i++){
        mini = min(mini,solve(n-i*i,dp));
    }
    
    dp[n] = mini+1;
    return mini+1;
}

//memoization bhaiya
int solve1(int n,vector<int> &dp){
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
        
    int mini = INT_MAX;
    for (int i = 1;i*i <= n;i++){
        mini = min(mini,1+solve1(n-i*i,dp));
    }

    dp[n] = mini;
    return mini;
}

//Tabulation
int solve2(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    for (int i = 1;i <= n;i++){
        for (int j = 1;j*j <= n;j++){
            if (i-j*j >= 0)
                dp[i] = min(dp[i],1+dp[i-j*j]);
        }
    }

    return dp[n];
}

int MinSquares(int n)
{
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}
