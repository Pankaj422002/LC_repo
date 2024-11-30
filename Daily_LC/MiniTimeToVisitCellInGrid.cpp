// MiniTimeToVisitCellInGrid.cpp
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
#define pipii 			pair<long long,pair<int,int>>

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

int dx[4]={0, -1, 0, 1};
int dy[4]={1, 0, -1, 0};

int fn(int a, int b){
    if((a%2 == 0 and b%2 == 0) or (a%2 != 0 and b%2 !=0))
        return b+1;
    return b;
}

bool ispossible(int i, int j, int n, int m){
    if(i>=0 and i<n and j>=0 and j<m)return true;
    return false;
}

int getAns(vector<vector<int>> &grid){
    priority_queue<pipii, vector<pipii>, greater<pipii>> min_heap;

    int n=grid.size(), m=grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // int term=1000;

    min_heap.push({0,{0,0}});
    visited[0][0]=1;
    while(!min_heap.empty()){
        pipii temp = min_heap.top();
        min_heap.pop();

        long long curr_dist = temp.first;
        int x = temp.second.first, y=temp.second.second;
        // visited[x][y]=1;

        // cout<<"x= "<<x<<" y= "<<y<<" curr_dist= "<<curr_dist<<" : : : ";

        if(x==n-1 and y==m-1)return curr_dist;

        for(int k=0;k<4;k++){
            int next_x = x+dx[k], next_y = y+dy[k];

            if(ispossible(next_x, next_y, n, m) and !visited[next_x][next_y]){
                if(curr_dist + 1 >= grid[next_x][next_y]){
                	// cout<<curr_dist+1<<" , "<<next_x << ", "<<next_y<<endl;
                    min_heap.push({curr_dist+1, {next_x, next_y}});
                }else{
                    int next_dist = fn(curr_dist, grid[next_x][next_y]);
                	// cout<<next_dist<<" , "<<next_x << ", "<<next_y<<endl;
                    min_heap.push({next_dist, {next_x, next_y}});
                }
                visited[next_x][next_y]=1;
            }

        }

        // if(term==0)return -1;
        // term--;
    }
    return -1;
}

int minimumTime(vector<vector<int>>& grid) {
    if(grid[0][0]!=0 or (grid[0][0]==0 and (grid[0][1]>1 and grid[1][0]>1)))
    	return -1;

    return getAns(grid);
}


void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}


	cout<<minimumTime(grid)<<endl;


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