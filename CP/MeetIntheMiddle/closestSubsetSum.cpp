// closestSubsetSum.cpp
/* JAI SHREE RAM */

#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#define int 			long long int
#define F 				first
#define S 				second
#define pb 				push_back
#define si 				set<int>
#define vi 				vector<int>
#define pii 			pair<int,int>
#define vpi 			vector<pii>
#define vpp 			vector<pair<int,pii>>
#define mii 			map<int,int>
#define umii			unordered_map<int,int>
#define mpi 			map<pii, int>
#define spi 			set<pii>
#define endl 			"\n"
#define sz(x) 			((int) x.size())
#define all(p) 			p.begin(), p.end()
#define double 			long double
#define que_max 		priority_queue<int>
#define que_min			priority_queue<int, vi, greater<int>>

#ifndef ONLINE_JUDGE
#define bug(...) 		__f (#__VA_ARGS__, __VA_ARGS__)
#endif

#define print(a) 		for(auto x: a)cout<<x<<" ";cout<<endl
#define print1(a) 		for(auto x: a)cout<<x.F<<" "<<x.S<<endl
#define print2(a,x,y) 	for(int i=x;i<y;i++)cout<<a[i]<<" ";cout<<endl

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

vector<int> subset(vector<int> &nums, int start ,int end, int offset){
	vector<int> ss;
	int sz=end-start+1;
	for(int curr=0 ; curr < (1<<sz) ; curr++){
		int x=0,temp=0;
		while(x<32){
			if(curr&(1<<x))temp+=nums[x+offset];
			x++;
		}
		ss.pb(temp);
	}
	return ss;
}

int justSmaller(vector<int> &arr, int key){
	int s=0,e=arr.size()-1,ans=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(arr[m]<=key){
			s=m+1;
			ans=m;
		}else{
			e=m-1;
		}
	}
	return ans;
}

int minAbsDifference(vector<int>& nums, int goal) {
    int n=nums.size();
    vector<int> arr1=subset(nums,0,n/2-1,0);
    vector<int> arr2=subset(nums,n/2,n-1,n/2);
    sort(arr2.begin(),arr2.end());

    int ans=INT_MAX;
    for(auto x: arr1){
    	int temp=goal-x;
    	int y=justSmaller(arr2, temp);
    	if(y>=0)ans=min(ans, abs((x+arr2[y])-goal));
    	if(y+1<arr2.size()){
    		ans=min(ans, abs((x+arr2[y+1])-goal));
    	}

    }
    return ans;
}

void solve(){

	int n,m;cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	// print(subset(arr,0));
	cout<< minAbsDifference(arr, m) <<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif


	int t=1;
	cin>>t;
	while(t--)solve();

#ifndef ONLINE_JUDGE
	clock_t z = clock();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


	return 0;
}