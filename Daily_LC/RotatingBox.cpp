// RotatingBox.cpp
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

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n=box.size(),m=box[0].size();
    vector<vector<char>> ans(m, vector<char>(n, '.'));

    for(int j=0;j<m;j++){
        for(int i=n-1;i>=0;i--){
            ans[j][n-1-i] = box[i][j];
        }
    }

    for(int j=0;j<n;j++){
        queue<pair<int,int>> q;
        for(int i=m-1;i>=0;i--){
            if(ans[i][j]=='.'){
                q.push({i,j});
            }else if(ans[i][j]=='*'){
                while(!q.empty())q.pop();
            }else if(ans[i][j]=='#'){
                if(!q.empty()){
                    pair<int,int> temp = q.front();
                    ans[temp.first][temp.second]='#';
                    q.pop();
                    ans[i][j]='.';
                    q.push({i,j});
                }
            }
        }
    }

    return ans;
}


void solve(){
	int n,m;cin>>n>>m;
	vector<vector<char>> box(n, vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cin>>box[i][j];
	}

	vector<vector<char>> ans = rotateTheBox(box);
	for(auto it: ans){
		for(auto ele: it)cout<<ele<<" ";
		cout<<endl;
	}

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