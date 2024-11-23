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

void fill(vector<vector<int>> &visited, int i, int j, int n, int m){
    if(visited[i][j]==1)return;

    for(int k=j+1;k<n;k++){
        if(visited[i][k]==-1 or visited[i][k]==2)break;
        visited[i][k]=1;
    }

    for(int k=j-1;k>=0;k--){
        if(visited[i][k]==-1 or visited[i][k]==2)break;
        visited[i][k]=1;
    }

    for(int k=i-1;k>=0;k--){
        if(visited[k][j]==-1 or visited[k][j]==2)break;
        visited[k][j]=1;
    }

    for(int k=i+1;k<m;k++){
        if(visited[k][j]==-1 or visited[k][j]==2)break;
        visited[k][j]=1;
    }

}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i=0;i<walls.size();i++){
        int x=walls[i][0], y=walls[i][1];
        visited[x][y]=-1;
    }

    for(auto it: guards)visited[it[0]][it[1]]=2;

    for(auto it: guards){
        int x=it[0], y=it[1];
        fill(visited,x,y,n,m);
    }

    int ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(visited[i][j]==0)ans++;

    return ans;
}

void solve(){
   int m,n;cin>>m>>n;
   int g_sz, w_sz; cin >> g_sz >> w_sz;
   vector<vector<int>> guards;
   vector<vector<int>> walls;
    
   for(int i=0;i<g_sz;i++){
        int x,y;cin>>x>>y;
        vector<int> temp={x,y};
        guards.push_back(temp);
   }
    
   for(int i=0;i<w_sz;i++){
        int x,y;cin>>x>>y;
        vector<int> temp={x,y};
        walls.push_back(temp);
   }

   cout<<countUnguarded(m,n,guards,walls)<<endl;

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

