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


// bool isSameSetBits(int a, int b){
//     int cnt1=0,cnt2=0;
//     while(a){
//         cnt1 += ((a&1)==0 ? 0 : 1);
//         a>>=1;
//     }
//     while(b){
//         cnt2 += ((b&1)==0 ? 0 : 1);
//         b>>=1;
//     }
//     return cnt1==cnt2;
// }
// bool BubbleSort(vector<int> &nums){
//     int n=nums.size();
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-1-i;j++){

//             if(nums[j]>nums[j+1]){
//                 if(!isSameSetBits(nums[j],nums[j+1]))return false;
//                 swap(nums[j],nums[j+1]);
//             }

//         }
//     }
//     return true;
// }

int popcount(int a){
    int ans=0;
    while(a){
        ans+= ((a&1)==0 ? 0: 1);
        a>>=1;
    }
    return ans;
}

bool getAns(vector<int> &nums){
    int n = nums.size();
    int pmax = 0, cmin = 0, cmax = 0;
    int pcnt = 0;
    for (int v : nums) {
        if (int ccnt = popcount(v); pcnt == ccnt) {
            cmin = min(cmin, v);
            cmax = max(cmax, v);
        } else if (cmin < pmax) {
            return false;
        } else {
            pmax = cmax;
            cmin = cmax = v;
            pcnt = ccnt;
        }
    }
    return cmin >= pmax;
}

bool canSortArray(vector<int>& nums) {
    
    // return BubbleSort(nums);
    return getAns(nums);

}

void solve(){
   //your code
   int n;cin>>n;
   vector<int> nums(n);
   for(int i=0;i<n;i++)cin>>nums[i];
   cout<<canSortArray(nums)<<endl;
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

