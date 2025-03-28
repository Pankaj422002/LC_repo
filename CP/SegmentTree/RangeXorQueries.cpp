// RangeXorQueries.cpp
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

struct SegmentTree{
	vector<int> st;
	int n;
	void init(int _n){
		this->n = _n;
		st.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector<int> &arr){
		if(start == end){
			st[node]=arr[start];
			return;
		}

		int mid=(start+end)/2;
		build(start, mid, 2*node+1, arr);
		build(mid+1, end, 2*node+2, arr);
		st[node] = st[2*node+1] ^ st[2*node+2];
		return;
	}

	void build(vector<int> &arr){
		build(0,n-1,0,arr);
	}

	int query(int start, int end, int node, int l, int r){
		//case1: nooverlap: 
		if(end<l || r<start)return 0;

		//case2: complete overlap: 
		if(l<=start and end<=r)return st[node];

		int mid=(start+end)/2;
		int left=query(start, mid, 2*node+1, l, r);
		int right=query(mid+1, end, 2*node+2, l, r);

		return left^right;
	}

	int query(int l, int r){
		return query(0, n-1, 0, l, r);
	}
};

vector<int>fn(int n, vector<int>a, vector<vector<int>> queries){
    SegmentTree Seg;
    Seg.init(a.size());
    Seg.build(a);

    vector<int> ans;
    for(auto it: queries){
    	ans.push_back(Seg.query(it[0]-1, it[1]-1));
    }
    return ans;
}

void solve(){
	int n,m;cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	vector<vector<int>> query;
	while(m--){
		int l,r;cin>>l>>r;
		vector<int> temp={l,r};
		query.push_back(temp);
	}
	print(fn(n,arr,query));
}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif


	int t=1;
	// cin>>t;
	while(t--)solve();

#ifndef ONLINE_JUDGE
	clock_t z = clock();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


	return 0;
}