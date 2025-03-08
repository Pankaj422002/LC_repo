// 2379_minRecolorgetKconsecutiveBlack.cpp
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b=0,w=0,j=0,n=blocks.size(),i=0,ans=INT_MAX;
        while(j<n){
            (blocks[j]=='B')?(b++):(w++);
            if(j-i+1<k)j++;
            else{
                ans=min(ans,w);
                if(blocks[i]=='W')w--;
                else b--;
                i++;
                j++;
            }
        }
        return ans;
    }
};