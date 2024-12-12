class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int> max_heap;
        for(auto it: gifts)max_heap.push(it);
        while(!max_heap.empty()){
            int x=max_heap.top();max_heap.pop();
            int t=sqrt(x);
            max_heap.push(t);
            k--;
            if(k==0)break;
        }
        while(!max_heap.empty()){
            ans+=max_heap.top();max_heap.pop();
        }
        return ans;
    }
};
