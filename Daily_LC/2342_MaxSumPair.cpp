class Solution {
public:
    int digitSum(int no){
        int ans=0;
        while(no){
            ans+=(no%10);
            no=no/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> mp;
        for(auto it: nums)mp[digitSum(it)].push_back(it);

        int ans=-1;
        for(auto it: mp){
            if(it.second.size()>1)
                ans = max(ans, it.second[it.second.size()-2]+it.second[it.second.size()-1]);
        }
        return ans;
    }
};
