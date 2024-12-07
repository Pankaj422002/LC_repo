// Nqueen.cpp
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

bool ispossible(int i, int j, int n, vector<string> &mat){
	for(int k=0;k<n;k++)if(mat[i][k]=='Q')return false;
	for(int k=0;k<n;k++)if(mat[k][j]=='Q')return false;
	int mini=min(i,j);
		
	int s_i=i-mini, s_j=j-mini;
	while(s_i<n and s_j<n){
		if(mat[s_i][s_j]=='Q')return false;
		s_i++;s_j++;
	}

	s_i=i-mini,s_j=j+mini;
	while(s_j>=0 and s_i<n){
		if(mat[s_i][s_j]=='Q')return false;
		s_i++;s_j--;
	}
	return true;
}

void getResult(int n, int j, vector<string> output, vector<vector<string>> &ans){
	//base case: 
	if(j==n){
		ans.pb(output);
		// print(output);
		return;
	}

	//recursive case: 
	for(int i=0;i<n;i++){
		if(ispossible(i,j,n,output)){
			output[i][j]='Q';
			getResult(n, j+1, output, ans);
			output[i][j]='.';
		}
	}

}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> output;

    for(int i=0;i<n;i++){
    	string temp="";
    	for(int j=0;j<n;j++)
    		temp+='.';
    	output.pb(temp);
    }
    getResult(n, 0, output, ans);

    return ans;
}


void solve(){
	int n;cin>>n;
	vector<vector<string>> ans = solveNQueens(n);
	for(auto it: ans){
		print(it);
	}
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