#include <iostream>
#include <vector>
#define modulo 1000000007
using namespace std;

//memomization;
long long solve(long long n,vector<long> &dp){
    //base case;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    //step 3;
    if (dp[n] != -1)
        return dp[n]%modulo;
    

    //step2 
    dp[n] = (n-1)*(solve(n-2,dp)%modulo + solve(n-1,dp)%modulo)%modulo;
    return dp[n]%modulo;
}

//simple recursionx
long long solve2(long long n){
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    return (n-1)*(solve2(n-2)+solve2(n-1));
}

long long int countDerangements(int n) {
    //step 1;
    vector<long> dp(n+1,-1);
    dp[n] = solve(n,dp);
    return dp[n];
}