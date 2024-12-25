// Test.cpp
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


struct LazySegmentTree{
	int n;
	vector<int> st;
	vector<int> lz;

	void init(int _n){
		this->n = _n;
		st.resize(4*n, 0);
		lz.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector<int> &nums){
		if(start == end){
			st[node]=nums[start];
			return;
		}

		int mid=(start+end)/2;
		build(start,mid,2*node+1,nums);
		build(mid+1,end,2*node+2,nums);

		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}

	void build(vector<int> &nums){
		build(0,n-1,0,nums);
	}

	void Update(int start, int end, int node, int l, int r, int val){
		if(start>r || end<l)return;

		//done the pending updates: 
		if(lz[node] != 0){
			st[node] += (lz[node]*(end-start+1));
			if(start != end){
				lz[2*node+1]+=lz[node];
				lz[2*node+2]+=lz[node];
			}
			lz[node]=0;
		}

		if(l<=start and end<=r){
			st[node] += (val*(end-start+1));
			if(start != end){
				lz[2*node+1] += val;
				lz[2*node+2] += val;
			}
			return;
		}

		int mid=(start+end)/2;
		Update(start,mid,2*node+1,l,r,val);
		Update(mid+1,end,2*node+2,l,r,val);

		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}

	void Update(int l, int r, int val){
		Update(0,n-1,0,l,r,val);
	}

	int query(int start, int end, int node, int idx){
		//check if there is pending update: 
		if(lz[node]!=0){
			st[node] += (lz[node]*(end-start+1));
			if(start != end){
				lz[2*node + 1] += lz[node];
				lz[2*node + 2] += lz[node];
			}
			lz[node]=0;
		}

		if(start == end){
			return st[node];
		}

		int mid=(start + end)/2;
		if(idx<=mid){
			return query(start, mid, 2*node+1,idx);
		}else{
			return query(mid+1, end, 2*node+2,idx);
		}

	}

	int query(int idx){
		return query(0,n-1,0,idx);
	}

};

vector<int> RangeUpdate(int n, vector<int> nums, vector<vector<int>> queries){
    vector<int> ans;
    LazySegmentTree Tree;

    Tree.init(n);
    Tree.build(nums);

    for(auto it: queries){
    	int type=it[0];
    	if(type == 1){
    		Tree.Update(it[1]-1,it[2]-1,it[3]);
    	}else if(type == 2){
    		ans.push_back(Tree.query(it[1]-1));
    	}
    }

    return ans;
}

void solve(){
	int n,m;cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	vector<vector<int>> query;
	while(m--){
		int type;cin>>type;
		if(type == 1){
			int x,y,u;cin>>x>>y>>u;
			vector<int> temp = {type, x, y, u};
			query.push_back(temp);
		}else if(type == 2){
			int pos;cin>>pos;
			vector<int> temp = {type, pos};
			query.push_back(temp);
		}
	}

	vector<int> ans = RangeUpdate(n, arr, query);
	print(ans);

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