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

int getAns(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    //base case: 
    if(i>=j)return 0;
    
    if(dp[i][j] != -1)return dp[i][j];

    ///recursive case: 
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int currAns = arr[i-1]*arr[k]*arr[j];
        
        int temp = getAns(arr, i, k, dp) + getAns(arr, k+1, j, dp) + currAns;
        
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;    
}

void printdp(vector<vector<int>> &dp){
    for(auto it: dp){
        for(auto ele: it)cout<<ele<<" ";
        cout<<endl;
    }
}

int getAnsTab(vector<int> &arr){
    
    int n=arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j== (i+1)){
                dp[i][j] = arr[i-1]*arr[i]*arr[j];
            }
        }
    }

    int x=3;
    while(x<n){
        int i=1,j=x;
        while(i<n and j<n){
            
            int ans=INT_MAX;
            for(int k=i;k<j;k++){
                int currAns=arr[i-1]*arr[k]*arr[j];
                int temp = dp[i][k]+dp[k+1][j]+currAns;
                ans = min(ans, temp);
            }
            dp[i][j]=ans;

            i++;j++;
        }
        x++;
    }
    
    return dp[1][n-1];

}

int matrixMultiplication(vector<int> &arr) {
    // code here
       
//    int n=arr.size();
//    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//    return getAns(arr, 1, n-1, dp);
    return getAnsTab(arr);

}

void solve(){
   //your code
   int n;cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
    
   cout<< matrixMultiplication(arr) << endl;
   
}

int32_t main(){

#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
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

