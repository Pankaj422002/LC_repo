// Heapsort.cpp
#include<bits/stdc++.h>

using namespace std;

void heapify(vector<int> &arr, int idx, int n){
	int maxi=idx, left_idx=2*idx, right_idx=2*idx+1; 

	if(left_idx<n and arr[left_idx]>=arr[maxi]){
		maxi=left_idx;
	}

	if(right_idx<n and arr[right_idx]>=arr[maxi]){
		maxi=right_idx;
	}

	if(maxi!=idx){
		swap(arr[maxi],arr[idx]);
		heapify(arr,maxi,n);
	}

}

void convertToHeap(vector<int> &arr){

	int n=arr.size();
	for(int i=n/2;i>0;i--)
		heapify(arr,i,n);

}

vector<int> heapsort(vector<int> &nums){
	
	vector<int> arr;
	arr.push_back(-1);
	for(auto it: nums)arr.push_back(it);

	//step: 01: convert the array to heap 
	convertToHeap(arr);

	//step: 02: swap the first element with last element & heapify it: 
	int n=arr.size();
	for(int i=0;i<n-1;i++){
		swap(arr[1], arr[n-i-1]);
		heapify(arr,1,n-i-1);
	}

	return arr;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("../../input.txt","r",stdin);
	freopen("../../output.txt","w",stdout);
#endif
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	vector<int> ans = heapsort(arr);
	for(auto it: ans)cout<<it<<" ";
	cout<<endl;

	return 0;
}