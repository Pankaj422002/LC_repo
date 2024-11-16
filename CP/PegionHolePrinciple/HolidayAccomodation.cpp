// HolidayAccomodation.cpp
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

class Graph{
	vector<vpi> adj;
	int v;
public: 
	Graph(int n){
		this->v=n;
		for(int i=0;i<v;i++){
			vpi temp;

			adj.pb(temp);
		}
	}

	void addEdge(int x, int y, int wt){
		adj[x].pb({y,wt});
		adj[y].pb({x,wt});
	}

	int dfs(int src, vector<bool> &visited, int &fR){
		visited[src]=true;
		int ans=1;
		for(auto nbr: adj[src]){
			if(!visited[nbr.F]){
				int wt = nbr.S;
				int curr = dfs(nbr.F, visited, fR);
				fR += (2*min(curr, v-curr)*wt);
				ans+=curr;
			}
		}
		return ans;
	}

	int getAns(){
		vector<bool> visited(v, false);
		int fR=0;
		dfs(0, visited, fR);
		return fR;
	}

};

int HolidayAccomodation(vector<vi> &edges){
	int e=sz(edges);
	Graph G(e+1);

	for(int i=0;i<e;i++)
		G.addEdge(edges[i][0]-1, edges[i][1]-1, edges[i][2]);

	return G.getAns();

	// int ans=0;
	// for(int i=0;i<e;i++){
	// 	int x=edges[i][0]-1 , y=edges[i][1]-1, wt=edges[i][2];
	// 	vi visited(e+1, false);
	// 	visited[y]=true;
	// 	int left = G.dfs(x, visited);
	// 	ans += (2*min(left, e+1-left)*wt);
	// }
	// return ans;
}

void solve(){
	int n;cin>>n;
	vector<vi> edges(n-1, vector<int>(3));
	for(int i=0;i<n-1;i++){
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
	}

	cout<< HolidayAccomodation(edges)<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif


	int t=1;
	cin>>t;
	int i=1;
	while(t--){
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}

#ifndef ONLINE_JUDGE
	clock_t z = clock();
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


	return 0;
}