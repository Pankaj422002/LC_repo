class Solution {
public:
    #define pii pair<int,int>
    #define pb  push_back
    #define F   first
    #define S   second
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<pii> arr;
        for(int i=0;i<n;i++)arr.pb({nums[i],i});
        sort(arr.begin(),arr.end());

        int l=0,r=0;
        while(r<n){
            
            while(r+1<n and abs(arr[r+1].F - arr[r].F)<=limit){
                r++;
            }
            r++;
            vector<int> temp;
            for(int i=l;i<r;i++)temp.pb(arr[i].S);

            sort(temp.begin(),temp.end());
            for(int i=l,k=0;i<r;i++)nums[temp[k++]]=arr[i].F;
            l=r;
        }
        return nums;
    }
};