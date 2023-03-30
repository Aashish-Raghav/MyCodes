#include <bits/stdc++.h>
using namespace std;

//recursion
int solve(int n,int a[],int curr,int prev){
    //base case;
    if (curr == n){
        return 0;
    }
    
    //include 
    int include = 0;
    if (prev == -1|| (a[prev] < a[curr])){
        include = 1 + solve(n,a,curr+1,curr);
    }
    
    int exclude = solve(n,a,curr+1,prev);
    
    return max(include,exclude);
}

//memoization
int solve1(int n,int a[],int curr,int prev,vector<vector<int>> &dp){
    //base case;
    if (curr == n)
        return 0;
        
    if (dp[curr][prev+1] != -1)
        return dp[curr][prev+1];
        
    //include
    int include = 0;
    if (prev == -1 || a[curr] > a[prev])
        include = 1 + solve1(n,a,curr+1,curr,dp);
        
    int exclude = solve1(n,a,curr+1,prev,dp);
    
    dp[curr][prev+1] = max(include,exclude);
    return dp[curr][prev+1];
}

//tabulation
int solve2(int n,int a[]){
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    
    for (int curr = n-1;curr >= 0;curr--){
        for (int prev = curr-1;prev >= -1;prev--){
            //include;
            int include = 0;
            if (prev == -1 || a[curr] > a[prev]){
                include = 1+ dp[curr+1][curr+1];
            }
            int exclude = dp[curr+1][prev+1];
            
            dp[curr][prev+1] = max(include,exclude);
        }
    }
    return dp[0][0];
}

//space optimisation
int solve3(int n,int a[]){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);
    
    for (int curr = n-1;curr >= 0;curr--){
        for (int prev = curr-1;prev >= -1;prev--){
            //include;
            int include = 0;
            if (prev == -1 || a[curr] > a[prev]){
                include = 1+ nextRow[curr+1];
            }
            int exclude = nextRow[prev+1];
            
            currRow[prev+1] = max(include,exclude);
        }
        nextRow = currRow;
    }
    return currRow[0];
}

//dp with Binary search
//most optimised solution
int solveOptimised(int n,int a[]){
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1;i < n;i++){
        if (a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
    }
    
    
int longestSubsequence(int n, int a[])
{
    vector<vector<int>> dp(n, vector<int> (n+1,-1));
    return solve1(n,a,0,-1,dp);
}
