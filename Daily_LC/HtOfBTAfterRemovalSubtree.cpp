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
#define umpii            unordered_map<int,int>
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
        TreeNode(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree{
    public: 
        TreeNode* root;
        BinaryTree(){
            this->root = NULL;
        }
        
        TreeNode* insert(vector<int> arr, int n){
            queue<TreeNode*> q;
            int k=0;
            root = new TreeNode(arr[k++]);
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
                int n=q.size();
                for(int i=0;i<n;i++){
                    TreeNode* curr = q.front();q.pop();
                    cout<<curr->val<<" ";
                    if(curr->left)q.push(curr->left);
                    if(curr->right)q.push(curr->right);
                }
                cout<<endl;
            }
        }
         
};

int fillht(TreeNode* root, int level, umpii &val_ht, umpii &val_lvl, unordered_map<int,vector<int>> &lvl_valarr){
    if(root == NULL)return 0;
    
    val_lvl[root->val]=level;
    lvl_valarr[level].push_back(root->val);

    if(root->left == NULL and root->right == NULL)return val_ht[root->val]=0;

    if(root->left!=NULL and root->right==NULL)return val_ht[root->val]=1+fillht(root->left,level+1, val_ht, val_lvl, lvl_valarr);
    if(root->left==NULL and root->right!=NULL)return val_ht[root->val]=1+fillht(root->right,level+1, val_ht, val_lvl, lvl_valarr);

    return val_ht[root->val]=1+ max(fillht(root->left, level+1, val_ht, val_lvl, lvl_valarr), fillht(root->right, level+1, val_ht, val_lvl, lvl_valarr));
}

void getTop2(TreeNode* root, vector<vector<int>> &top2_level, umpii &val_ht){
    queue<TreeNode*> q;
    q.push(root);
    int level=0;

    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr=q.front();q.pop();

            if(top2_level[0][level] <= val_ht[curr->val])top2_level[1][level]=top2_level[0][level];
            else top2_level[1][level]=max(top2_level[1][level], val_ht[curr->val]);


            top2_level[0][level]=max(top2_level[0][level], val_ht[curr->val]);

            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        level++;
    }
}

vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> ans;
    umpii val_ht;
    umpii val_lvl;
    unordered_map<int,vector<int>> lvl_valarr;
    
    vector<vector<int>> top2_level(2,vector<int>(100002, INT_MIN));

    int total_ht = fillht(root,0,val_ht,val_lvl,lvl_valarr);

    getTop2(root, top2_level, val_ht);

    // for(auto it: top2_level){
    //     for(auto ele: it)cout<<ele<<" ";
    //     cout<<endl;
    // }

    for(auto curr: queries){
        int ht=val_lvl[curr]-1;
        int curr_lvl = val_lvl[curr];

        int max1=top2_level[0][curr_lvl];
        int max2=top2_level[1][curr_lvl];
        
        if(val_ht[curr] == max1)ht=max(ht, curr_lvl+max2);
        else ht=max(ht, curr_lvl+max1);

        ans.push_back(ht);
    }
    
    return ans;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    BinaryTree BT;
    TreeNode* root = BT.insert(arr,n);
   // BT.printBT();
    vector<int> queries(m);
    for(int i=0;i<m;i++)cin>>queries[i];


    print(treeQueries(root, queries));
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

