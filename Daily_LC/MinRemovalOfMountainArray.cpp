// MinRemovalOfMountainArray.cpp
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

vector<int> LIS(vector<int> &nums){
	int n=nums.size();
	vector<int> dp(n,0);
	for(int i=0;i<n;i++){
		int maxi=0;
		for(int j=0;j<i;j++){
			if(nums[j]<nums[i])
				maxi=max(maxi, dp[j]);
		}
		dp[i]=maxi+1;
	}
	return dp;
}

vector<int> LDS(vector<int> &nums){
	int n=nums.size();
	vector<int> dp(n,0);
	for(int i=n-1;i>=0;i--){
		int maxi=0;
		for(int j=n-1;j>i;j--){
			if(nums[i] > nums[j]){
				maxi=max(maxi, dp[j]);
			}
		}
		dp[i]=maxi+1;
	}
	return dp;
}

bool isPeak(vector<int> &nums, int i){
	if(i==0)return false;
	if(i==nums.size()-1)return false;
	if(nums[i-1]<nums[i] and nums[i]>nums[i+1])return true;
	return false;
}

int minimumMountainRemovals(vector<int>& nums) {
	int n=nums.size();
	vector<int> lis = LIS(nums);
	vector<int> lds = LDS(nums);

	int ans=n;
	for(int i=0;i<n;i++){
		if(isPeak(nums,i)){
			int curr= ( (i+1) - lis[i] ) + ( (n-i) - lds[i]);
			ans=min(ans, curr);
		}
	}
	return ans;
}

void solve(){
	int n;cin>>n;
	vi arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<minimumMountainRemovals(arr)<<endl;
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