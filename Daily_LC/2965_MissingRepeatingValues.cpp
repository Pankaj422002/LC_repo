class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> freq(n*n+1,0), ans(2,-1);
        for(auto it: grid)
            for(auto ele: it)freq[ele]++;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==2)ans[0]=i;
            else if(freq[i]==0)ans[1]=i;
        }
        return ans;
    }
};