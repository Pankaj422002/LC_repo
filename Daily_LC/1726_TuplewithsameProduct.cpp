// 1726_TuplewithsameProduct.cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int a=0;a<n;a++){
            for(int b=n-1;b>a;b--){
                
                set<int> s;
                int curr_prod=nums[a]*nums[b];
                for(int c=a+1;c<b;c++){
                    if(curr_prod%nums[c] == 0){

                        int d_val = curr_prod/nums[c];
                        if(s.find(d_val)!=s.end()){
                            ans += 8;
                        }
                        s.insert(nums[c]);

                    }
                }

            }
        }
        return ans;
    }
};