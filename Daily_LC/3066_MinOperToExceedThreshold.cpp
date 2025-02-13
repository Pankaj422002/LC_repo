// 3066_MinOperToExceedThreshold.cpp
class Solution {
public:
    #define ll  long long int
    int minOperations(vector<int>& nums, int k) {
        int ans=0;

        priority_queue<ll,vector<ll>,greater<ll>> min_heap;
        for(auto it: nums)min_heap.push(it);
        while(min_heap.top()<k){
            ll x=min_heap.top();min_heap.pop();
            ll y=min_heap.top();min_heap.pop();
            ans++;
            ll temp=min(x, y) * 2 + max(x, y);
            min_heap.push(temp);
        }
        return ans;
    }
};