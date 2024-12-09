// specialArray2.cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;

        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n-1;i++){
            if((nums[i]&1) == (nums[i+1]&1))arr.push_back(i);
        }

        for(auto it: queries){
            int x=it[0], y=it[1];

            bool flag=true;
            if(x!=y){
                int s=0,e=arr.size()-1;
                while(s<=e){
                    int m=(s+e)/2;
                    if(arr[m]>=x and arr[m]<y){
                        flag=false;break;
                    }else if(arr[m]<x){
                        s=m+1;
                    }else{
                        e=m-1;
                    }
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};