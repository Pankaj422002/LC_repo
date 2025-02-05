// 1790_checkStringOneStringSwap.cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length()!=s2.length())return false;
        int cnt=0,n=s1.length(),i=0,j=0;
        while(i<n and j<n){
            if(s1[i]!=s2[j])cnt++;
            i++;j++;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1!=s2)return false;
        return cnt<=2;
    }
};