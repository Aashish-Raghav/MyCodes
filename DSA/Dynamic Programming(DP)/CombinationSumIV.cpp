#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &num, int tar){
    //base case;
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    int ans = 0;
    for (int i = 0;i < num.size();i++){
        ans += solve(num,tar-num[i]);
    }

    return ans;
}

//memoization
int solve1(vector<int> &num, int tar,vector<int> &dp){
    //base case;
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    //step 3;
    if (dp[tar] != -1)
        return dp[tar];
        
    int ans = 0;
    for (int i = 0;i < num.size();i++){
        ans += solve1(num,tar-num[i],dp);
    }
    //step 2;
    dp[tar] = ans; 
    return dp[tar];
}


//tabulation
int solv2(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    //base case;
    dp[0] = 1;

    //updating dp;
    for (int i = 1;i <= tar;i++){
        
        for (int j = 0; j < num.size();j++){
            if (i-num[j] >= 0)
                dp[i] += dp[i-num[j]];
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{

    
    return solve(num,tar);
}