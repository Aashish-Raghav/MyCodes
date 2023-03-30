#include<iostream>
#include <limits.h>
#include <vector>

using namespace std;

//recursion faster than 99.9%
// mine approach
void solve(int n,int x,int y,int z,int count,int &maxi){
	//base case
	if (n == 0){
		maxi = max(count,maxi);
		return;
	}
	if (n < 0)
		return;
	

	//cut in x;
	solve(n-x,x,y,z,count+1,maxi);
	if (y != x)
		solve(n-y,x,y,z,count+1,maxi);
	if (z != x && z != y)
		solve(n-z,x,y,z,count+1,maxi);

}

//memoiztion bhaiya approach 
//faster than 12.48%
int solve2(int n,int x,int y,int z,vector<int> &dp){
	//base case
	if (n == 0){
		return 0;
	}
	if (n < 0)
		return INT_MIN;

	//step 3;
	if (dp[n] != -1)	
		return dp[n];


	int a = solve2(n-x,x,y,z,dp) + 1;
	int	b = solve2(n-y,x,y,z,dp) + 1;
	int c = solve2(n-z,x,y,z,dp) + 1;
	
	//step 2;
	dp[n] = max(a,max(b,c));
	return dp[n];
}


//tabulation
int solve3(int n,int x,int y,int z){
	int value = 0;
	vector<int> dp(n+1,INT_MIN);
	dp[0] = 0;
	for (int i = 1;i <= n;i++){
		if (i - x >= 0)
			dp[i] = max(dp[i],dp[i-x]+1);
		if (i - y >= 0)
			dp[i] = max(dp[i],dp[i-y]+1);
		if (i - z >= 0)
			dp[i] = max(dp[i],dp[i-z]+1);
	}

	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	int maxi = 0;
	solve(n,x,y,z,0,maxi);
	return maxi;
}