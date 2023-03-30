#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <numeric>
#include <string>
#include <climits>

using namespace std;

#ifndef ONLINE_JUDGE
#define debub(x) cerr << #x << " ";  _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define ll long long int
#define vint vector<int>
#define vlong vector<ll>
#define mod1 1000000007
#define mod2 998244353
#define pi 3.141592653589793238462643
#define loop(i,n) for(auto i = 0;i < n;i++)
#define input1(v,n) for(int i = 0;i < n;i++){int temp; cin >> temp;v.push_back(temp);}
#define input2(v,n) for(long i = 0;i < n;i++){long temp; cin >> temp;v.push_back(temp);}
#define printArr(arr,n) for (auto i = 0;i < n;i++){ cout << arr[i] << " ";} cout << endl;
#define pb push_back
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll power(ll x,ll y,ll m){
    if (y == 0)
        return 1;
    if (y & 1)
        return (x*((power(x,y/2,m)*power(x,y/2,m))%m))%m;
    else    
        return (power(x,y/2,m)*power(x,y/2,m))%m;
} 


ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        ll q = A / M;
        ll t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

ll factorial(ll n){
    if (n == 1 || n == 0)
        return 1;
    return (n*factorial(n-1))%mod1;
}

//-------------------------------------------------------------------------------------------------

void solve(){
    int n,x;
	cin >> n >> x;
	string s;
	cin >> s;
	vint length0;
	int i = 0;
	int sum = 0;
	while (i < n){
		int j = i;
		int count = 0;
		while (j < n && s[j] != '1'){
			count++;
			j++;
		}
		sum += count;
		if (count > 0){
// 			cout << count << endl;
			length0.pb(count);
			i=j;
		}
		else	
			i++;
		count = 0;
	}
	if (sum == 0){
		cout << n << endl;
		return;
	}
	sum = n - sum;
// 	printArr(length0,length0.size());
	loop(i,length0.size()){
		int l = length0[i];
		if (x >= 2*l + 1){
			sum += l;
			x-=(2*l + 1);
		}
		else{
			sum += (x-1)/2;
			break;
		}
	}
	
	cout << sum << endl;
}

//-------------------------------------------------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt","w",stderr);
// #endif   
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
