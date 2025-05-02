// ImplementationOfQueue.cpp
#include<bits/stdc++.h>

using namespace std;

class myQueue{
	vector<int> arr;
	int f,r,msz,csz;
public:
	myQueue(int sz=10){
		arr.resize(sz,0);
		f=0,r=0,msz=sz,csz=0;
	}

	bool isempty(){
		return csz==0?true:false;
	}

	bool isfull(){
		return msz==csz?true:false;
	}

	void push(int ele){
		if(isfull()){
			cout<<"queue is full"<<endl;
			return;
		}

		arr[r]=ele;
		r=(r+1)%msz;
		csz++;
	}

	void pop(){
		if(isempty()){
			cout<<"queue is empty"<<endl;
			return;
		}
		f=(f+1)%msz;
		csz--;
		return;
	}

	int front(){
		if(isempty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		return arr[f];
	}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif

	myQueue q;
	q.push(2);
	q.push(21);
	q.push(12);
	q.push(22);
	q.push(23);

	while(!q.isempty()){
		cout<<q.front()<<" ";
		q.pop(); 
	}

	return 0;
}