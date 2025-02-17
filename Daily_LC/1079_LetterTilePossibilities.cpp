//1079. Letter Tile Possibilities
//Medium
//Topics
//Companies
//Hint
//You have n  tiles, where each tile has one letter tiles[i] printed on it.
//
//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
//
// 
//
//Example 1:
//
//Input: tiles = "AAB"
//Output: 8
//Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
//Example 2:
//
//Input: tiles = "AAABBC"
//Output: 188
//Example 3:
//
//Input: tiles = "V"
//Output: 1
// 
//
//Constraints:
//
//1 <= tiles.length <= 7
//tiles consists of uppercase English letters.
//

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

void getAns(unordered_map<char,int> &mp, int &ans, string curr,int n){
    ans++;
    for(auto &it: mp){
        if(it.second > 0){
            it.second--;
            getAns(mp, ans, curr+it.first,n);
            it.second++;
        }
    }

}

int fn(string str){
    int n=str.length();

    unordered_map<char,int> mp;
    for(auto it: str)mp[it]++;

    int ans=0;
    getAns(mp,ans,"",n);
    return ans-1;
}


void solve(){
   //your code
   string str;cin>>str;
   cout<<fn(str)<<endl;
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


