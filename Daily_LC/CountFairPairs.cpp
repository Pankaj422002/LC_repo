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

int FindL_idx(vector<int> &nums, int k, int curr){
    int s=0,e=curr-1, ans=-1;
    while(s<=e){
        int m=(s+e)/2;
        if(nums[m]>=k){
            ans=m;
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return ans;
}

int FindR_idx(vector<int> &nums, int k, int curr){
    int s=0,e=curr-1, ans=-1;
    while(s<=e){
        int m=(s+e)/2;
        if(nums[m]<=k){
            ans=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return ans;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(),nums.end());

    long long ans=0;
    int n=nums.size();
    
    for(int i=1;i<n;i++){
        int l_val = lower-nums[i];
        int r_val = upper-nums[i];

        //l_idx just grt then eq to l_val
        int l_idx = FindL_idx(nums, l_val, i);

        //r_idx just smaller then eq to r_val
        int r_idx = FindR_idx(nums, r_val, i);

        //find values b/w l_idx, r_idx: 
        if(l_idx!=-1 and r_idx!=-1){
            ans += (r_idx-l_idx+1);
        }

    }

    return ans;
}


void solve(){
   //your code
   int n,l,r;cin>>n>>l>>r;
   vector<int> nums(n);
   for(int i=0;i<n;i++)cin>>nums[i];

   cout<< countFairPairs(nums, l, r) <<endl;
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

