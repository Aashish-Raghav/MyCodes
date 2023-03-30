#include <bits/stdc++.h>
using namespace std;

//recursion;
int solve(vector<int> &obstacles,int currLane,int currPos){
    //base case;
    if (currPos == obstacles.size() - 1){
        return 0;
    }
    int jump = 0;
    if (obstacles[currPos+1] != currLane){
        jump = solve(obstacles,currLane,currPos+1);
    }
    else{
        int mini = INT_MAX;
        for (int i = 1;i <= 3;i++){
            if (i == currLane)
                continue;
            int ans1 = INT_MAX;
            if (obstacles[currPos] != i){
                ans1 = solve(obstacles,i,currPos);
            }
            mini = min(mini,ans1);
        }
        jump = 1+ mini;
    }

    return jump;
}

//memoization
int solve1(vector<int> &obstacles,int currLane,int currPos,vector<vector<int>> &dp){
    //base case;
    if (currPos == obstacles.size() - 1){
        return 0;
    }
    if (dp[currLane][currPos] != -1)
        return dp[currLane][currPos];

    int jump = 0;
    if (obstacles[currPos+1] != currLane){
        jump = solve1(obstacles,currLane,currPos+1,dp);
    }
    else{
        int mini = INT_MAX;
        for (int i = 1;i <= 3;i++){
            if (currLane != i && obstacles[currPos] != i){
                mini = min(mini,solve1(obstacles,i,currPos,dp));
            } 
        }
        jump = 1+ mini;
    }
    dp[currLane][currPos] = jump;
    return jump;
}

//tabulation;

int solve2(vector<int> &obstacles){
    vector<vector<int>> dp(4,vector<int> (obstacles.size(),1e9));
    //base case;
    for (int i = 1;i <= 3;i++)
        dp[i][obstacles.size()-1] = 0;

    int ans = 1e9;  //1e9 islie lia kyuki Intmax me +1 nhi kar sakte
    for (int currPos = obstacles.size()-2;currPos>= 0;currPos--){
        for (int currLane = 1;currLane <= 3;currLane++){
            if (obstacles[currPos+1] != currLane){
                dp[currLane][currPos] = dp[currLane][currPos+1];
            }
            else{
                int mini = 1e9;
                for (int i = 1;i <= 3;i++){
                    if (currLane != i && obstacles[currPos] != i){
                        mini = min(mini,dp[i][currPos+1]);//*******
                    } 
                }
                dp[currLane][currPos] = 1+ mini;
            }
        }
    }
    return min(dp[2][0],1+min(dp[1][0],dp[3][0]));
}

//space optimisation
//curr lane and aage wali lane;
int solve3 (vector<int> &obstacles){
        vector<int> curr(4, 1e9);
        vector<int> next(4,0);

        int ans = 1e9;
        for (int currPos = obstacles.size()-2;currPos>= 0;currPos--){
            for (int currLane = 1;currLane <= 3;currLane++){
                if (obstacles[currPos+1] != currLane){
                    curr[currLane] = next[currLane];
                }
                else{
                    int mini = 1e9;
                    for (int i = 1;i <= 3;i++){
                        if (currLane != i && obstacles[currPos] != i){
                            mini = min(mini,next[i]);//*******
                        } 
                    }
                    curr[currLane] = 1+ mini;
                }
            }
            next = curr;
        }
        return min(next[2],1+min(next[1],next[3]));
    }

int minSideJumps(vector<int>& obstacles) {
    return solve(obstacles,2,0);
}