// 2657_prefixCommonArray.cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        vector<int> ans;
        
        unordered_map<int,int> mp1, mp2;
        for(int i=0;i<n;i++){
            int temp=0;
            mp1[A[i]]++;
            mp2[B[i]]++;

            for(auto it: mp1){
                if(mp2.find(it.first)!=mp2.end()){
                    temp++;
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};