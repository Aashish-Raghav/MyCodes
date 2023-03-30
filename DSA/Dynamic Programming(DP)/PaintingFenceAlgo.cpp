#include <bits/stdc++.h> 
using namespace std;
#define modulo 1000000007
int add(int a,int b){
    return (a%modulo + b%modulo)%modulo;
}

int mult(int a,int b){
    return ((a%modulo)*1LL *(b%modulo))%modulo;
}

//Memoization
int solve1(int n,int k,vector<int> &dp){
    //base case;
    if (n == 1){
        return k%modulo;   
    }
    if (n == 2){ 
        return add(k,mult(k,k-1));
    }

    //step 3;
    if (dp[n] != -1)
        return dp[n];

    //step 2;
    dp[n] = add(mult(k-1,solve1(n-1,k,dp)),mult(k-1,solve1(n-2,k,dp)));
    return dp[n];
}

//Tabulation
int solve2(int n,int k){
    vector<int> dp(n+1,-1);
    dp[1] = k%modulo;
    dp[2] = add(k,mult(k,k-1));

    for (int i = 3;i<=n;i++){
        dp[i] = add(mult(k-1,dp[i-1]),mult(k-1,dp[i-2]));
    }

    return dp[n];
}

// space optimization
int solve3(int n,int k){
    int prev2 = k%modulo;
    int prev1 = add(k,mult(k,k-1));

    for (int i = 3;i<=n;i++){

        int curr = mult(k-1,add(prev1,prev2));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


int numberOfWays(int n, int k) {
    //step 1;
    vector<int> dp(n+1,-1);
    return solve1(n,k,dp);
}
