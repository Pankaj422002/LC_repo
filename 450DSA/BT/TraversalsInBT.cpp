#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node(int val){
		this->data=val;
		this->left=NULL;
		this->right=NULL;
	}
};

class BinaryTree{
	Node *root;
public:
	BinaryTree(){
		root=NULL;
	}

	void POSTORDER(Node* root){
		if(root==NULL)return;
		POSTORDER(root->left);
		POSTORDER(root->right);
		cout<<root->data<<" ";
	}

	void postorder(){
		cout<<"postorder : ";
		POSTORDER(root);
		cout<<endl;
	}

	void postorder_using_stack(Node* root){
		stack<Node*> s1;
		vector<int> res;

		s1.push(root);
		while(!s1.empty()){
			Node* temp = s1.top();s1.pop();
			res.push_back(temp->data);
			if(temp->left)s1.push(temp->left);
			if(temp->right)s1.push(temp->right);
		}
		reverse(res.begin(),res.end());
		for(auto it: res)cout<<it<<" ";
	}

	void postorder_using_stack(){
		cout<<"postorder_using_stack: ";
		postorder_using_stack(root);
		cout<<endl;
	}

	void PREORDER(Node* root){
		if(root==NULL)return;
		cout<<root->data<<" ";
		PREORDER(root->left);
		PREORDER(root->right);
	}

	void preorder(){
		cout<<"preorder : ";
		PREORDER(root);
		cout<<endl;
	}

	void preorder_using_stack(Node* root){
		stack<Node*> s;
		s.push(root);

		while(!s.empty()){
			Node* temp = s.top();s.pop();
			cout<<temp->data<<" ";
			if(temp->right)s.push(temp->right);
			if(temp->left)s.push(temp->left);
		}

	}

	void preorder_using_stack(){
		cout<<"preorder_using_stack: ";
		preorder_using_stack(root);
		cout<<endl;
	}

	void INORDER(Node* root){
		if(root==NULL)return;
		INORDER(root->left);
		cout<<root->data<<" ";
		INORDER(root->right);
	}
	
	void inorder(){
		cout<<"inorder : ";
		INORDER(root);
		cout<<endl;
	}
    
    void inorder_using_stack(Node* root){
    	stack<Node*> s;
    	Node* curr=root;

    	while(!s.empty() || curr!=NULL){
    		while(curr){
    			s.push(curr);
    			curr=curr->left;
    		}

    		Node* temp = s.top();s.pop();
    		cout<<temp->data<<" ";
    		curr=temp->right;
    	}

    }

	void inorder_using_stack(){
		cout<<"inorder_using_stack: ";
		inorder_using_stack(root);
		cout<<endl;
	}

    Node* createPreorder(vector<int> &arr, int &i){
    	if(arr[i] == -1)return NULL;

    	Node* temp = NULL;
		temp = new Node(arr[i]);

		i++;
		temp->left = createPreorder(arr,i);
		
		i++;
		temp->right = createPreorder(arr,i);

    }

    void Create(vector<int> &arr){
    	int i=0;
    	root = createPreorder(arr,i);
    }

    void printLevelOrder(){
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    		int n=q.size();
    		for(int i=0;i<n;i++){
    			Node* temp = q.front();q.pop();
    			cout<<temp->data<<" ";
    			if(temp->left)q.push(temp->left);
    			if(temp->right)q.push(temp->right);
    		}
    		cout<<endl;
    	}
    }
};

int main(){

	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);

	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	BinaryTree BT;
	BT.Create(arr);
	BT.printLevelOrder();
	BT.preorder();
	BT.preorder_using_stack();
	BT.postorder();
	BT.postorder_using_stack();
	BT.inorder();
	BT.inorder_using_stack();

	return 0;
}