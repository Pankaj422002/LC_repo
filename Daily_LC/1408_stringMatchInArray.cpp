// 1408_stringMatchInArray.cpp
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

vector<int> LPS(string &str){

	int i=1,len=0,n=str.length();
	vector<int> lps(n,0);

	while(i<n){
		if(str[i]==str[len]){
			len++;
			lps[i]=len;
			i++;
		}else{

			if(len-1 < 0){
				lps[i++]=0;
				len=0;
			}
			else len=lps[len-1];
		}
	}

	return lps;
}

bool issubstring(string &str, string &ptr, int idx, vector<vi> &getLPS){

	if(str.length() < ptr.length())return false;

	vector<int> lps = getLPS[idx]; //idx of ptr

	int i=0,j=0,n=str.length(),m=ptr.length();
	while(i<n and j<m){
		if(str[i]==ptr[j]){
			i++;j++;
		}else{

			if(j-1 < 0){
				j=0;
				i++;
			}
			else j=lps[j-1];

		}
	}

	if(j==m)return true;

	return false;

}

vector<string> stringMatching(vector<string>& words) {

    vector<string> ans;

    vector<vector<int>> mat;
    for(auto it :words){
    	mat.push_back(LPS(it));
    }

    for(int i=0;i<words.size();i++){
    	string ptr=words[i];
    	for(int j=0;j<words.size();j++){
    		string str = words[j];
    		if(i!=j and issubstring(str, ptr, i, mat)){
    			ans.push_back(ptr);
    			break;
    		}
    	}
    }

    return ans;

}

void solve(){
	int n;cin>>n;

    vector<string> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    print(stringMatching(arr));

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