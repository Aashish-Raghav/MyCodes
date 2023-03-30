//you are given a set find power set of that subset
#include <iostream>
#include <vector>
using namespace std;

void powerSet(vector<vector <int>> &ans,vector<int> output,int index,vector<int> arr)
{
    //base case;
    if (index >= arr.size()){
        ans.push_back(output);
        return;
    }
    
    //exclude part
    powerSet(ans,output,index+1,arr);
    
    //include part
    output.push_back(arr[index]);
    powerSet(ans,output,index+1,arr);
}

int main()
{
    vector<vector<int> > ans;
    vector<int> output;
    vector<int> arr = {1,2,3,4};
    int index = 0;
    powerSet(ans,output,index,arr);

    // cout << ans.size() << endl;s
    for (int i = 0;i < ans.size();i++)
    {
        for (int j = 0;j < ans[i].size();j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}