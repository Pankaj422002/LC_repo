
//
//Begin with an empty string comp. While word is not empty, use the following operation:
//Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
//Append the length of the prefix followed by c to comp.
//Return the string comp.
//
// 
//
//Example 1:
//
//Input: word = "abcde"
//
//Output: "1a1b1c1d1e"
//
//Explanation:
//
//Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
//
//For each prefix, append "1" followed by the character to comp.
//
//Example 2:
//
//Input: word = "aaaaaaaaaaaaaabb"
//
//Output: "9a5a2b"
//
//Explanation:
//
//Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.
//
//For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
//For prefix "aaaaa", append "5" followed by "a" to comp.
//For prefix "bb", append "2" followed by "b" to comp.
// 
//
//Constraints:
//
//1 <= word.length <= 2 * 105
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

string compressedString(string word){
    string comp="";
    
    int i=0;
    while(i<word.length()){
        int j=i;
        while(j<word.length()-1 and word[j]==word[j+1] and j-i+1<9){
            j++;
        }
        comp += (to_string(j-i+1)+word[j]);
        i=j+1;
    }

    return comp;
}

void solve(){
   //your code
   string str;cin>>str;
   cout<<compressedString(str)<<endl;
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


