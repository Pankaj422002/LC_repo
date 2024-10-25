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

class Node{
public:
   string data;
   unordered_map<string, Node*> childrens;
   bool isterminal;
   Node(string ch ){
       this->data = ch;
       this->isterminal=false;
   }
};

class Trie{
    Node* root;
    public: 
    Trie(){
        root = new Node("");
    }
    void insert(string str){
        Node *curr=root;
        int i=1;
        while(i<str.length()){
            string ch="";
            while(i<str.length() and str[i]!='/')ch+=str[i++];
            
            if(curr->childrens.find(ch)!=curr->childrens.end()){
                curr=curr->childrens[ch];
            }else{
                Node* newnode = new Node(ch);
                curr->childrens[ch]=newnode;
                curr = newnode;
            }
            i++;
        }
        curr->isterminal=true;

    }
    
    void fn(Node* curr, vector<string> &ans, string temp){
        if(curr->isterminal == true){
            ans.push_back(temp.substr(0,temp.length()-1));
            return;
        }
        
        for(auto it: curr->childrens){
            temp+=it.first;
            temp.push_back('/');
            fn(it.second, ans, temp);
            temp.pop_back();
            temp=temp.substr(0,temp.length()-it.first.length());
        }
        
    }

    vector<string> getAns(){
        vector<string> ans;
        fn(root, ans, "/");
        return ans;
    }
    
};

vector<string> removeSubfolders(vector<string>& folder) {

   Trie T;
   for(auto it: folder){
       T.insert(it);
   }
   return T.getAns();
}    

void solve(){
   //your code
   int n;cin>>n;
   vector<string> arr(n);
   for(int i=0;i<n;i++)
       cin>>arr[i];

   print(removeSubfolders(arr));
    
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

