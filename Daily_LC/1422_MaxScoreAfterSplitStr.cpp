// 1422_MaxScoreAfterSplitStr.cpp
class Solution {
public:
    #define F first
    #define S second
    int maxScore(string s) {
        vector<pair<int,int>> p(s.length()+1, {0,0});
        for(int i=0;i<s.length();i++)
            p[i+1] ={(s[i]=='0'?p[i].F+1:p[i].F), (s[i]=='1'?p[i].S+1:p[i].S)};
        
        int ans=0,one=0;
        for(auto it: s)one+=(it=='1'?1:0);

        for(int i=1;i<s.length();i++) ans=max(ans, p[i].F+(one-p[i].S));
        
        return ans;
    }   
};