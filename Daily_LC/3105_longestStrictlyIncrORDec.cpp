// 3105_longestStrictlyIncrORDec.cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(j-i+1 == 1)ans=max(ans, j-i+1);
            else {
                if(nums[j]>nums[j-1])ans=max(ans, j-i+1);
                else i=j;
            }
            j++;
        }

        i=0,j=0;
        while(j<n){
            if(j-i+1 == 1)ans=max(ans,j-i+1);
            else{
                if(nums[j]<nums[j-1])ans=max(ans, j-i+1);
                else i=j;
            }
            j++;
        }
        return ans;
    }
};