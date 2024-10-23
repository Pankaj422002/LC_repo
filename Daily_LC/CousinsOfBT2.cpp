// CousinsOfBT2.cpp
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
	TreeNode *left, *right;
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

	void insert(vector<int> &arr, int n){

		queue<TreeNode*> q;
		root = new TreeNode(arr[0]);
		int k=1;
		q.push(root);

		while(!q.empty()){
			int sz=q.size();
			for(int i=0;i<sz;i++){
				TreeNode *temp = q.front();q.pop();
				
				if(k<n and arr[k]!=-1){
					temp->left = new TreeNode(arr[k]);
					q.push(temp->left);
				}
				k++;
				if(k<n and arr[k]!=-1){
					temp->right = new TreeNode(arr[k]);
					q.push(temp->right);
				}
				k++;

			}
		}

	}

	void printBT(){

		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int n=q.size();
			for(int i=0;i<n;i++){
				TreeNode* temp = q.front();q.pop();
				cout<<temp->val<<" ";
				if(temp->left)q.push(temp->left);
				if(temp->right)q.push(temp->right);
			}
			cout<<endl;
		}

	}


    void FindParent(TreeNode *root, vector<int> &parent, unordered_map<int,int> &mp){

        parent.push_back(-1);
        mp[-1]=root->val;
        int p=0;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();q.pop();
                if(temp->left){
                    q.push(temp->left);
                    parent.push_back(p);
                    mp[p]+=(temp->left->val);
                }
                if(temp->right){
                    q.push(temp->right);
                    parent.push_back(p);
                    mp[p]+=(temp->right->val);
                }
                p++;
            }
        }

    }

    // TreeNode* replaceValueInTree() {
    void replaceValueInTree(){

        vector<int> parent;
        unordered_map<int,int> mp;
        FindParent(root,parent,mp);

        queue<TreeNode*> q;
        q.push(root);
        int curr_total=root->val, k=0;
        while(!q.empty()){
            int n=q.size(), next_total=0;
            for(int i=0;i<n;i++){
                TreeNode *curr = q.front();q.pop();
                
                curr->val = curr_total - mp[parent[k++]];

                if(curr->left){
                    q.push(curr->left);
                    next_total+=(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    next_total+=(curr->right->val);
                }
            }
            curr_total=next_total;
        }

        // return root;
    }



};

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    BinaryTree BT;
	BT.insert(arr, n);
	cout<<"BEFORE : "<<endl; 
	BT.printBT();


	BT.replaceValueInTree();

	cout<<"AFTER : "<< endl;
	BT.printBT();

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