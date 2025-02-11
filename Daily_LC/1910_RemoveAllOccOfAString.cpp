// 1910_RemoveAllOccOfAString.cpp
class Solution {
public:
    vector<int> LPS(string &s){
        int n=s.length();
        vector<int> lps(n,0);

        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len-1 < 0)
                    lps[i++]=0;
                else 
                    len=lps[len-1];
            }
        }
        return lps;
    }
    int getIdx(string &str, string &ptr, vector<int> &lps){
        int n=str.length(), m=ptr.length(), i=0, j=0;
        while(i<n and j<m){
            if(str[i]==ptr[j]){
                i++;j++;
            }else{
                if(j-1<0)
                    i++;
                else
                    j=lps[j-1];
            }
        }
        if(j==m)return i-j;
        return -1;
    }
    string removeOccurrences(string s, string part) {
        vector<int> lps = LPS(part);
        
        int idx = getIdx(s,part,lps), m=part.length();
        while(idx!=-1){
            s = s.substr(0,idx)+s.substr(idx+m);
            idx = getIdx(s,part,lps);
        }
        return s;
    }
};