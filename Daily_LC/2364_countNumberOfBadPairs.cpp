// 2364_countNumberOfBadPairs.cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            
            int check = nums[i]-i;

            if(mp.find(check)!=mp.end())ans+=(i-mp[check]);
            else ans+=(i);

            mp[nums[i]-i]++;

        }
        return ans;
    }
};