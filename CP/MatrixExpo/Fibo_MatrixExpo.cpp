// Fibo_MatrixExpo.cpp
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
#define mpi 			map<pii, int>
#define spi 			set<pii>
#define endl 			"\n"
#define sz(x) 			((int) x.size())
#define all(p) 			p.begin(), p.end()
#define double 			long double
#define que_max 		priority_queue<int>
#define que_min			priority_queue<int, vi, greater<int>>
#define bug(...) 		__f (#__VA_ARGS__, __VA_ARGS__)
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

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names+1, ',');
	cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}

const int N = 200005;

const int sz=2;
struct Mat
{
	int m[sz][sz];
	Mat(){
		memset(m, 0, sizeof(m));
	}

	void Identity(){
		for(int i=0;i<sz;i++)
			m[i][i]=1;
	}

	Mat operator*(Mat a){
		Mat res;

		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				for(int k=0;k<sz;k++){
					res.m[i][j] += (m[i][k]*a.m[k][j]);
				}
			}
		}

		return res;
	}

};

int Fibo(int n){

	if(n<=2)return n;

	Mat T;
	T.m[0][0]=T.m[0][1]=T.m[1][0]=1;

	n=n-2;

	Mat res;res.Identity();

	while(n){
		if(n&1)res=res*T;
		T=T*T;
		n>>=1;
	}

	return res.m[0][0]+res.m[0][1]; 
}

void solve(){
	int n;cin>>n;
	cout<<Fibo(n)<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif

	clock_t z = clock();

	int t=1;
	cin>>t;
	while(t--)solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}