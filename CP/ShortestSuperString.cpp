// ShortestSuperString.cpp
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
#ifndef ONLINE_JUDGE
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#endif
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

#ifndef ONLINE_JUDGE
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names+1, ',');
    cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}
#endif

const int N = 200005;

int calc(const string& a, const string& b) {
    for (int i = 1; i < a.length(); i++) {
        if (b.substr(0, a.length() - i) == a.substr(i)) {
            return b.length() - a.length() + i;
        }
    }
    return b.length();
}


string shortestSuperstring(vector<string>& A) {
    int n = A.size();
    vector<vector<int>> graph(n, vector<int>(n));
    
    // Build the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = calc(A[i], A[j]);
            graph[j][i] = calc(A[j], A[i]);
        }
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    vector<vector<int>> path(1 << n, vector<int>(n, -1));
    int last = -1, min_len = INT_MAX;
    
    // Start TSP DP
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                int prev = i - (1 << j);
                if (prev == 0) {
                    dp[i][j] = A[j].length();
                } else {
                    for (int k = 0; k < n; k++) {
                        if (dp[prev][k] < INT_MAX && dp[prev][k] + graph[k][j] < dp[i][j]) {
                            dp[i][j] = dp[prev][k] + graph[k][j];
                            path[i][j] = k;
                        }
                    }
                }
            }
            if (i == (1 << n) - 1 && dp[i][j] < min_len) {
                min_len = dp[i][j];
                last = j;
            }
        }
    }
    
    // Build the path
    string result;
    int cur = (1 << n) - 1;
    stack<int> stack;
    while (cur > 0) {
        stack.push(last);
        int temp = cur;
        cur -= (1 << last);
        last = path[temp][last];
    }
    
    // Build the result
    int i = stack.top(); stack.pop();
    result += A[i];
    while (!stack.empty()) {
        int j = stack.top(); stack.pop();
        result += A[j].substr(A[j].length() - graph[i][j]);
        i = j;
    }
    
    return result;
}
    

void solve(){
    int n;cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<shortestSuperstring(arr)<<endl;
}

int32_t main(){

#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    clock_t z = clock();
#endif

    int t=1;
    cin>>t;
    while(t--)solve();

#ifndef ONLINE_JUDGE
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


    return 0;
}