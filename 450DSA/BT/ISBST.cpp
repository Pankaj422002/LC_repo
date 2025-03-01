// ISBST.cpp
#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
	int data;
	Node* left, *right;
	Node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

class BinaryTree{
	Node* root;
public: 
	BinaryTree(){
		root=NULL;
	}

	Node* createPreOrder(vector<int> &arr, int &i){
		if(arr[i]==-1)return NULL;

		Node* temp = new Node(arr[i]);

		i++;
		temp->left = createPreOrder(arr,i);
		i++;
		temp->right = createPreOrder(arr,i);

		return temp;
	}

	void CreateBT(vector<int> &arr){
		int i=0;
		this->root = createPreOrder(arr,i);
	}

	class info{
	public:
		bool isbst;
		int mini,maxi;
		info(){
			this->isbst=true;
			this->mini=INT_MAX;
			this->maxi=INT_MIN;
		}
	};

	info isBST(Node* root){
		info obj;
		if(root==NULL){
			return obj;
		}

		info L = isBST(root->left);
		info R = isBST(root->right);

		if(L.isbst and R.isbst and root->data>=L.maxi and root->data < R.mini){
			obj.isbst=true;
		}else{
			obj.isbst=false;
		}

		obj.mini = min(root->data, L.mini);
		obj.maxi = max(root->data, R.maxi);
		return obj;
	}

	bool isBST(){
		return isBST(root).isbst;
	}

	void printpreorder(Node* root){
		stack<Node*> s;
		s.push(root);
		while(!s.empty()){
			Node* temp = s.top();s.pop();
			cout<<temp->data<<" ";

			if(temp->right)s.push(temp->right);
			if(temp->left)s.push(temp->left);
		}
	}

	void printpreorder(){
		printpreorder(root);
	}

};

int main(){

	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);

	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	BinaryTree BT;
	BT.CreateBT(arr);
	BT.printpreorder();
	cout<<BT.isBST()<<endl;

	return 0;
}