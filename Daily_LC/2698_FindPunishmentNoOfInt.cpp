// 2698_FindPunishmentNoOfInt.cpp
class Solution {
public:
    bool isPossible(int no, int req){
        if(no == 0){
            return req==0?true:false;
        }
        if(req<0)return false;

        int k=10;
        for(int i=1;i<=8;i++){
            bool istrue = isPossible(no/k , req-(no%k));
            if(istrue)return true;
            k=k*10;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int temp = i*i;
            if(isPossible(temp, i))
                ans += temp;
        }
        return ans;
    }
};