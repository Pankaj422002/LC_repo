// ImplementKstacksUsingArr.cpp
#include<bits/stdc++.h>

using namespace std;

class Kstacks{
	vector<int> arr;
	vector<int> topidxofStack;
	vector<int> next;
	int free;
public: 

	Kstacks(int n, int k){
		arr.resize(n,0);
		topidxofStack.resize(k,-1);
		for(int i=0;i<n;i++)next.push_back(i+1);
		next[n]=-1;
		this->free=0;
	}

	void insert(int ele, int stack_i){

		int idx = free;
		arr[idx]=ele;
		
		int temp=topidxofStack[stack_i];

		topidxofStack[stack_i]=idx;


		free=next[idx];
		next[idx]=temp;
	}

	void pop(int stack_i){
		int top_idx = topidxofStack[stack_i];

		if(top_idx == -1)return;

		int temp=next[top_idx];

		next[top_idx]=free;
		free=top_idx;

		topidxofStack[stack_i]=temp;
	}

	void print(int stack_i){
		int temp = topidxofStack[stack_i];
		while(temp!=-1){
			cout<<arr[temp]<<" ";
			temp=next[temp];
		}
		cout<<endl;
	}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif


	Kstacks stk(5,4);
	stk.insert(15, 0);
	stk.print(0);


	stk.insert(25, 1);
	stk.print(1);

	stk.insert(35, 2);
	stk.print(2);

	stk.insert(45, 3);
	stk.print(3);

	stk.insert(55, 0);
	stk.print(0);

	stk.pop(0);
	stk.print(0);

	stk.pop(1);
	stk.print(1);

	stk.insert(55,0);
	stk.print(0);

	stk.pop(3);
	stk.print(3);

	return 0;
}