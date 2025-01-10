// 916_wordsubsets.cpp
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(auto word: words2){
            unordered_map<char,int> mp;
            for(auto ele: word){
                mp[ele]++;
                if(freq[ele-'a'] < mp[ele])freq[ele-'a']++;
            }
        }

        int min_len=0;
        for(auto it: freq)min_len += it;

        vector<string> res;
        for(auto it: words1){
            if(min_len <= it.length()){
                unordered_map<char,int> mp;
                for(auto ele: it)mp[ele]++;

                int flag=0;
                for(int i=0;i<26;i++){
                    if(freq[i]!=0 and mp[i+'a']<freq[i]){
                        flag=1;break;
                    }
                }
                if(flag==0)res.push_back(it);
            }
        }
        return res;
    }
};