// 827_makingALargeIsland.cpp
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

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool ispossible(int x, int y, int n){
	if(x>=0 and x<n and y>=0 and y<n)return true;
	return false;
}

void bfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &grid, int &cntr, umii &mp){
	
	int cnt=0,n=grid.size();

	queue<pii> q;
	q.push({x,y});
	visited[x][y]=true;
	grid[x][y]=cntr;

	while(!q.empty()){
		pii temp = q.front();q.pop();
		int i=temp.F, j=temp.S;

		cnt++;

		for(int k=0;k<4;k++){
			int ni=i+dx[k], nj=j+dy[k];

			if(ispossible(ni,nj,n) and grid[ni][nj]==1){
				q.push({ni,nj});
				visited[ni][nj]=true;
				grid[ni][nj]=cntr;
			}

		}

	}

	mp[cntr]=cnt;

}

void print_arr(vector<vector<int>> &arr){
	for(auto it: arr){
		for(auto ele: it)cout<<ele<<" ";
		cout<<endl;
	}
}

int largestIsland(vector<vector<int>>& grid) {
    int n=grid.size();

    int ans=0,cntr=2;
    umii mp;
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(!visited[i][j] and grid[i][j]==1){
    			bfs(i,j,visited,grid,cntr,mp);
                ans = max(ans, mp[cntr]);
    			cntr++;
    		}
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(grid[i][j] == 0){
    			si s;
    			for(int k=0;k<4;k++){
    				int nbr_i = i+dx[k], nbr_j = j+dy[k];
    				if(ispossible(nbr_i,nbr_j,n) and grid[nbr_i][nbr_j]!=0)
    					s.insert(grid[nbr_i][nbr_j]);
    			}

    			int curr_ans=0;
    			for(auto it: s)curr_ans+=mp[it];

    			ans = max(ans, curr_ans+1);

    		}
    	}
    }

    return ans;
}


void solve(){

	int n;cin>>n;
	vector<vector<int>> grid(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>grid[i][j];

	cout<<largestIsland(grid)<<endl;

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