#include <bits/stdc++.h>
using namespace std;
int solve(int n,vector<int> &days,vector<int> &cost,int index){
    //base case;
    if (index >= n)
        return 0;

    int option1 = cost[0] + solve(n,days,cost,index+1);
    int i;
    for (i = index;i < n && days[i] < days[index] + 7;i++);
    int option2 = cost[1] + solve(n,days,cost,i);
    
    for (i = index;i < n && days[i] < days[index] + 30;i++);
    int option3 = cost[2] + solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}


int solve1(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp){
    //base case;
    if (index >= n)
        return 0;

    //step 3;
    if (dp[n] != -1)
        return dp[n];
    
    int option1 = cost[0] + solve1(n,days,cost,index+1,dp);
    int i;
    for (i = index;i < n && days[i] < days[index] + 7;i++);
    int option2 = cost[1] + solve1(n,days,cost,i,dp);
    
    for (i = index;i < n && days[i] < days[index] + 30;i++);
    int option3 = cost[2] + solve1(n,days,cost,i,dp);

    //step 2;
    dp[index] =  min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    //space optimisation;
    int ans =0;
    queue<pair<int,int>> monthly;
    queue<pair<int,int>> weekly;
    for (auto day : days){
        //step 1; remove expired days;
        while (!monthly.empty() && monthly.front().first + 30 <= day)   
            monthly.pop();
        while (!weekly.empty() && weekly.front().first + 7 <= day)
            weekly.pop();

        //step 2 push current day cost;
        weekly.push({day,ans + cost[1]});
        monthly.push({day,ans + cost[2]});

        //step 3 : update ans;
        ans = min(ans+cost[0],min(monthly.front().second,weekly.front().second));
    }
    return ans;
}