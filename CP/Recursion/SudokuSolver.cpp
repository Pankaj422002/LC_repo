// SudokuSolver.cpp
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

void PrintGrid(vector<vector<int>> &grid){
	for(auto it: grid){
		for(auto ele: it)cout<<ele<<" ";
		cout<<endl;
	}
}


bool ispossible(vector<vector<int>> &grid, int i, int j, int no){	
	for(int k=0;k<9;k++)if(grid[i][k]==no)return false;
	for(int k=0;k<9;k++)if(grid[k][j]==no)return false;

	int rooti, rootj;
	if(i>=0 and i<3)rooti=0;
	else if(i>=3 and i<6)rooti=3;
	else if(i>=6 and i<9)rooti=6;

    if(j>=0 and j<3)rootj=0;
    else if(j>=3 and j<6)rootj=3;
    else if(j>=6 and j<9)rootj=6;

	for(int p=rooti;p<rooti+3;p++){
		for(int q=rootj;q<rootj+3;q++){
			if(grid[p][q]==no)return false;
		}
	}

	return true;
}

bool getAns(vector<vector<int>> &grid, int i, int j){
	//base case: 
	if(i==grid.size())return true;

	if(grid[i][j]!=0){
		return getAns(grid, ((j==8)?i+1:i),((j==8)?0:j+1));
	}

	//recursive case: 
	for(int k=1;k<=9;k++){
		if(ispossible(grid, i, j, k)){

			grid[i][j]=k;

			bool ans = getAns(grid, ((j==8)?i+1:i), ((j==8)?0:j+1));
			if(ans)return ans;

			grid[i][j]=0;
		}
	}

	return false;

} 

void SudokuSolver(vector<vector<int>> &grid){
	getAns(grid, 0,0);
	PrintGrid(grid);
}

void solve(){
	vector<vector<int>> grid(9, vector<int> (9));

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>grid[i][j];

	SudokuSolver(grid);

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