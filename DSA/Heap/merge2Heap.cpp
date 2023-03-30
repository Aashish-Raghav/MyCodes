#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &v,int size,int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        
        if (left < size && v[left] > v[largest])
            largest = left;
        if (right < size && v[right] > v[largest])
            largest = right;
        
        if (largest != i){
            swap(v[i],v[largest]);
            heapify(v,size,largest);
        }
    }

//1 base indexing;
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> v;
        for (auto i : a)
            v.push_back(i);
            
        for (auto i : b)
            v.push_back(i);
        
        //0 base indexing
        int size = v.size();
        for (int i = size/2 - 1;i >= 0;i--){
            heapify(v,size,i);
        }
        
        return v;  
    }

int main(){

}