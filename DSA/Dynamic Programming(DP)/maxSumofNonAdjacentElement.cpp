#include <bits/stdc++.h> 
using namespace std;

int solve1(vector<int> &num,int n){
    //base case;
    if (n == 0){
        return num[0];
    }
    if (n < 0)
        return 0;

    int incl = solve1(num,n-2) + num[n];
    int excl = solve1(num,n-1);

    return max(incl,excl);

}

//memoization
int solve2(vector<int> &num,int n,vector<int> &dp){
    //base case;
    if (n == 0){
        return num[0];
    }
    if (n < 0)
        return 0;
    
    //step 3;
    if (dp[n] != -1)
        return dp[n];

    int incl = solve2(num,n-2,dp) + num[n];
    int excl = solve2(num,n-1,dp);

    //step 2;
    dp[n] = max(incl,excl);
    return dp[n];

}

//tabulation method
int solve3(vector<int> &num){
    int n = num.size();
    vector<int> dp(n,0);

    //base case;
    dp[0] = num[0];

    for (int i = 1;i < n;i++){
        int incl = dp[i-2] + num[i];
        int excl = dp[i-1];

        dp[i] = max(incl,excl);

    }

    return dp[n-1];
}

//space optimisation
int solve4(vector<int> &num){
    int prev2 = 0;
    int prev1 = num[0];

    for (int i = 1;i < num.size();i++){
        int incl = prev2 + num[i];
        int excl = prev1;

        prev2 = prev1;
        prev1 = max(incl,excl);
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &num){
    int n = num.size();
    int ans = solve1(num,n-1);

    
    vector<int> dp(n+1,-1);
    ans = solve2(num,n-1,dp);

    ans = solve3(num);
    return ans;
}