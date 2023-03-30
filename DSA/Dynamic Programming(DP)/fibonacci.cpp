#include<bits/stdc++.h>
using namespace std;

//top - down method;
int fib(int n,vector<int> & dp){
    //base case;
    if (n == 0 || n == 1)
        return n;
    //check in dp;
    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

//tabulation method
int fib(int n){
    if (n <= 1)
        return n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2;i <= n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}




int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    int ans = fib(n,dp);
    // cout << endl;
    cout << ans << endl;

    //space optimisation
    int prev1 = 1;
    int prev2 = 0;
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i= 2;i <= n;i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout <<  prev1 << endl;
    return 0;
}