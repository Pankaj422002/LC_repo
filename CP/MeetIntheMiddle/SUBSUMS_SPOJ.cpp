// SUBSUMS_SPOJ.cpp
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

vector<int> subset(vector<int> &arr, int s, int e, int offset){
	vector<int> ans;

	int sz=e-s+1;
	for(int st=0;st < (1<<sz) ;st++){

		int curr=0;
		int i=0;
		while(i<sz){
			if((1<<i)&st)curr+=arr[i+offset];
			i++;
		}
		ans.pb(curr);

	}

	return ans;
}

int NoofsubsetsInb_w_ab(vector<int> &arr, int a, int b){

	int n=sz(arr);
	vector<int> arr1 = subset(arr,0,n/2-1,0);
	vector<int> arr2 = subset(arr,n/2,n-1,n/2);

	sort(arr2.begin(),arr2.end());

	int ans=0;
	for(int i=0;i<arr1.size();i++){
		int x=arr1[i];
		ans += (upper_bound(arr2.begin(),arr2.end(),b-x) - lower_bound(arr2.begin(),arr2.end(),a-x));
	}

	return ans;
}

void solve(){
	int n,a,b;cin>>n>>a>>b;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	cout<<NoofsubsetsInb_w_ab(arr,a,b)<<endl;

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