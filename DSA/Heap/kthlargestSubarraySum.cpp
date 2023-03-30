#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getKthLargest1(vector<int> &arr, int k)
{
	
	vector<int> temp;
	int sum = 0;
	int n = arr.size();
	for (int i = 0;i < n;i++){
		sum = arr[i];
		for (int j = i+1;j < n;j++){
			temp.push_back(sum);
			sum += arr[j];
		}
		temp.push_back(sum);
	}

	sort(temp.begin(),temp.end());

	return temp[temp.size()-k];

}


