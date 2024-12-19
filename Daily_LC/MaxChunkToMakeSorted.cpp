class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),i=0,maxi=arr[0],ans=0;
        while(i<n){
            maxi=max(maxi, arr[i]);
            if(maxi==i)ans++;
            i++;
        }
        return ans;
    }
};
