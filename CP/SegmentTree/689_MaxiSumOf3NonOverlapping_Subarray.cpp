// MaxiSumOf3NonOverlapping_Subarray.cpp
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

// void dfs(vector<int> &arr, int i, int k, vector<int> temp, vector<int> &ans){
// 	if(temp.size() == 3){
// 		int maxi=0,curr=0;
// 		for(auto it: ans)maxi+=arr[it];
// 		for(auto it: temp)curr+=arr[it];

// 		// print(ans);
// 		if(maxi<curr){
// 			ans=temp;
// 		}else if(maxi == curr){
// 			if(temp[0]<ans[0]){
// 				ans=temp;
// 				// bug("hi");
// 			}else if(temp[0] == ans[0]){
// 				if(temp[1]<ans[1]){
// 					ans=temp;
// 				}else if(temp[1] == ans[1]){
// 					if(temp[2]<ans[2]){
// 						ans=temp;
// 					}
// 				}
// 			}
// 		}
// 		// print(ans);
// 		return;
// 	}
// 	if(i>=arr.size())return ;


// 	temp.push_back(i);
// 	dfs(arr, i+k, k, temp, ans);
// 	temp.pop_back();
// 	dfs(arr, i+1, k, temp, ans);

// }

void getAns(vector<int> &arr, vector<int> &ans, int k){
	print(arr);

	int n=arr.size();
	vector<vector<int>> dp(n+1, vector<int>(4, 0));

	for(int i=1;i<=n;i++){
		for(int j=2;j>=0;j--){
			if(j<3){
				dp[i][j] = max(arr[i-1]+ ((i-k>=0) ? dp[i-k][j+1] : 0), 
								dp[i-1][j]);
			}
		}
	}

	int i=n,j=0;
	while(i>0 and j<3){

		int consider = arr[i-1]+ ((i-k>=0) ? dp[i-k][j+1] : 0);
		int notconsider = dp[i-1][j];

		int maxi = max(consider, notconsider);

		if(consider == notconsider){
			i=i-1;
		}else{
			if(maxi == notconsider){
				i=i-1;
			}else{
				ans.push_back(i-1);
				i=i-k;j=j+1;
			}
		}

	}

	reverse(ans.begin(),ans.end());
}

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> ans;

   	vector<int> arr;
   	int i=0,j=0,n=nums.size(),curr_sum=0;
   	while(j<n){

   		curr_sum += nums[j];

   		if(j-i+1 < k)j++;
   		else if(j-i+1 == k){
   			arr.push_back(curr_sum);

   			curr_sum -= nums[i];

   			i++;
   			j++;
   		}

   	}

   	getAns(arr,ans,k);

    return ans; 
}

void solve(){

	int n,k;cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	vector<int> ans = maxSumOfThreeSubarrays(arr, k);
	print(ans);

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