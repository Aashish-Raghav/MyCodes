#include <bits/stdc++.h> 
using namespace std;

unordered_map<int,bool> rowLeft;
unordered_map<int,bool> lowerDiag;
unordered_map<int,bool> upperDiag;

void markTrue(int row,int col){
	rowLeft[row] = 1;
	lowerDiag[row+col] = 1;
	upperDiag[col-row] = 1;
}
void markFalse(int row,int col){
	rowLeft[row] = 0;
	lowerDiag[row+col] = 0;
	upperDiag[col-row] = 0;
}

void addToAns(vector<vector<int>> &board,vector<vector<int>>&ans){
	vector<int> temp;
	for (auto i : board)
		for (auto j : i)
			temp.push_back(j);
	ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board,int n){
	return !rowLeft[row] && !lowerDiag[row+col] && !upperDiag[col-row];

}

void solve(int col,vector<vector<int>> &board,vector<vector<int>>&ans,int n){
	//base case;
	if (col == n){
		addToAns(board,ans);
		return;
	}

	for (int row = 0;row < n;row++){
		if (isSafe(row,col,board,n)){
			board[row][col] = 1;
			markTrue(row,col);
			solve(col+1,board,ans,n);
			board[row][col] = 0;
			markFalse(row, col);
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int> > board(n,vector<int> (n,0));
	vector<vector<int> >  ans;

	int col = 0;
	solve(col,board,ans,n);

	return ans;
}