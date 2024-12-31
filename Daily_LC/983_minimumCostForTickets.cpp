// 983_minimumCostForTickets.cpp
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

int BS(vector<int> &days, int key){
	int n=days.size();
	int s=0,e=n-1,ans=days[0];

	while(s<=e){
		int mid = (s+e)/2;

		if(days[mid]<=key){
			ans=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}

	}
	return ans;
}

int getAns(vector<int> &days, vector<int> &costs, int i, vector<int> &dp){
	if(i>=days.size())return 0;

	if(dp[i]!=-1)return dp[i];

	int op1 = costs[0]+getAns(days,costs,i+1,dp);

	int nxt_i = BS(days,days[i]+6);
	int op2 = costs[1]+getAns(days,costs,nxt_i+1,dp);

	int nxt_j = BS(days,days[i]+29);
	int op3 = costs[2]+getAns(days,costs,nxt_j+1,dp);

	return dp[i]=min({op1,op2,op3});
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
	sort(days.begin(),days.end());


	int n=days.size();
	vector<int> dp(n+1,-1);
	return getAns(days,costs,0,dp);
}


void solve(){
	int n,m;cin>>n>>m;
	vector<int> days(n);
	vector<int> costs(m);

	for(int i=0;i<n;i++)cin>>days[i];
	for(int i=0;i<m;i++)cin>>costs[i];

	cout<<mincostTickets(days,costs)<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
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