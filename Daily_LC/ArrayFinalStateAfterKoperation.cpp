class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<int,int>>s;
        for(int i=0;i<nums.size();i++)s.insert({nums[i],i});

        while(k--){
            pair<int,int> temp = *s.begin();
            s.erase(s.begin());
            nums[temp.second]=temp.first*multiplier;
            s.insert({nums[temp.second],temp.second});
        }

        return nums;
    }
};