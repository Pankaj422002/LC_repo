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
#define mci				unordered_map<char,int>
#define mpi             map<pii, int>
#define spi             set<pii>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define double          long double
#define que_max         priority_queue<int>
#define que_min         priority_queue<int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
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

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names+1, ',');
    cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}

const int N = 200005;

bool isequal(mci &mp1, mci &mp2){

	for(auto it: mp2){
		if(mp1.find(it.first)==mp1.end())return false;
		else{
			if(mp1[it.first] != it.second)return false;
		}
	}

	return true;

}

bool checkInclusion(string s1, string s2) {
    
    int k=s1.length();
    mci mp1;
    mci mp2;
    for(auto it: s1)mp1[it]++;

    int i=0,j=0,n=s2.length();
	while(j<n){
		mp2[s2[j]]++;
		if(j-i+1<k)j++;
		else if(j-i+1 == k){

			if(isequal(mp1,mp2))return true;
			mp2[s2[i]]--;
			if(mp2[s2[i]] == 0)mp2.erase(mp2.find(s2[i]));

			i++;j++;
		}
	}
	return false;

}


void solve(){
    
    string s1,s2;cin>>s1>>s2;
    cout<<checkInclusion(s1,s2)<<endl;

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    clock_t z = clock();

    int t=1;
    cin>>t;
    while(t--)solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}