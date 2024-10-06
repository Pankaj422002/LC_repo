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
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
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

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout<< name << " : " << arg1<<endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names+1, ',');
    cout.write(names, comma - names) << " : "<<arg1<<" | "; __f(comma+1, args...);
}

const int N = 200005;






bool isprefix(string str, string &key){
    int key_len = key.length();
    return (str.substr(0,key_len) == key && str[key_len]==' ');
}
bool issuffix(string str, string &key){
    int key_len = key.length();
    return (str.substr(str.length() - key_len) == key && str[str.length()-key_len - 1] == ' ');
}
bool areSentencesSimilar(string s1, string s2) {
    int s1_len=s1.length(), s2_len=s2.length();
    if(s1_len>s2_len)return areSentencesSimilar(s2,s1);
    if(s1_len == s2_len)return s1==s2;

    if(isprefix(s2,s1) || issuffix(s2,s1))return true;

    int i=0;
    while(i<s1_len){
        while(i<s1_len and s1[i]!=' '){
            i++;
        }
        
        if(i==s1_len)break;

        string left = s1.substr(0,i);
        string right= s1.substr(i+1,s1_len-(i+1));
        if(isprefix(s2,left) and issuffix(s2,right))return true;

        i++;
    }
    return false;
}

void solve(){
    

	string s1, s2;
	cin.get();
	getline(cin,s1);
	getline(cin,s2);

    cout<<areSentencesSimilar(s1,s2)<<endl;

}





int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    clock_t z = clock();

    int t=1;
    cin>>t;
    while(t--)solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}