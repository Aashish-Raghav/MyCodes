#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base,vector<int> &next){
    if (base[0] >= next[0] && base[1] >= next[1] && base[2] >= next[2])
        return true;
    else
        return false;
}

int solve(int n,vector<vector<int>> &cuboids){
    vector<int> nextRow(n+1,0);
    vector<int> currRow(n+1,0);

    for (int curr = n-1;curr >= 0;curr--){
        for (int prev = curr-1;prev >= -1;prev--){
            //include 
            int include = 0;
            if (prev == -1 || check(cuboids[curr],cuboids[prev]))
                include = cuboids[curr][2] + nextRow[curr+1];
            
            //exclude
            int exclude = nextRow[prev+1];

            currRow[prev+1] = max(include,exclude);
        }
        nextRow = currRow;
    }

    return nextRow[0];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for (auto &i : cuboids){
        sort(i.begin(),i.end());
    }

    sort(cuboids.begin(),cuboids.end());

    return solve(cuboids.size(),cuboids);
}