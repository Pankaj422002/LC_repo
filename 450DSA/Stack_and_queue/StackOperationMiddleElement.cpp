// StackOperationMiddleElement.cpp
#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next, *prev;
	Node(int d){
		this->data=d;
		this->next=NULL;this->prev=NULL;
	}
};

class LinkedList{
	Node* head;
	Node* tail;
	Node* mid;
	int sz;
public: 
	LinkedList(){
		this->head=NULL;
		this->tail=NULL;
		this->mid=NULL;
		this->sz=0;
	}

	void insert(int ele){
		Node *newnode = new Node(ele);

		if(head==NULL){
			head=newnode;
			tail=newnode;
			mid=newnode;
			sz++;
			return;
		}

		tail->next = newnode;
		newnode->prev=tail;
		tail=newnode;
		sz++;

		if(sz%2 == 0)mid=mid->next;

		return;
	}

	int findMiddle(){
		if(sz==0){
			cout<<"no element in stack";
			return -1;
		}
		return mid->data;
	}

	void deleteMiddle(){
		if(sz==0){
			cout<<"no element in stack";
			return;
		}

		if(sz==1){
			head=NULL;
			tail=NULL;

			Node* temp = mid;
			mid=NULL;
			
			sz--;
			delete temp;
			return;
		}

		if(sz==2){
			tail=tail->prev;
			tail->next=NULL;

			Node* temp=mid;
			mid=mid->prev;

			sz--;
			delete temp;
			return;
		}

		Node* prevguy=mid->prev;
		Node* nextguy=mid->next;

		prevguy->next=nextguy;
		nextguy->prev=prevguy;
		
		Node* temp = mid;

		sz--;

		if(sz%2 == 0)mid=mid->next;
		else mid=mid->prev;

		delete temp;
	}

	void pop(){
		if(sz==0)return;
		if(sz==1){
			Node* temp = tail;

			head=NULL;
			tail=NULL;
			mid=NULL;
			sz--;

			delete temp;
			return;
		}
		if(sz==2){
			Node *temp = tail;

			tail=tail->prev;
			mid=head;
			tail->next=NULL;

			delete temp;
			return;
		}

		Node *temp=tail;

		tail=tail->prev;
		tail->next=NULL;

		sz--;
		if(sz%2 != 0)mid=mid->prev;

		delete temp;
		return;
	}

	void print(){
		Node *temp=head;
		while(temp){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif

	LinkedList ll;

	ll.insert(4);
	ll.insert(14);
	ll.insert(41);
	ll.insert(44);
	ll.print();

	cout<< ll.findMiddle() << endl;
	ll.deleteMiddle();
	ll.print();
	cout<< ll.findMiddle() << endl;
	ll.pop();
	ll.print();
	cout<< ll.findMiddle() << endl;

	return 0;
}