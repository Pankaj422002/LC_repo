// 3444_MiniIncOfTargetMultiplesOfArr.cpp
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

    int lcm(int a, int b){
        return (a*b)/__gcd(a,b);
    }

    int LCM(vector<int> &target, int subset){
        int ans=1;
        for (int j = 0; j < target.size(); j++) {
            if (subset & (1 << j)) {
                ans = lcm(ans, target[j]);
            }
        }
        return ans;
    }


int getAns(vector<int> &nums,vector<int> &target, int i, int mask){
    int n=nums.size(),m=target.size();

    if(mask == (1<<m)-1)return 0;
    if(i==n)return INT_MAX;

	//not consider: 
    int op1 = getAns(nums,target,i+1,mask);

    //consider:
    int op2=INT_MAX;
    for(int k=1;k<(1<<m);k++){

    	bool isvalid=true;
    	for(int x=0;x<m;x++){
    		int temp=(1<<x);
    		if((mask&temp)!=0 and (k&temp)!=0){
    			isvalid=false;
    			break;
    		}
    	}

    	if(isvalid){

    		//find the LCM of k : 
    		int lcm = LCM(target, k), curr_ans=0;
    		if(nums[i]%lcm != 0){
    			curr_ans = ((((nums[i]/lcm)*lcm)+lcm) - nums[i]);
    		}
    		int next_ans = getAns(nums,target,i+1,mask|k);
		    op2 = min(op2, (next_ans==INT_MAX ? INT_MAX : curr_ans+next_ans));

    	}

    }

    return min(op1, op2);
}

int minimumIncrements(vector<int>& nums, vector<int>& target) {
	int ans=INT_MAX;
	return getAns(nums,target,0,0);
    // return ans; 

}


void solve(){
	int n,m;cin>>n>>m;
	vector<int> nums(n),target(m);
	for(int i=0;i<n;i++)cin>>nums[i];
	for(int j=0;j<m;j++)cin>>target[j];
	cout<<minimumIncrements(nums,target)<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
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