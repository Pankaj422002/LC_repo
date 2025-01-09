class Solution {
public:
    bool isprefix(string &ptr, string &str){
        if(str.length()<ptr.length())return false;
        for(int i=0;i<ptr.length();i++)if(str[i]!=ptr[i])return false;
        return true;
    }
    bool issuffix(string &ptr, string &str){
        if(str.length()<ptr.length())return false;
        for(int i=str.length()-1,j=ptr.length()-1;j`>=0;i--,j--)if(str[i]!=ptr[j])return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(), ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isprefix(words[i], words[j]) and issuffix(words[i],words[j]))
                    ans++;
            }
        }
        return ans;
    }
};
