// SegmentedSieve.cpp
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

vector<int> GeneratePrimeSieve(){
	vector<int> ans;


	vector<int> prime(100001, 1);
	prime[0]=prime[1]=0;
	for(int i=2;i<100001;i++){
		if(prime[i]){
			ans.push_back(i);
			for(int j=i*i;j<100001;j+=i){
				prime[j]=0;
			}		
		}
	}


	return ans;
}

void solve(){
	vector<int> prime = GeneratePrimeSieve();

	int q;cin>>q;
	while(q--){
		int m,n;cin>>m>>n;
		vector<int> Segment(n-m+1, 1);

		for(int i=0;i<prime.size();i++){
			int p=prime[i];

			if(p*p > n)break;

			int start = (m/p)*p;

			//overlapping case: 
			if(p>=m and p<=n)
				start=p*2;

			for(int j=start;j<=n;j+=p){
				if(j<m)continue;
				Segment[j-m]=0;
			}
		}

		//calculate the answer: 
		for(int i=m;i<=n;i++){
			if(Segment[i-m] and i!=1)cout<<i<<endl;
		}
		cout<<endl;
	}

}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif


	int t=1;
	while(t--)solve();

	return 0;
}