#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for (int i = 0;i < k;i++)
            pq.push(arr[i]);
            
        for (int i = k;i <= r;i++){
            int top = pq.top();
            if (arr[i] < top){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }

int main(){


    
    return 0;
}