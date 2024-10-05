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
#define my_que_max 		priority_queue<pair<int,pii>>
#define my_que_min 		priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>>


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

vector<int> smallestRange(vector<vector<int>>& nums) {
    
    my_que_min min_heap;
    my_que_max max_heap;
    int n=nums.size();
    for(int i=0;i<n;i++){
    	pair<int,pii> curr=make_pair(nums[i][0], make_pair(i,0));
    	min_heap.push(curr);
    	max_heap.push(curr);
    }

    pair<int,pii> maxi = max_heap.top();
    pair<int,pii> mini = min_heap.top();

    int ans_diff = maxi.first - mini.first;
    vector<int> ans = {mini.first, maxi.first};

    while(!max_heap.empty() and !min_heap.empty()){

    	pair<int,pii> maxi_curr = max_heap.top();
    	pair<int,pii> mini_curr = min_heap.top();

    	int diff = maxi_curr.first - mini_curr.first;
    	if(diff < ans_diff){
    		ans_diff = diff;
    		ans[0]=mini_curr.first;
    		ans[1]=maxi_curr.first;
    	}

    	min_heap.pop();

    	int min_i = mini_curr.second.first;
    	int min_j = mini_curr.second.second;
    	
    	if(min_j+1 >= nums[min_i].size())break;

    	pair<int,pii> temp = make_pair(nums[min_i][min_j+1], make_pair(min_i, min_j+1));
    	min_heap.push(temp);
    	max_heap.push(temp);

    }
    return ans;
}


void solve(){
    
    vector<vector<int>> arr = {{1,2,3},{1,2,3},{1,2,3}};  // {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> ans = smallestRange(arr);
   	print(ans);

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