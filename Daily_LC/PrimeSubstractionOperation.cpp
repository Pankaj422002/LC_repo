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

bool primeSubOperation(vector<int>& nums) {
    vector<int> PS(1001, 0);
    for(int i=3;i<1001;i+=2)PS[i]=1;
    PS[2]=1;
    for(int i=3;i<1001;i++){
        if(PS[i]){
            for(int j=i*i;j<1001;j+=i)PS[j]=0;
        }
    }

    int n=nums.size();
    int i=n-1;
    while(i>0){
        //check nums[i-1] with nums[i]:
        if(nums[i-1]<nums[i])i--;
        else {
            //now fill the value of nums[i-1]:
            int j=nums[i-1]-1, temp=nums[i-1];
            while(j>0){
                if(PS[j]){
                    if(temp-j < nums[i])nums[i-1]=temp-j;
                    else break;
                }
                j--;
            }
            if(nums[i-1]>=nums[i])return false;
            i--;
        }
    }

    return true;
}

void solve(){
   //your code
   int n;cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)cin>>arr[i];
   cout << primeSubOperation(arr) << endl;
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

