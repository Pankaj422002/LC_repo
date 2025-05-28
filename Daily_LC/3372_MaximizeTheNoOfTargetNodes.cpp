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

class Solution {
public:

    class Graph{
        vector<vector<int>> adj;
        int n;
        public: 
        Graph(int n){
            for(int i=0;i<n;i++){
                vector<int> temp;
                adj.push_back(temp);
            }
            this->n=n;
        }
        void addEdge(int x, int y){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int BFS(int src, int k){
            vector<bool> visited(n,false);
            queue<int> q;
            q.push(src);
            visited[src]=true;
            
            int ans=0,level=0;
            while(!q.empty()){
                if(level>k)break;
                int sz=q.size();
                for(int i=0;i<sz;i++){
                    int temp =q.front();q.pop();
                    ans++;
                    for(auto nbr: adj[temp]){
                        if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr]=true;
                        }
                    }
                }
                level++;
            }
            return ans;
        }
    };

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size(), m=edges2.size();
        Graph G1(m+1);
        
        for(auto it: edges2){
            G1.addEdge(it[0],it[1]);
        }
        
        int ans1=0; 
        for(int i=0;i<=m;i++){
            ans1=max(ans1, G1.BFS(i,k-1));
        }
        cout<<ans1<<endl;

        Graph G2(n+1);
        for(auto it: edges1)G2.addEdge(it[0],it[1]);

        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            ans.push_back(G2.BFS(i,k)+ans1);
        }
        return ans;
    }
};

void solve(){
   //your code
   vector<vector<int>> edges1, edges2;
   int n,m,k;cin>>n>>m>>k;
   for(int i=0;i<n;i++){
       int x,y;cin>>x>>y;
       edges1.push_back({x,y});
   }

   for(int i=0;i<m;i++){
       int x,y;cin>>x>>y;
       edges2.push_back({x,y});
   }

   Solution sol;
   print(sol.maxTargetNodes(edges1,edges2,k));

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

