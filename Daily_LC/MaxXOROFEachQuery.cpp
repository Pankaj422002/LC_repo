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

// vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//     int n=nums.size();
//     vector<int> prefixXOR(n,0);
//     prefixXOR[0]=nums[0];
//     for(int i=1;i<n;i++)prefixXOR[i]=prefixXOR[i-1]^nums[i];

//     vector<int> ans;
//     for(int i=n-1;i>=0;i--){
//         int curr = prefixXOR[i], k=maximumBit-1, temp=0;
//         while(k>=0){
//             if((curr&(1<<k)) == 0){
//                 temp+= (1<<k);
//             }
//             k--;
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size(),xorr = nums[0],maxxorr = pow(2,maximumBit)-1;
    for(int i=1;i<n;i++)xorr ^= nums[i];
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i] = xorr^maxxorr;
        xorr ^= nums[n-1-i];
    }
    return ans;
}


void solve(){
   //your code
   int n,k;cin>>n>>k;
   vector<int> arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   
   print(getMaximumXor(arr, k));
   
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

