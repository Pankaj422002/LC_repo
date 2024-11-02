// MaximumScore.cpp
/* JAI SHREE RAM */

#include<bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#define int             long long int
#define F               first
#define S               second
#define pb              push_back
#define si              set<int>
#define vi              vector<int>
#define pii             pair<int,int>
#define vpi             vector<pii>
#define vpp             vector<pair<int,pii>>
#define mii             map<int,int>
#define mpi             map<pii, int>
#define spi             set<pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define double          long double
#define que_max         priority_queue<int>
#define que_min         priority_queue<int, vi, greater<int>>
#ifndef ONLINE_JUDGE
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#endif
#define print(a)        for(auto x: a)cout<<x<<" ";cout<<endl
#define print1(a)       for(auto x: a)cout<<x.F<<" "<<x.S<<endl
#define print2(a,x,y)   for(int i=x;i<y;i++)cout<<a[i]<<" ";cout<<endl

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

const int N = 200005;

bool NeededToFlip(vector<vi> &grid, int j){
	int noofOnes=0, noofZeros=0;
	for(int i=0;i<grid.size();i++){
		if(grid[i][j]==1)noofOnes+=1;
		else noofZeros+=1;
	}
	return noofOnes<noofZeros;
}

int getMaximumScore(vector<vi> &grid){
	int n=grid.size(),m=grid[0].size();
	for(int i=0;i<n;i++){
		if(grid[i][0]==0){
			//filp the bits of the row : 

			for(int j=0;j<m;j++)grid[i][j]=(grid[i][j]==1)?0:1;

		}
	}

	for(int j=0;j<m;j++){
		//should we need to flip it : 
		bool isNeededToFlip = NeededToFlip(grid, j);
		if(isNeededToFlip){
			for(int i=0;i<n;i++)grid[i][j]=(grid[i][j]==1)?0:1;
		}
	}

	int ans=0;
	for(int i=0;i<n;i++){
		int curr=0;
		for(int j=0;j<m;j++)
			curr = curr + (grid[i][j]==1 ? (1<<(m-1-j)) : 0);
		ans+=curr;
	}
	return ans;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vi> grid(n, vector<int>(m));
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin>>grid[i][j];

    cout<<getMaximumScore(grid)<<endl;

}

int32_t main(){

#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    clock_t z = clock();
#endif

    int t=1;
    cin>>t;
    while(t--)solve();

#ifndef ONLINE_JUDGE
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
#endif


    return 0;
}