// 2559_CountVowelStrRange.
class Solution {
public:
    bool isf(string &st){
        int x=st[0]-'a', y=st.back()-'a';
        if((x==0 || x==4 || x==8 || x==14|| x==20)&&(y==0 || y==4 || y==8 || y==14|| y==20))return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> ans,pre(n+1,0);
        for(int i=0;i<n;i++)pre[i+1]=(isf(words[i])?pre[i]+1:pre[i]);

        for(auto it: queries)ans.push_back(pre[it[1]+1]-pre[it[0]]);
        
        return ans;
    }
};