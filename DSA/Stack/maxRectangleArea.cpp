#include <iostream>
#include <stack>
#include <vector>
const int size = 4;
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

vector<int> nextSmallerElement(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size());
    s.push(-1);
    for (int i = v.size()-1;i >= 0;i--){
        while (s.top() != -1 && v[s.top()] >= v[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size());
    s.push(-1);
    for (int i = 0;i < v.size();i++){
        while (s.top() != -1 && v[s.top()] >= v[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestAreaOfHistogram(vector<int> &v){
    vector<int> next(v.size());
    next = nextSmallerElement(v);
    vector<int> prev(v.size());
    prev = prevSmallerElement(v);
    // for (int i = 0;i < next.size();i++){
    //     cout << next[i] << " ";
    // }
    // for (int i = 0;i < prev.size();i++){
    //     cout << prev[i] << " ";
    // }
    int maxArea = 0;
    for (int i = 0;i < v.size();i++){
        
        if (next[i] == -1){
            next[i] = v.size();
        }

        int breadth = next[i] - prev[i] - 1;
        int length = v[i];
        // cout << "\nLength : " << length << " breadth : " << breadth << endl;
        // cout << "\narea : " << length*breadth << endl;
        if (length*breadth > maxArea){
            maxArea = length*breadth;
        }
    }
    return maxArea;
}

int MaxRectangleArea(int arr[size][size]){
    vector<int> v(size,0);
    int maxArea = 0;
    for (int i = 0;i < size;i++){
        for (int j = 0;j < size;j++){
            if (arr[i][j] == 0){
                v[j] = 0;
            }
            else    
                v[j] += 1;  //v[j] + 1;
        }
        // for (int k = 0;k < v.size();k++){
        //     cout << v[k] << " ";
        // }
        // cout << endl;
        int area = largestAreaOfHistogram(v);
        // cout << "Row : " << i+1 << " area : " << area << endl;
        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main()
{
    int matrix[size][size] = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout << " ans : " <<  MaxRectangleArea(matrix) << endl;
    
    return 0;
}