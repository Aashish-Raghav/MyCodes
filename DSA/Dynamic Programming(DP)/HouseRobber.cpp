#include <bits/stdc++.h> 
using namespace std;

//recursion
long long solve(vector<int> valueInHouse,int pos){
    //base case;
    if (pos >= valueInHouse.size())
        return 0;
    int incl = valueInHouse[pos] + solve(valueInHouse,pos+2);
    int excl = solve(valueInHouse,pos+1);

    return max(incl,excl);
}
//space optimisation;
long long int solve2(vector<int>& v){
    long long prev1 = v[0];
    long long prev2 = 0;
    for (int i = 1;i <v.size();i++){
        long long incl = prev2 + v[i];
        long long excl = prev1;
        prev2 = prev1;
        prev1 = max(incl,excl);
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<int> first,second;
    if (n == 1)
        return valueInHouse[0];
    for (int i = 0;i < n;i++){
        if (i != n-1)
            first.push_back(valueInHouse[i]);
        if (i != 0)
            second.push_back(valueInHouse[i]);
    }
    long long ans = max(solve2(first),solve2(second));
    return ans;
}