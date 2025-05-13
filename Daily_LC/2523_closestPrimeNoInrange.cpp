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

vector<int> PrimeSieve(int right){
    int n=sqrt(right);
    vector<int> sieve(n+1, 1);
    sieve[0]=sieve[1]=0;
    for(int i=2;i<=n;i++){
        if(sieve[i]==1){
            for(int j=i*i;j<=n;j+=i){
                sieve[j]=0;
            }
        }
    }
    
    vector<int> ans;
    for(int i=0;i<=n;i++)if(sieve[i]==1)ans.push_back(i);
    return ans;
}

vector<int> closestPrimes(int left, int right){
    
    vector<int> prime = PrimeSieve(right);
    vector<int> segSieve(right-left+1, 1);
    for(auto p: prime){
        
        if(p*p > right)break;
        
        int start = (left/p)*p;
        if(left<=p and p<=right)start=2*p;

        for(int i=start;i<=right;i+=p){
            if(i<left)continue;
            segSieve[i-left]=0;
        }

    }
    
    vector<int> res;
    for(int i=0;i<segSieve.size();i++){
        if(segSieve[i]==1)res.push_back(i+left);
    }
    print(res);
    vector<int> ans(2,-1);
    int temp=INT_MAX;
    for(int i=0;i<res.size()-1;i++){
        int curr=res[i+1]-res[i];
        if(curr<temp){
           temp=curr;
           ans[0]=res[i];
           ans[1]=res[i+1];
        }
    }
    return ans;
}

void solve(){
   int l,r;cin>>l>>r;
   print(closestPrimes(l,r));
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

