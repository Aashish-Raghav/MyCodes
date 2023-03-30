#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int a,int b,vector<vector<int>> visited,vector<vector<int>> &m,int n)
    {
        cout << "i" << endl;
        if (visited[a][b] == 0 && m[a][b] == 1 && (a >= 0 && a < n) && (b >= 0 && b < n) )
            return true;
        return false;
    }
    void solve(int x,int y,vector<vector<int>> visited,vector< vector<int>> &m,
                    int n,string path,vector<string>& ans)
    {
        if (x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        cout << "out" << endl;
        //right();
        if (isSafe(x,y+1,visited,m,n))
        {
            path.push_back('R');
            solve(x,y+1,visited,m,n,path,ans);
            path.pop_back();
        }
        
        //up
        if (isSafe(x-1,y,visited,m,n))
        {
            path.push_back('U');
            solve(x-1,y,visited,m,n,path,ans);
            path.pop_back();
        }
        
        //down
        if (isSafe(x+1,y,visited,m,n))
        {
            path.push_back('D');
            solve(x+1,y,visited,m,n,path,ans);
            path.pop_back();
        }
        
        //left
        if (isSafe(x,y-1,visited,m,n))
        {
            path.push_back('L');
            solve(x,y-1,visited,m,n,path,ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }

void findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int x = 0,y = 0;
        vector< vector<int> > visited = {m};
        //initialising visited array to zero;
        for (int i = 0;i < n;i++)
            for (int j =0;j < n;j++)
                visited[i][j] = 0;
        
        string path = "";
        cout << "IN" << endl;
        solve(x,y,visited,m,n,path,ans);
        sort(ans.begin(),ans.end());
        // return ans;
    }

int main()
{
    vector< vector<int>> m;
    vector<int> v1;
    int temp;
    for (int j = 0;j < 4;j++)
    {
        for (int i = 0;i < 4;i++)
        {
            cin >> temp;
            v1.push_back(temp);
        }
        m.push_back(v1);
    }
    findPath(m,4);
}