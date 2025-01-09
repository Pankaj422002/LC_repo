// 2185_CountWordWithGivenPrefix.cpp
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

class Node{
public: 
	char ch;
	bool isterminal;
	int freq;
	vector<Node*> childrens;
	Node(char ch){
		this->ch = ch;
		this->isterminal=false;
		this->freq=0;
		for(int i=0;i<26;i++)childrens.push_back(NULL);
	}
};

class Trie{
	Node* root;
public: 
	Trie(){
		root = new Node('\0');
	}
	void insert(string str){
		Node *temp = root;
		for(int i=0;i<str.length();i++){
			char ch = str[i];
			if(temp->childrens[ch-'a']!=NULL){
				temp=temp->childrens[ch-'a'];
			}else{
				temp->childrens[ch-'a'] = new Node(ch);
				temp=temp->childrens[ch-'a'];
			}
			temp->freq+=1;
		}
		temp->isterminal=true;
	}
	int countPref(string pre){
		Node* temp=root;
		for(int i=0;i<pre.length();i++){
			char ch = pre[i];
			if(temp->childrens[ch-'a']!=0){
				temp=temp->childrens[ch-'a'];
			}else{
				return 0;
			}
		}
		return temp->freq;
	}
};

int prefixCount(vector<string>& words, string pref) {
    Trie T;
    for(auto it: words)T.insert(it);
    return T.countPref(pref);
}


void solve(){

	int n;cin>>n;
	vector<string> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	string pref;cin>>pref;
	cout<<prefixCount(arr,pref)<<endl;

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