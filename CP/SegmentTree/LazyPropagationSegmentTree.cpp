// LazyPropagationSegmentTree.cpp
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

struct SegmentLazyTree{
	int n;
	vector<int> st, lazy;
	void init(int n){
		this->n = n;
		st.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector<int> &arr){
		if(start==end){
			st[node]=arr[start];
			return;
		}
		int mid=(start+end)/2;
		build(start,mid,2*node+1,arr);
		build(mid+1,end,2*node+2,arr);
		st[node]=st[2*node+1]+st[2*node+2];

		return;
	}

	void build(vector<int> &arr){
		build(0,n-1,0,arr);
	}

	int query(int start, int end, int node, int l, int r){
		//case:1: nooverlap: 
		if(start>r || end<l)return 0;

		//done the pending updates first: 
		if(lazy[node]!=0){
			st[node] += lazy[node]*(end-start+1);
			if(start!=end){
				lazy[2*node+1] += lazy[node];
				lazy[2*node+2] += lazy[node];
			}
			lazy[node]=0;
		}

		//case:2: completeoverlap: 
		if(l<=start and end<=r){
			return st[node];
		}

		//case:3: partialoverlap:
		int mid=(start+end)/2;
		int left = query(start,mid,2*node+1,l,r);
		int right = query(mid+1,end,2*node+2,l,r);

		return left+right;
	}

	int query(int l, int r){
		return query(0,n-1,0,l,r);
	}

	void update(int start, int end, int node, int l, int r, int val){
		//case:1:no overlapping: 
		if(start>r || end<l)return;

		//done the pending updates first: 
		if(lazy[node]!=0){
			st[node] += lazy[node]*(end-start+1);
			if(start!=end){
				lazy[2*node+1] += lazy[node];
				lazy[2*node+2] += lazy[node];
			}
			lazy[node]=0;
		}

		//case:2: complete overlapping: 
		if(l<=start and end<=r){
			st[node] += val*(end-start+1);
			if(start!=end){
				lazy[2*node+1] += val;
				lazy[2*node+2] += val;
			}
			return;
		}

		//case:3: partial overlapping: 
		int mid=(start+end)/2;
		update(start,mid,2*node+1,l,r,val);
		update(mid+1,end,2*node+2,l,r,val);

		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}

	void update(int l, int r, int val){
		update(0,n-1,0,l,r,val);
	}

};

void solve(){
	int n,m;cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	SegmentLazyTree Seg;
	Seg.init(arr.size());
	Seg.build(arr);

	while(m--){
		int x,y,z;cin>>x>>y>>z;
		if(x==0){
			cout<<Seg.query(y,z)<<endl;
		}else if(x==1){
			int val;cin>>val;
			Seg.update(y,z,val);
		}
	}
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