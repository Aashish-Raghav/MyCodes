#include <bits/stdc++.h>
using namespace std;

//memoization;
int solve(vector<int> &satisfaction,int time,int index,vector<vector<int>> &dp){
    //base case;
    if (index == satisfaction.size())
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];

    int included = (time+1)*satisfaction[index]+solve(satisfaction,time+1,index+1,dp);
    int excluded = solve(satisfaction,time,index+1,dp);
    dp[index][time] = max(included,excluded);
    return dp[index][time];
    }

//tabulation

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>> dp(satisfaction.size()+1,vector<int> (satisfaction.size(),-1));
    return solve(satisfaction,0,0,dp);
}