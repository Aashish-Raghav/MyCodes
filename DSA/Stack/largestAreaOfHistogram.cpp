#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template <typename T>
void printStack(stack<T> s)
{
    cout << "Your Stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

vector<int> nextSmallerElement(vector<int> arr,int size){
    stack<int> s;
    vector<int> ans(size);
    s.push(-1);
    for (int i = size-1;i >= 0;i--){
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr,int size){
    stack<int> s;
    vector<int> ans(size);
    s.push(-1);
    for (int i = 0;i < size;i++){
        while (s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int MaxAreaOfHistogram(vector<int> heights,int size){
    int maxArea = -1;
    //nextSmaller;
    vector<int> next(size);
    next = nextSmallerElement(heights,size);
    vector<int> prev(size);
    prev = prevSmallerElement(heights,size);
    for (int i = 0;i < next.size();i++){
        cout << next[i] << " ";
    }
    for (int i = 0;i < prev.size();i++){
        cout << prev[i] << " ";
    }

    for (int i = 0;i < size;i++){
        int length = heights[i];
        if (next[i] == -1)
            next[i] = size;
        int breadth = next[i] - prev[i] -1;
        if (length* breadth > maxArea)
            maxArea = length* breadth;
        // cout << "maxArea : " << length* breadth << endl;
    }
    return maxArea;
}

int main()
{   
    vector<int> h;
    int temp;
    cin >> temp;
    while (temp != -1){
        h.push_back(temp);
        cin >> temp;
    }
    // for (int i = 0;i < h.size();i++){
    //     cout << h[i] << " ";
    // }
    cout << endl;
    cout << MaxAreaOfHistogram(h,h.size()) << endl;
    return 0;
}