// 1400_constructKpalindromeString.cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> mp;
        for(auto it: s)mp[it]++;
        int o=0,e=0;
        for(auto it: mp){
            if(it.second%2==0) e++;
            else o++;
        }

        int mini=o, maxi=s.length();

        if(mini<=k and k<=maxi)return true;
        return false;

    }
};