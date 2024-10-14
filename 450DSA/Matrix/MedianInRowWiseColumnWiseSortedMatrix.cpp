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

int NoOfElementLessthanEqualTo(vector<int> &arr, int key){
	int s=0,e=arr.size()-1,ans=0;
	while(s<=e){
		int m=(s+e)/2;
		if(arr[m] <= key){
			ans=m+1;
			s=m+1;
		}else{
			e=m-1;
		}
	}
	return ans;
}

int LessThanEqualTo(vector<vector<int>> &mat, int key){
	int r=mat.size(), c=mat[0].size(), ans=0;
	for(int i=0;i<r;i++){
		vector<int> temp = mat[i];
		ans+=NoOfElementLessthanEqualTo(temp, key);
	}
	return ans;
}

int median(vector<vector<int>> &matrix, int R, int C){
    // code here 
    int s=1,e=2000,ans=-1,n=R*C;
    while(s<=e){
    	int mid=(s+e)/2;
    	if(LessThanEqualTo(matrix, mid) >= (n/2 + 1)){
    		ans=mid;
    		e=mid-1;
    	}else{
    		s=mid+1;
    	}
    }
    return ans;
}

void solve(){
    int r,c;cin>>r>>c;
    vector<vector<int>> arr(r, vector<int>(c));
    for(int i=0;i<r;i++)
    	for(int j=0;j<c;j++)
    		cin>>arr[i][j];

    cout<<median(arr, r, c)<<endl;

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
