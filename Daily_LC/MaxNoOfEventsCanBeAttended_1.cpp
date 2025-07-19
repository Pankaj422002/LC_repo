// Test.cpp

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.
// Return the maximum number of events you can attend.

 

// Example 1:


// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.




#include<bits/stdc++.h>

using namespace std;

int MaxNoOfEventsCanBeAttended(vector<vector<int>> &events){

	int n=events.size();
	sort(events.begin(),events.end());
	priority_queue<int,vector<int>,greater<int>> min_heap;


	int i=0,currDay=events[0][0],ans=0;
	while(i<n || !min_heap.empty()){

		if(min_heap.empty())currDay=max(currDay,events[i][0]);

		while(i<n and events[i][0] == currDay){
			min_heap.push(events[i][1]);
			i++;
		}

		//remove completed event which can't be attended now : 
		while(!min_heap.empty() and min_heap.top()<currDay)
			min_heap.pop();

		//attend the one event on the current day: 
		if(!min_heap.empty()){
			min_heap.pop();
			ans++;
		}
		currDay++;
	}

	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	vector<vector<int>> arr(n,vector<int>(2));
	for(int i=0;i<n;i++)cin>>arr[i][0]>>arr[i][1];

	cout<<MaxNoOfEventsCanBeAttended(arr)<<endl;

	return 0;
}