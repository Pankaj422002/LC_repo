// ShortestSubarrayORAtleastK.cpp
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

void addTOBV(int x , vector<int> &BV){
    int i=0;
    while(x){
        if(x&1)BV[i]++;
        x>>=1;
        i++;
    }
}

int BVtoNo(vector<int> &BV){
    int ans=0;
    for(int i=0;i<32;i++){
        if(BV[i]) ans += (1<<i);
    }
    return ans;
}

void RemoveI_BV(vector<int> &BV, int x){
    int i=0;
    while(x){
        if(x&1)BV[i]--;
        x>>=1;
        i++;
    }
}

int minimumSubarrayLength(vector<int>& nums, int k) {
    vector<int> BV(32, 0);
    int i=0,j=0,ans=INT_MAX,n=nums.size();
    while(j<n){
        //calculation: 
        int curr = nums[j];
        addTOBV(curr, BV);
        int no = BVtoNo(BV);
        
        if(no<k)j++;
        else{
            while(BVtoNo(BV)>=k and i<=j){
                ans = min(ans, j-i+1);
                RemoveI_BV(BV, nums[i]);
                i++;
            }
            j++;
        }
    }
    return ans==INT_MAX?-1:ans;
}

void solve(){
	int n,k;cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<< minimumSubarrayLength(arr, k) <<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	clock_t z = clock();

	int t=1;
	cin>>t;
	while(t--)solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}