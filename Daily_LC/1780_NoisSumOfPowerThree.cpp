// 1780_NoisSumOfPowerThree.cpp
class Solution {
public:
    bool fn(int n, set<int> &s){
        if(n==1 || n==0)return true;
        if(n==2)return false;
        int pwr=0;
        while(pow(3,pwr)<=n){
            pwr++;
        }
        pwr--;
        if(s.find(pwr)!=s.end())return false;
        s.insert(pwr);
        return fn(n-pow(3,pwr), s);
    }
    bool checkPowersOfThree(int n) {
        set<int> s;
        return fn(n,s);
    }
};