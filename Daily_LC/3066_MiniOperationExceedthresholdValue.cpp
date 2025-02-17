//3066. Minimum Operations to Exceed Threshold Value II
//You are given a 0-indexed integer array nums, and an integer k.
//
//In one operation, you will:
//
//Take the two smallest integers x and y in nums.
//Remove x and y from nums.
//Add min(x, y) * 2 + max(x, y) anywhere in the array.
//Note that you can only apply the described operation if nums contains at least two elements.
//
//Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.
//
// 
//
//Example 1:
//
//Input: nums = [2,11,10,1,3], k = 10
//Output: 2
//Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
//In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
//At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
//It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
//Example 2:
//
//Input: nums = [1,1,2,4,9], k = 20
//Output: 4
//Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
//After two operations, nums becomes equal to [7, 4, 9].
//After three operations, nums becomes equal to [15, 9].
//After four operations, nums becomes equal to [33].
//At this stage, all the elements of nums are greater than 20 so we can stop.
//It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.
// 
//
//Constraints:
//
//2 <= nums.length <= 2 * 105
//1 <= nums[i] <= 109
//1 <= k <= 109
//The input is generated such that an answer always exists. That is, there exists some sequence of operations after which all elements of the array are greater than or equal to k.


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

int minOperations(vector<int>& nums, int k) {
   int ptr1=-1, ptr2=-1, n=nums.size();
   for(int i=0;i<n;i++){
       if(ptr1 == -1 and nums[i]<k)ptr1=nums[i];
       else if(ptr2 == -1 and nums[i]<k)ptr2=nums[i];
    
       if(ptr1 != -1 and ptr2 != -1){
           //do the following : 

       }
   }
}

void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    minOperations(arr,k)
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

