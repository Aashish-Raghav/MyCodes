//tsp;
#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int max = 1e9;

int dist[n + 1][n + 1] = {
    { 0, 0, 0, 0, 0 },    { 0, 0, 10, 15, 20 },
    { 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
    { 0, 20, 25, 30, 0 },
};

//atmost 64 places can be tracked...
int visited_all = (1 << (n+1)) - 1;

//recursion
int tsp(int mask,int pos){

    if (visited_all == mask){
        return dist[pos][1];
    }

    int ans = INT_MAX;
    for (int city = 1;city <= n;city++){

        //unvisited city;
        if ((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask | (1 << city),city);
            ans = min(newAns,ans);
        }
    }

    return ans;
}



//keep track;
int dp[1 << (n+1)][n+1];

//memoization;
int tspMemo(int mask,int pos){
    if (visited_all == mask){
        return dist[pos][1];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 1;city <= n;city++){
        //if not visited;
        if ((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask|(1 << city),city);
            ans = min(newAns,ans);
        }
    }

    return dp[mask][pos] = ans;
}

int main(){

    cout << tsp(1,1) << endl;
    for (int i = 0;i <= n;i++){
        for (int j =0;j <= n;j++){
            dp[i][j] = -1;
        }
    }

    cout << tspMemo(1,1) << endl;

    return 0;
}