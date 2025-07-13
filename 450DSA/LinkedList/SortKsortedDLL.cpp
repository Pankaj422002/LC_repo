// SortKsortedDLL.cpp
#include<bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node *next, *prev;
public: 
	Node(int d){
		this->data=d;
		this->next=NULL;
		this->perv=NULL;
	}
};

class LinkedList{
	Node *head, *tail;
public: 
	LinkedList(){
		this->head=NULL;
		this->tail=NULL;
	}

	void insertInLL(int ele){
		Node* newnode = new Node(ele);
		if(head==NULL){
			head=newnode;
			tail=newnode;
			return;
		}

		tail->next = newnode;
		newnode->prev=tail;

		tail=tail->next;
	}

	void print(){
		Node* temp=head;
		while(temp){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}

	class mycompare{
	public:
		bool operator()(Node* a, Node* b){
			return a->data < b->data;
		}
	};

	Node* sort(int k){

		priority_queue<Node*,vector<Node*>,mycompare> min_heap;
		k++;
		while(k-- and head){
			min_heap.push(head->data);
			head=head->next;
		}

		Node *ans_head=NULL, *ans_tail=NULL;
		while(!min_heap.empty()){
			Node* temp = min_heap.top();min_heap.pop();

			if(ans_head==NULL){
				ans_head=temp;
				ans_tail=temp;
			}else{
				ans_tail->next=temp;
				ans_tail=temp;
			}

			if(head){
				min_heap.push(head);
				head=head->next;
			}

		}
		return ans_head;
	}

};

int main(){

	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);

	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	LinkedList ll;
	for(auto it: arr)ll.insertInLL(it);

	int k;cin>>k;
	Node* head = ll.sort(k);

	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;

	return 0;
}