#include <iostream>
#include <vector>
using namespace std;

void solve(string digits,vector<string> &ans,string output,int index,string* mapping)
{
    //base case;
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }

    int num = digits[index] - '0';
    string temp = mapping[num];

    for (int i = 0;i < temp.size();i++)
    {
        output.push_back(temp[i]);
        solve(digits,ans,output,index+1,mapping);
        //back track;
        output.pop_back();
    }
}

int main()
{
    string digits = "";
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,ans,output,index,mapping);
    for (int i = 0;i < ans.size();i++)
        cout << ans[i] << " ";
    
    cout << endl;
}