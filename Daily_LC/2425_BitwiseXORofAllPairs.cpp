// 2425_BitwiseXORofAllPairs.cpp
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(),a1=0,a2=0,a3=0;
        for(auto it:nums1)a1 ^= it;
        for(auto it:nums2)a2 ^= it;
        a3=a1^a2;

        if(n1%2 == 0 and n2%2 == 0)return 0;
        if(n1%2 !=0 and n2%2 == 0)return a2;
        if(n1%2 == 0 and n2%2 != 0)return a1;

        return a3;
    }
};