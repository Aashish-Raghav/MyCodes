#include <iostream>
using namespace std;

long long merge(long long arr[],long long start,long long mid,long long end
        ,long long temp[]){
        long long inver_count = 0;
        long long i = start;
        long long j = mid;
        long long k = start;
        while (i <= mid-1 && j <= end){
            if (arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                
                inver_count += mid - i;
            }           
        }
        
        //remaining elements;
        while (i <= mid-1){
            temp[k++] = arr[i++];
        }
        
        while (j <= end){
            temp[k++] = arr[j++];
        }
        
        //copying merged elements to original array;
        for (i = start;i <= end;i++){
            arr[i] = temp[i];
        }
        
        return inver_count;
    }  
    
    
    long long mergeSort(long long arr[],long long start,long long end,long long temp[]){
        long long inver_count = 0;
        if (start < end){
            long long mid = start + (end - start)/2;
            inver_count += mergeSort(arr,start,mid,temp);
            inver_count += mergeSort(arr,mid+1,end,temp);
            inver_count += merge(arr,start,mid+1,end,temp);
        }
        
        return inver_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long start = 0,end = N-1;
        long long temp[N];
        return mergeSort(arr,start,end,temp);
    }