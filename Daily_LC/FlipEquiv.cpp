// FlipEquiv.cpp
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

class TreeNode{
public: 
	int val;
	TreeNode* left, *right;
	TreeNode(int d){
		this->val=d;
		this->left=NULL;
		this->right=NULL;
	}
};

class BinaryTree{
public: 
	TreeNode* root;
	BinaryTree(){
		this->root=NULL;
	}
	TreeNode* insert(vector<int> &arr, int n){
		int k=0;
		root = new TreeNode(arr[k++]);
		
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			for(int i=0;i<sz;i++){

				TreeNode* curr = q.front();q.pop();

				if(k<n and arr[k]!=-1){
					curr->left = new TreeNode(arr[k]);
					q.push(curr->left);
				}
				k++;
				if(k<n and arr[k]!=-1){
					curr->right = new TreeNode(arr[k]);
					q.push(curr->right);
				}
				k++;

			}
		}
		return root;
	}

	void printBT(){
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			for(int i=0;i<sz;i++){

				TreeNode* curr = q.front();q.pop();
				cout<<curr->val<<" ";
				if(curr->left)q.push(curr->left);
				if(curr->right)q.push(curr->right);
			}
			cout<<endl;
		}
	}


};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if(!root1 and !root2)return true;
    if(!root1 or !root2 or root1->val!=root2->val)return false;

    return ((flipEquiv(root1->left,root2->left) and flipEquiv(root1->right,root2->right)) or
            (flipEquiv(root1->right,root2->left) and flipEquiv(root1->left,root2->right)));

}


void solve(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    vector<int> arr2(m);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    BinaryTree BT1, BT2;
	TreeNode* root1 = BT1.insert(arr,n);
	TreeNode* root2 = BT2.insert(arr2,m);

	// BT1.printBT();
	// BT2.printBT();
	cout<< flipEquiv(root1, root2)<< endl;

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