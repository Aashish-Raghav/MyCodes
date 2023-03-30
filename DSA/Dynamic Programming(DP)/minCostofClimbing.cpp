#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

// memoization;
  int solve(vector<int>&cost,int n,vector<int> &dp){
    if (n == 0 || n == 1)
        return cost[n];
    
    //step 3;
    if (dp[n] != -1)
      return dp[n];

    //step 2;
    dp[n] = min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
    return dp[n];
  }

//tabulation method;
int solve2(vector<int> &cost,int n){
    vector<int> dp(n+1,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2;i < n;i++){
      dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }

    return min(dp[n-1],dp[n-2]);
  }

//space optimisation
int solve3(vector<int> &cost,int n){
    int prev1 = cost[1];
    int prev2 = cost[0];
    // int curr = 0;
    for (int i = 2;i < n;i++){
      int curr = min(prev1,prev2) + cost[i];
      prev2 = prev1;
      prev1 = curr;
    }

    return min(prev1,prev2);
  }

  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    //step 1;
    vector<int> dp(n+1,-1);
    int ans = min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
  }
};