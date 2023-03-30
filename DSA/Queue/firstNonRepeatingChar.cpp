#include <iostream>
#include <queue>
#include <map>
using namespace std;

template <class T>
void printQueue(queue<T> q){
    cout << "Your Queue : " << endl;
    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}
string FirstNonRepeating(string s){
    map<char,int> count;
    queue<char> q;
	int n = s.size();
	string ans = "";
	for (int i = 0;i < n;i++){
	    char ch = s[i];
		count[ch]++;
		q.push(ch);
		while (!q.empty()){
            if (count[q.front()] > 1)
	            q.pop();
	        else{
                ans.push_back(q.front());
	                break;
            }
        }
        if (q.empty())
            ans.push_back('#');
    }		    
    return ans;
}

int main(){
    return 0;
}