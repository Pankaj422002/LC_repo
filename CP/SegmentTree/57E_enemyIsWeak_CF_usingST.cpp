// 57E_enemyIsWeak_CF.cpp
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

	void update(int start, int end, int node, int idx, int val){
		if(start == end){
			st[node]+=val;
			return;
		}

		int mid=(start + (end - start)/2);
		if(idx<=mid)
			update(start, mid, 2*node+1, idx, val);
		else 
			update(mid+1, end, 2*node+2, idx, val);

		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}

	void update(int idx, int val){
		update(0,n-1,0,idx,val);
	}

	int query(int start, int end, int node, int l, int r){
		//case1: nooverlap: 
		if(r<start || end<l)return 0;
		//case2: complete overlap: 
		if(l<=start and end<=r)return st[node];

		int mid = (start + (end - start)/2);
		int left = query(start, mid, 2*node+1, l, r);
		int right= query(mid+1, end, 2*node+2, l, r);
		return left+right;
	}

	int query(int l, int r){
		return query(0,n-1,0,l,r);
	}

};

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	vector<int> temp = arr;
	sort(temp.begin(),temp.end());
	unordered_map<int,int> pos;
	for(int i=0;i<n;i++)pos[temp[i]]=i;

	SegmentTree Tree1, Tree2;
	Tree1.init(n);
	Tree2.init(n);

	vector<int> LG;
	for(int i=0;i<n;i++){
		int actualpos_inSortArr = pos[arr[i]];
		LG.pb(Tree1.query(actualpos_inSortArr+1, n-1));
		Tree1.update(actualpos_inSortArr,1);
	}

	vector<int> RS;
	for(int i=n-1;i>=0;i--){
		int actualpos_inSortArr = pos[arr[i]];
		RS.pb(Tree2.query(0,actualpos_inSortArr-1));
		Tree2.update(actualpos_inSortArr,1);
	}

	reverse(RS.begin(),RS.end());

	int ans=0;
	for(int i=1;i<n-1;i++){
		ans+= (LG[i]*RS[i]);
	}

	cout<<ans<<endl;
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