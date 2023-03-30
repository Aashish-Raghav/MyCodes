#include <bits/stdc++.h> 
using namespace std;

// simple recursion
int solve1(vector<int> &num, int x){
    //base case;
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    int mini = INT_MAX;
    for (int i = 0;i < num.size();i++){
        int ans = solve1(num,x - num[i]);
        if (ans != -1){
            mini = min(mini,ans+1);
        }
    }
    if (mini == INT_MAX)
        return -1;
    return mini;
}

// memoization
int solve2(vector<int> &num, int x,vector<int> &dp){
    //base case;
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;

    //step 3;
    if (dp[x] != -1)
        return dp[x];
    int mini = INT_MAX;
    for (int i = 0;i < num.size();i++){

        int ans = solve2(num,x - num[i],dp);
        
        if (ans != -1){
            mini = min(mini,ans+1);
        }
    }

    //step 2;
    if (mini == INT_MAX)
        dp[x] = -1;
    else
        dp[x] = mini;

    return dp[x];
}

//tabulation
int solve3(vector<int> &num,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    //bottom up approach building from 1 -> x;
    for (int i = 1;i <= x;i++){
        //for each target 1->x checking every coin as in memoization 
        for (int j = 0;j < num.size();j++){
            if (i-num[j] >= 0 && dp[i-num[j]] != INT_MAX)
            // mini = min(mini,target-coin)
            dp[i] = min(dp[i],1 + dp[i-num[j]]);
        }
    }

    if (dp[x] == INT_MAX)
        return -1;
    else
        return dp[x];
}


int minimumElements(vector<int> &num, int x)
{
    
    int ans = solve1(num,x);
    //step 1;
    vector<int> dp(x+1,-1);
    ans = solve2(num,x,dp);
    return ans;
}