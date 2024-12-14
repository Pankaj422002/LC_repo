// CountString.cpp
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

int sz=2;
struct Mat{
	vector<vector<int>> mat;
	
	Mat(){
		for(int i=0;i<sz;i++){
			vector<int> temp(sz, 0);
			mat.pb(temp);
		}
	}

	void Identity(){
		for(int i=0;i<sz;i++)
			mat[i][i]=1;
	}

	Mat operator*(Mat T){
		Mat res;
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){

				for(int k=0;k<sz;k++){
					res.mat[i][j] += mat[i][k]*T.mat[k][j];
				}

			}
		}
		return res;
	}

};

int CountString_matExpo(int n){

	int b=n-1;
	Mat res, T;
	res.Identity();

	T.mat[0][0]=T.mat[0][1]=T.mat[1][0]=1;
	T.mat[1][1]=0;

	while(b){
		if(b&1)res=res*T;
		T=T*T;
		b>>=1;
	}

	return res.mat[0][0]*2;

}

int countstring(int n){
	if(n==0)return 0;
	if(n==1)return 2;

	return countstring(n-1)+countstring(n-2);

}

void solve(){
	int n;cin>>n;

	// cout<<countstring(n)<<endl;
	cout<<CountString_matExpo(n)<<endl;

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