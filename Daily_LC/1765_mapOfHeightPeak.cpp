// 1765_mapOfHeightPeak.cpp
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

void printMAT(vector<vector<int>> &arr){
	for(auto it: arr){
		for(auto ele: it)cout<<ele<<" ";
		cout<<endl;
	}
}

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool ispossible(int i, int j, int n, int m){
	if(i>=0 and i<n and j>=0 and j<m)return true;
	return false;
}
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
	int n=isWater.size(), m=isWater[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));

	queue<pii> q;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(isWater[i][j]){
    			q.push({i,j});
    			ans[i][j]=0;
    		}
	    }
    }

    while(!q.empty()){
    	pii temp = q.front();q.pop();
    	int i=temp.F,j=temp.S;
    	for(int k=0;k<4;k++){
    		int x=i+dx[k], y=j+dy[k];
    		if(ispossible(x, y, n, m) and ans[x][y]==-1){
    			ans[x][y]=ans[i][j]+1;
    			q.push({x,y});
    		}
    	}
    }
    return ans;
}


void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	vector<vector<int>> ans = highestPeak(arr);
	printMAT(ans);

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