#include <iostream>
#include <vector>
using namespace std;
void solve(string s,int index,vector<string> & ans)
{
    //base case;
    if (index >= s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int j = index;j < s.size();j++)
    {
        swap(s[index],s[j]);
        solve(s,index+1,ans);

        //back tracking;

        //if i don't back track then it is giving the right ans;
        // swap(s[index],s[j]);
    }
}
int main()
{
    string s = "abc";
    string output;
    int index = 0;
    vector<string> ans;
    solve(s,index,ans);
    for (int i = 0;i < ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}