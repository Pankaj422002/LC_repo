// SubstractionOf_TwoLargeNo.cpp
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

string sub(string &a, string &b){
    string ans="";
    
    int i=a.length()-1, j=b.length()-1, carry=0;
    while(i>=0 and j>=0){
        int temp=(a[i]-'0')-(b[j]-'0')-carry;
        if(temp<0){
            temp+=10;
            carry=1;
        }else{
            carry=0;
        }
        ans+=to_string(temp);
        i--;j--;
    }
    
    while(i>=0){
        int temp=(a[i]-'0')-carry;
        if(temp<0){
            temp+=10;
            carry=1;
        }else{
            carry=0;
        }
        ans+=to_string(temp);
        i--;
    }
    //remove the trailing zeros : 
    int k=ans.length()-1;
    while(k>=0){
    	if(ans[k]=='0')
    		k--;
    	else break;
    }

    if(k<0)return "0";

    ans=ans.substr(0,k+1);
    
    reverse(ans.begin(),ans.end());
    return ans;
}

bool isaGrtb(string &a, string &b){
	if(a.length()==b.length()){
        int i=0;
        while(i<a.length()){
            if(a[i]==b[i])
                i++;
            else if(a[i]>b[i])
                return true;
            else 
                return false;
        }
	}
	return a.length()>b.length();
}

string gcd(string a, string b){
    if(a == "0")return b;
    if(b == "0")return a;
    if(a == b)return a;
        
    if(isaGrtb(a,b)){
        // cout<<a<<" "<<b<<endl;
        return gcd(sub(a,b), b);
    }
    else{
        // cout<<a<<" lll "<<b<<endl;
        return gcd(a, sub(b,a));
    }
    
}

int fn(int a, string b){
    string n1=to_string(a);
    string ans = gcd(n1,b);
    
    int res=stoi(ans);
    
    return res;
    
}

void solve(){
	int a;
	string b;
	cin>>a>>b;
	cout<< fn(a,b) <<endl;
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
