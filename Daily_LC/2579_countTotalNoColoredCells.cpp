// 2579_countTotalNoColoredCells.cpp
class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1,i=0;
        while(n--){ans+=(4*i);i++;}
        return ans;
    }
};