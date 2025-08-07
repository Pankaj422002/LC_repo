//  3. Longest Substring Without Repeating Characters
//  Given a string s, find the length of the longest substring without duplicate characters.
//  
//   
//  
//  Example 1:
//  
//  Input: s = "abcabcbb"
//  Output: 3
//  Explanation: The answer is "abc", with the length of 3.
//  Example 2:
//  
//  Input: s = "bbbbb"
//  Output: 1
//  Explanation: The answer is "b", with the length of 1.
//  Example 3:
//  
//  Input: s = "pwwkew"
//  Output: 3
//  Explanation: The answer is "wke", with the length of 3.
//  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//   
//  
//  Constraints:
//  
//  0 <= s.length <= 5 * 104
//  s consists of English letters, digits, symbols and spaces.

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

int lengthOfLongestSubstring(string s) {
    int n=s.length();

    int j=0,i=0;
    while(j<n){
        
        mp[s[j]]++;

        while(mp[s[j]] > 1 and i<=j){
            //shrink the window:
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(mp.find(s[i]));
            i++;
        }
        
        ans=max(ans, j-i+1);
        j++;
    }
    return ans;
}

void solve(){
   //your code
   string str;cin>>str;
   cout<<lengthOfLongestSubstring(str);
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





