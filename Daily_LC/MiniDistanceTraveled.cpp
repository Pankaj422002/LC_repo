// MiniDistanceTraveled.cpp
/* JAI SHREE RAM */

#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
// #define int             long long int
#define ll 				long long
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

long long getAns(vector<int> &robot, vector<int> &finalFactory, int i, int j, vector<vector<long long>> &dp){
    if(i==-1)return 0;
    if(j==-1)return LLONG_MAX;

    if(dp[i][j]!=-1)return dp[i][j];

    
    long long ifconsider = getAns(robot, finalFactory, i-1, j-1, dp);

    if(ifconsider!=LLONG_MAX)
        ifconsider+=abs(finalFactory[j]-robot[i]);

    long long ifnotconsider = getAns(robot, finalFactory, i, j-1, dp);

    return dp[i][j]=min(ifconsider, ifnotconsider);
}

long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(robot.begin(),robot.end());
    vector<int> finalFactory;
    for(int i=0;i<factory.size();i++){
        while(factory[i][1]--)
            finalFactory.push_back(factory[i][0]);
    }
    sort(finalFactory.begin(),finalFactory.end());

    vector<vector<long long>> dp(robot.size(), vector<long long>(finalFactory.size(), -1));
    return getAns(robot, finalFactory, robot.size()-1, finalFactory.size()-1, dp);
}

void solve(){
    int n,m;cin>>n>>m;
    vi robot(n);
    for(int i=0;i<n;i++)cin>>robot[i];
    vector<vi> factory;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		vi temp = {x, y};
		factory.push_back(temp);
	}

	cout<<minimumTotalDistance(robot, factory)<<endl;

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