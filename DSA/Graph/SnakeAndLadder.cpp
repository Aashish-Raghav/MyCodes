#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>  flattenBoard(n*n+1);

        int pos = 1;
        bool leftToRight = 1;
        for (int i = n-1; i >= 0;i--){
            if (leftToRight){
                for (int j = 0;j < n;j++)
                    flattenBoard[pos++] = board[i][j];
            }
            else{
                for (int j = n-1;j >= 0;j--)
                    flattenBoard[pos++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }

        vector<int> dist(n*n + 1,-1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            if (curr == n*n)
                return dist[curr];

            for (int i = 1;i <= 6;i++){
                int next = curr + i;
                if (next > n*n)
                    continue;

                //snake and ladder exist;
                if (flattenBoard[next] != -1)
                    next = flattenBoard[next];
    
                if (dist[next] == -1){
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }

        }
        return -1;
    }
};