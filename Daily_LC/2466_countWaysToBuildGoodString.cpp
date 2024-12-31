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

long long mod = 1e9+7;
int getAns(int l, int h, int z, int o, int len, vector<int> &dp){
    if(len>h)return 0;
    
    if(dp[len]!=-1)return dp[len];

    int ans = (len>=l and len<=h)?1:0;
    ans = (ans%mod + (getAns(l,h,z,o,len+z,dp)%mod+getAns(l,h,z,o,len+o,dp)%mod)%mod)%mod;

    return dp[len]=ans;
}

int getAnsTab(int l, int h, int z, int o){
    vector<int> dp(h+2,0);
    for(int i=h;i>=0;i--){
        if(i>=l and i<=h)dp[i]+=1;
        dp[i] += ((i+z <=h ? dp[i+z]%mod : 0) + (i+o <=h ? dp[i+o]%mod : 0))%mod;
    }
    return dp[0];
}

int countGoodStrings(int low, int high, int zero, int one) {
    //vector<int> dp(high+1,-1);
    //return getAns(low,high,zero,one,0,dp);
    return getAnsTab(low,high,zero,one);
}

void solve(){
   //your code
   int low,high,zero,one;cin>>low>>high>>zero>>one;
   cout<<countGoodStrings(low,high,zero,one)<<endl;

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

