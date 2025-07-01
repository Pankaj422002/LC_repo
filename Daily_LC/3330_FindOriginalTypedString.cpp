//3330. Find the Original Typed String I
//Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
//
//Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
//
//You are given a string word, which represents the final output displayed on Alice's screen.
//
//Return the total number of possible original strings that Alice might have intended to type.
//
// 
//
//Example 1:
//
//Input: word = "abbcccc"
//
//Output: 5
//
//Explanation:
//
//The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
//
//Example 2:
//
//Input: word = "abcd"
//
//Output: 1
//
//Explanation:
//
//The only possible string is "abcd".
//
//Example 3:
//
//Input: word = "aaaa"
//
//Output: 4
//
// 
//
//Constraints:
//
//1 <= word.length <= 100
//word consists only of lowercase English letters.

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

int possibleStringCount(string word) {
    int n=word.length(),i=0,j=0,ans=0;
    while(i<n){
        while(word[j]==word[i])j++;
        ans+=(j-i-1);
        i=j;
    }
    return ans+1;
}


void solve(){
    string str;cin>>str;
    possibleStringCount(str);
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




