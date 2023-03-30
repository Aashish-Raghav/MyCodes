#include <iostream>
#include <vector>
using namespace std;

void subsequence(string s,string temp,vector<string> &ans,int index)
{
    //base case
    if (index >= s.size())
    {
        ans.push_back(temp);
        return;
    }
    
    //exclude
    subsequence(s,temp,ans,index+1);

    //include
    temp.push_back(s[index]);
    subsequence(s,temp,ans,index+1);    

}

int main()
{
    string s = "abc";
    string temp;
    vector<string> ans;
    int index = 0;
    subsequence(s,temp,ans,index);

    for (int i = 0;i < ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
}