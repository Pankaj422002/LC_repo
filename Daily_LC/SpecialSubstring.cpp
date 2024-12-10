class Solution {
public:
    bool isallsame(string &temp){
        for(int i=1;i<temp.length();i++){
            if(temp[i]!=temp[i-1])return false;
        }
        return true;
    }
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                //check s[i,j] ==> is all same
                string str=s.substr(i, j-i+1);
                if(isallsame(str))mp[str]++;
            }
        }

        int ans=-1;
        for(auto it: mp){
            int sz=it.first.length();
            if(it.second>=3)ans=max(ans, sz);
        }
        return ans;
    }
};
