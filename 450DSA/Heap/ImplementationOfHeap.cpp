// ImplementationOfHeap.cpp
#include<bits/stdc++.h>

using namespace std;

class Heap{
	vector<int> arr;
public:
	Heap(){
		arr.push_back(-1);
	}

	void push(int ele){
		arr.push_back(ele);

		int i=arr.size()-1;
		int parent = i/2;
		while(parent>0 and arr[parent]<=arr[i]){
			swap(arr[parent],arr[i]);
			i=parent;
			parent=i/2;
		}
	}

	bool isempty(){
		return arr.size()==1;
	}

	int top(){
		if(isempty()){
			cout<<"heap is empty"<<endl;
			return -1;
		}
		return arr[1];
	}

	void heapify(int idx){
		int left_idx = idx*2;
		int right_idx = idx*2 + 1;

		int n=arr.size(),maxi=idx;
		if(left_idx<n and arr[left_idx]>=arr[maxi]){
			maxi=left_idx;
		}

		if(right_idx<n and arr[right_idx]>=arr[maxi]){
			maxi=right_idx;
		}
		
		if(maxi!=idx){
			swap(arr[idx],arr[maxi]);
			heapify(maxi);
		}

	}

	void pop(){
		if(isempty()){
			cout<<"heap is empty"<<endl;
			return;
		}
		swap(arr[1],arr[arr.size()-1]);
		arr.pop_back();
		heapify(1);
	}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif

	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	Heap max_heap;
	for(auto it: arr)max_heap.push(it);

	cout<<max_heap.top()<<endl;
	max_heap.pop();
	cout<<max_heap.top()<<endl;

	return 0;
}