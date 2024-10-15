// HistogramMaxRectangularArea.cpp
/* JAI SHREE RAM */

#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#define int             long long int
#define F               first
#define S               second
#define pb              push_back
#define si              set<int>
#define vi              vector<int>
#define pii             pair<int,int>
#define vpi             vector<pii>
#define vpp             vector<pair<int,pii>>
#define mii             map<int,int>
#define mpi             map<pii, int>
#define spi             set<pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define double          long double
#define que_max         priority_queue<int>
#define que_min         priority_queue<int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for(auto x: a)cout<<x<<" ";cout<<endl
#define print1(a)       for(auto x: a)cout<<x.F<<" "<<x.S<<endl
#define print2(a,x,y)   for(int i=x;i<y;i++)cout<<a[i]<<" ";cout<<endl

inline int power(int a, int b){
    int x=1;
    while(b){
        if(b&1)x=x*a;
        a=a*a;
        b=b>>1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names+1, ',');
    cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}

const int N = 200005;

vector<long long> FindRight(vector<long long> &arr){
    int n=arr.size();
    vector<long long> ans(n, n);
    stack<long long> s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans[i]=n;
            s.push(i);
        }else{
            while(!s.empty() and arr[s.top()] >= arr[i])s.pop();
            if(s.empty())ans[i]=n;
            else ans[i]=s.top();
            s.push(i);
        }
    }
    return ans;
}

vector<long long> FindLeft(vector<long long> &arr){
    int n=arr.size();
    vector<long long> ans(n, -1);
    stack<long long> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            ans[i]=-1;
            s.push(i);
        }else{
            while(!s.empty() and arr[s.top()] >= arr[i])s.pop();
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(i);
        }
    }
    return ans;
}

long long getMaxArea(vector<long long> &hist) {
    // Your code here
    vector<long long> left_sm = FindLeft(hist);
    vector<long long> right_sm = FindRight(hist);
    
    long long ans=0,n=hist.size();
    for(int i=0;i<n;i++){
        long long curr_ht = hist[i];
        long long curr_width = right_sm[i]-left_sm[i]-1;
        ans = max(ans, curr_ht*curr_width);
    }
    return ans;
}

void solve(){
	int n;cin>>n;
	vector<long long> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
    cout<<getMaxArea(arr)<<endl;
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
#endif

    clock_t z = clock();

    int t=1;
    cin>>t;
    while(t--)solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}