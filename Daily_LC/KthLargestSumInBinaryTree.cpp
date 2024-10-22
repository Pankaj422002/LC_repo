// KthLargestSumInBinaryTree.cpp
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
	public : 
	int val;
	Node* left , *right;
	Node(int d){
		this->val=d;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree{
public:
	Node* root;
	BinaryTree(){
		this->root = NULL;
	}
	void insert(vector<int> &arr, int n){
		root = new Node(arr[0]);

		int k=1;
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			for(int i=0;i<sz;i++){
				Node* curr = q.front();q.pop();
				if(k<n and arr[k]!=-1)curr->left = new Node(arr[k]);
				k++;
				if(k<n and arr[k]!=-1)curr->right = new Node(arr[k]);
				k++;

				if(curr->left)q.push(curr->left);
				if(curr->right)q.push(curr->right);
			}
		}
	}

	void printBT(){
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			int n = q.size();
			for(int i=0;i<n;i++){
				Node* curr = q.front();q.pop();
				cout<<curr->val<<" ";
				if(curr->left)q.push(curr->left);
				if(curr->right)q.push(curr->right);
			}
			cout<<endl;
		}
	}
    int kthLargestLevelSum(int k) {
        que_min min_heap;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int curr=0;
            for(int i=0;i<n;i++){
                Node* temp = q.front();q.pop();
                curr+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            min_heap.push(curr);
            if(min_heap.size()>k)min_heap.pop();
        }

        return min_heap.size()==k?min_heap.top():-1;
    }
};

void solve(){
	BinaryTree BT;

	int n,k;cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	BT.insert(arr, n);
	BT.printBT();
	cout<< "ans = " << BT.kthLargestLevelSum(k)<<endl;

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